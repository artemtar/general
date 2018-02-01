
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
int ar[1][2];
int krakenCount(int m, int n) {
    if (m == 1 || n == 1) return 1;
    return krakenCount(m-1,n-1)
            + krakenCount(m-1,n)
            + krakenCount(m,n-1);
}


int main(){
   int i = krakenCount(3,3);
   cout << i << endl;
}