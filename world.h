//world.h
#ifndef WORLD_H
#define WORLD_H
#include <string>
#include <iostream>
#include <fstream>
#include "point.h"
#include "robot.h"

using namespace std;

class world
{
  private:
    point *coins = new point[3];
    ofstream log_file;
  public:
    world();
    void  print()  const;
    void  set(int , int , int );
    bool searchWorld(int , int );
    int coinsXLocation(int i);
    int coinsYLocation(int i);
    void deletememory();
    ~world();
};
#endif