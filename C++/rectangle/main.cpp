#include "rectangle.h"
#include <iostream>
#include <vector>
#include "rectangle.h"
#include <array>

//using namespace std;

int main() {
    std::vector<Rectangle> rVec;
    rVec.emplace_back(Rectangle(3,4,10,2));
    rVec.emplace_back(Rectangle(8,8,3,4));
    rVec.emplace_back(Rectangle(4,1,10,2));
    rVec.emplace_back(Rectangle(14,2,3,5));
    rVec.emplace_back(Rectangle(1,2,15,9));
    // Test intersect
    for (int oI=1; oI<rVec.size(); ++oI ) {
      std::cout << "Intersection of ";
      rVec[0].print();
      std::cout << " and ";
      rVec[oI].print();
      std::cout << "?" << std::endl;
      if ( rVec[0].intersect(rVec[oI])) {
      Rectangle r = rVec[0].intersection(rVec[oI]);
      r.print();
      std::cout << std::endl;
        } else {
      std::cout << "No intersection" << std::endl;
        }
    }
    std::cout << std::endl << "Testing split of ";
    rVec[0].print();
    std::cout << std::endl;
    // Test split
    std::vector<Rectangle> children = rVec[0].split();
    for (auto child:children) {
      child.print();
        std::cout << std::endl;
    }
    return 0;
  }