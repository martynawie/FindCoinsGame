//robot.h
#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <iostream>
#include "point.h"
#include "world.h"
using namespace std;

class robot
{
  private:
    point location;
    enum orientation_type {north, south, east, west};
    orientation_type orientation;
    int moves;
    int x;
    int y;

  public:
    robot();
    robot(robot &);
    ~robot();
    void init();
    void print()  const;
    void setOrientation(orientation_type);
    void setplayer1orientation(char);
    bool forward();
    bool reverse();
    void turnCW();
    void turnAntiCW();
    bool eastEnd();
    bool westEnd();
    bool northEnd();
    bool southEnd();
    bool zag();
    bool zig();
    point getLocation();
    int xlocation();
    int ylocation();
    bool operator++();
    bool operator--();
    float operator-(robot);
    bool operator==(robot);
    robot operator=(robot);
};

#endif