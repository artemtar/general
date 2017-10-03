#include <iostream>
#include "screen.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
  char (*screen)[5];
  clearScreen( screen ); 
 // int hLines, vLines;
 // cout << "No. of Horizontal and Vertical Lines: "; cin >> hLines; cout << endl;
 /* gridScreen( screen, hLines );
  printScreen( screen );
  // No clear screen
  cout << "Drawing new grid over old grid:" << endl; 
  cout << "No. of Horizontal Lines: "; cin >> hLines; 
  cout << "No. of Vertical Lines: "; cin >> vLines; cout << endl;
  gridScreen( screen, hLines, vLines );
  printScreen( screen );
  clearScreen( screen );*/
  return 0;
}
    
  


