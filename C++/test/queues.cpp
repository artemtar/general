#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
template<typename iterator>
void print(iterator begin, iterator end){
    while(begin != end){
        cout << *begin << endl;
        ++begin;
    }
}
int main(){
    vector<int> v (10, 1);
    print(v.begin(), v.end());
    priority_queue <int> pq(v.begin(), v.end());
    stack<int, vector<int>> st(v);
    pq.push(2);
    vector<int>bb(v.begin(),v.end());
    
}
