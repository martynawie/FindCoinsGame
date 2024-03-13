//point.cpp:
#include "point.h"
#include <iostream>
using namespace std;

void point::print() const
{
  cout << "(" << x << ", " << y << ")";
}

void point::set( int x, int y )
{
  this->x = x;
  this->y = y;
}

int point::getX()
{
  return x; 
}

int point::getY()
{
  return y;
}
