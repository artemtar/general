#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
void simpleSort(T& container){
    for(typename T::iterator iterA = container.begin(); iterA != container.end(); ++iterA){
        for(typename T::iterator iterB = iterA; iterB != container.end(); ++iterB){
            if(*iterA > *iterB){
                typename T::value_type temp{*iterA};
                *iterA = *iterB;
                *iterB = temp;
            }
        }
    }
}

int main(){
    vector<int> a = {10, 4, 66, 2, 444};
    simpleSort(a);
    for_each(a.begin(),a.end(), [](int i) {cout << i << endl;});
}

