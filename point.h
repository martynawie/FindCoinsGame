//point.h
#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>
using namespace std;


class point
{
  private:
    int x,y;
  public:
    void  print()  const;
    void  set(int, int);
    int getX();
    int getY();
};

#endif