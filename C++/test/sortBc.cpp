#include <algorithm>
#include <vector>
#include <iostream> 
#include <string>

using std::sort;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ostream;


struct BuildingCode {
  string d_code;
  string d_name;
  int d_num;

  friend ostream& operator<<( ostream& os, const BuildingCode& bc ) {
    os << bc.d_code << ": " << bc.d_name << " " << bc.d_num;
    return os;
  }
};

bool comp(BuildingCode& s1, BuildingCode& s2){
    return s1.d_code < s2.d_code;
}

int main() {
  vector<BuildingCode> bcVec{{"STE","SITE",800},
                             {"MNT","Montpetit",125},
	                     {"MRN","Marion",140},
	                     {"VNR","Vanier",11},
	                     {"LMX","Lamoureux",145},
	                     {"MCD","MacDonald",150}};

    sort(bcVec.begin(), bcVec.end(), [](const BuildingCode b1, const BuildingCode b2){return b1.d_num < b2.d_num;});
    for (auto a : bcVec){
        cout << a << endl;
    }
    auto itstart = bcVec.rend();
    auto itend = bcVec.rbegin();

    sort(itend, itstart, comp);
        for (auto a : bcVec){
        cout << a << endl;
    }
}