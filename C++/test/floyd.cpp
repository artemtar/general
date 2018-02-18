#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;



int distance(string g1, string g2){
    int c = 0;
    int s = g1.size();
    for(int i = 0; i < s; ++i)
        if (g1[i] == g2[i]) c++;
    return s - c;
}

int findMutationDistance(string start, string end, vector < string > bank) {



int s_position = 0;
for(int i = 0; i < bank.size(); ++i){
    if (bank.at(i) == start){
        s_position = i;
    }
}
if(!s_position) bank.insert(bank.begin(),start);

int genetic_pool = bank.size();

int* distances_form_start = new int[genetic_pool];
for(int i = 0; i < genetic_pool; ++i){
    distances_form_start[i] = -1;
}



vector<pair<string, int> > canditate_for_mutation;
auto p = make_pair(start, s_position);
canditate_for_mutation.push_back(p);

int (*genetic_distance)(string, string) = &distance;
while(canditate_for_mutation.size() != 0){
    auto next = *canditate_for_mutation.begin();
    canditate_for_mutation.erase(canditate_for_mutation.begin());
    for(int j = 0; j < genetic_pool; ++j){  
        if(genetic_distance(bank.at(j), next.first) == 1
            && distances_form_start[j] == -1){
            int dist = distances_form_start[next.second] + 1;
            distances_form_start[j] = dist;
            string check = bank.at(j);
            if (check == end) return dist + 1;
        canditate_for_mutation.emplace_back(check, j);
        }
    }
    sort(canditate_for_mutation.begin(), canditate_for_mutation.end(), [end](auto p1, auto p2){
                int c1 = 0;
                int c2 = 0;
                int s = end.size();
                for(int i = 0; i < s; ++i){
                if (p1.first[i] == end[i]) c1++;
                if (p1.first[i] == end[i]) c2++;
                }
                return c1 < c2;
        });
}
return -1;
}

int main(){
string s = "AAAAAAAA";
string e = "GGAAAAAA";
// b = ['AAAAAAAA', 'AAAAAAAT', 'AAAAAATT', 'AAAAATTT']
vector<string> b = {"GAAAAAAA", "AAGAAAAA", "AAAAGAAA", "GGAAAAAA"};

int i = findMutationDistance(s, e, b);
cout << i << "end" << endl;
}