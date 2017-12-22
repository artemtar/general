#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
template<typename iter>
void print(iter b, iter e){
    while(b != e){
        cout << b->first << " " << b->second << endl;
        ++b;
    }
}
int main(){
    pair<int, string> p1;
    pair<int, string> p2;
    p1 = make_pair(12, "sinel");
    p2 = make_pair(12, "sinem");
    bool i;
    i = p1 < p2;
    
    map<int,string> mp;
    mp.insert(p1);
    mp.insert(p2);
    cout << mp.count(12) << endl;
    cout << mp.size() << endl;
    auto p = mp.find(12);
    //second pair is duplicate and have been removed
    //cout << p->first << " " << p->second << endl;
    mp.erase(12);
    mp = {{100, "a"}, {1, "b"}, {4,"c"}};
    auto iter = mp.begin();
    //will print 1 b
    cout << iter->first << " " << iter->second << endl;
    cout<<"map2"<<endl;
    map<int, string> map2;
    map2.insert(mp.begin(),mp.end());
    map2[1] = "new value";
    map2[999] = "here is 999";
    map<int,string>::iterator l = mp.end();
    map2.insert(map2.end(), p1);
    //deleting last element
    //map2.erase(--(map2.end()));
    print(map2.cbegin(), map2.cend());
        
}