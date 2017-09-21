#include <vector>
//using namespace std;
#ifndef RECTANGLE
#define RECTANGLE

class Rectangle
{
  int d_x_start;
  int d_x_end;
  int d_y_start;
  int d_y_end;

public:
  Rectangle(int llc = -1, int w = 1, int h = 1);
  void print();
  bool intersect(Rectangle other);
  Rectangle intersection(Rectangle other);
  void setVal(int xs, int ys, int xe, int ye);
  std::vector<Rectangle> split ();
};

#endif // RECTANGLE