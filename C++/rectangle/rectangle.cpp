#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(int llc, int w, int h) : d_x_start(llc),
                                              d_y_start(llc),
                                              d_x_end(llc + w),
                                              d_y_end(llc + h)
{
}
void Rectangle::print()
{
    cout << "Rectangle: (" << d_x_start << "," << d_y_start << ")"
         << "(" << d_x_end << "," << d_y_end << ") ";
}
//checking if rectangles is outside of each other
bool Rectangle::intersect(Rectangle other)
{
    return !(d_x_start > other.d_x_end || d_y_end < other.d_y_start ||
             d_x_end < other.d_x_start || d_y_start > other.d_y_end);
}
Rectangle Rectangle::intersection(Rectangle other)
{
    cout << "Intersection of ";
    print();
    cout << " and ";
    other.print();
    cout << "?" << endl;
    if (intersect(other) == false)
    {
        cout << "No intersection" << endl;
        return Rectangle();
    }
    else
    {
        Rectangle newRec;
        newRec.d_x_start = max(d_x_start, other.d_x_start);
        newRec.d_y_start = max(d_y_start, other.d_y_start);
        newRec.d_x_end = min(d_x_end, other.d_x_end);
        newRec.d_y_end = min(d_y_end, other.d_y_end);
        newRec.print();
        cout << endl;
        return newRec;
    }
}
void Rectangle::setVal(int xs, int ys, int xe, int ye)
{
    d_x_start = xs;
    d_y_start = ys;
    d_x_end = xe;
    d_y_end = ye;
}
vector<Rectangle> Rectangle::split()
{
    cout << "Slit of ";
    print();
    cout << "is:" << endl;
    
    int mid_x = (d_x_end - d_x_start)/2;
    int mid_y = (d_y_end - d_y_start)/2;
    Rectangle ll, lr, rl, rr;
    ll.setVal(d_x_start, d_y_start, d_x_start + mid_x, d_y_start + mid_y);    
    lr.setVal(mid_x, d_y_start, d_x_end, mid_y);
    rl.setVal(d_x_start, mid_y, mid_x, d_y_end);
    rr.setVal(mid_x, mid_y, d_x_end, d_y_end);
    vector<Rectangle> v;
    v.push_back(ll);
    v.push_back(lr);
    v.push_back(rl);
    v.push_back(rr);
    return v;
}