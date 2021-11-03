// Định nghĩa lớp
#include "Point.h"


Point::Point(int xVal, int yVal)
    : xVal(xVal), yVal(yVal)
{
}
Point::Point(const Point& p) : xVal(p.xVal), yVal(p.yVal)
{
   
}
Point::Point(int x) : xVal(x), yVal(x)
{ }
Point::~Point()
{
    cout << "Huy Point" << endl;
}
void Point::Show()
{   
    //this->z = 5;
    cout << "(" << this->xVal << ", " << this->yVal << ")" << endl;
}
// Point operator+(const Point& p1, const Point& p2)
// {
//     Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
//     return p;
// }
// Point operator+(const Point& p1, const int& p2)
// {
//     Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
//     return p;
// }
// Point operator+(const int& p1, const Point& p2)
// {
//     Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
//     return p;
// }
// Point operator-(const Point& q)
// {
//     Point p(this->xVal - q.xVal, this->yVal - q.yVal);
//     return p;
// }
// ostream& operator<<(const Point& p, ostream& o)
// {
//     o << p.xVal << ", " << p.yVal << endl;
// }
// ostream& operator<<(ostream& o, const Point& p)
// {
//     o << p.xVal << ", " << p.yVal << endl;
// }
// istream& operator>>(istream& in, Point& p)
// {
//     cout << "xVal = ";
//     in >> p.xVal;
//     cout << "yVal = ";
//     in >> p.yVal;
//     return in;
// }
// Point& Point::operator++()
// {
//     this->xVal++;
//     this->yVal++;
//     return *this;
// }
// const Point Point::operator++(int)
// {
//     Point bef = *this;
//     this->xVal++;
//     this->yVal++;
//     return bef;
// }
