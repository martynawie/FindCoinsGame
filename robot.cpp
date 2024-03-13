//robot.cpp
#include "robot.h"
#include <iostream>
#include <cmath>
using namespace std;

robot::robot()
{

}
//copy constructor
robot::robot(robot &r1)
{
  this->location.set(r1.xlocation(),r1.ylocation());
}
robot::~robot()
{
  //cout<<"Calling the destructor"<<endl; 
}

void robot::init()
{  
  x = 0;
  y = 0;
  location.set(x,y);
  orientation = east;
}

point robot::getLocation() 
{
  return location;
}

void robot::print()  const
{
  cout << "I am at ";
  location.print();
  cout << " and I am  facing ";
  switch (orientation) 
  {
    case north:
        cout << "north";
        break;
    case south:
        cout << "south";
        break;
    case east:
        cout << "east";
        break;
    case west:
        cout << "west";
        break;
  }
  cout << "." << endl;
}

void robot::setOrientation(orientation_type orientation)
{
  this->orientation = orientation;
}

void robot::setplayer1orientation(char c)
{
  if (c == 'N')
    orientation = north;
  else if (c == 'S')
    orientation = south;
  else if (c == 'E')
    orientation = east;
  else
    orientation = west;
}

bool robot::forward()
{
  switch (orientation) 
  {
    case north:
      if (location.getY() == 0) 
      {
        return false;
      }
      y--;
      location.set(x,y);
        return true;
    case south:
      if (location.getY() == 9) 
      {
        return false;
      }
      y++;
      location.set(x,y);
        return true;
    case east:
      if (location.getX() == 9) 
      {
        return false;
      }
      x++;
      location.set(x,y);
      return true;
    case west:
      if (location.getX() == 0) 
      {
        return false;
      }
      x--;
      location.set(x,y);
      return true;
    moves++;
  }
    return false; 
}

bool robot::reverse()
{
  switch (orientation) 
  {
    case north:
      if (location.getY() == 0) 
      {
        return false;
      }
      y++;
      location.set(x,y);
        return true;
    case south:
      if (location.getY() == 9) 
      {
        return false;
      }
      y--;
      location.set(x,y);
        return true;
    case east:
      if (location.getX() == 9) 
      {
        return false;
      }
      x--;
      location.set(x,y);
      return true;
    case west:
      if (location.getX() == 0) 
      {
        return false;
      }
      x++;
      location.set(x,y);
      return true;
    moves++;
  }
    return false; 
}

void robot::turnCW()
{
  switch (orientation) 
  {
    case north:
        orientation = east;
        break;
    case south:
        orientation = west;
        break;
    case east:
        orientation = south;
        break;
    case west:
        orientation = north;
        break;
  }
}

void robot::turnAntiCW()
{
  switch (orientation) 
  {
    case north:
        orientation = west;
        break;
    case south:
        orientation = east;
        break;
    case east:
        orientation = north;
        break;
    case west:
        orientation = south;
        break;
  }
}

bool robot::eastEnd()
{
  if(location.getX() == 9)
    return true;
  else
    return false;
}

bool robot::westEnd()
{
  if(location.getX() == 0)
    return true;
  else
    return false;
}

bool robot::northEnd()
{
  if(location.getY() == 0)
    return true;
  else
    return false;
}

bool robot::southEnd()
{
  if(location.getY() == 9)
    return true;
  else
    return false;
}

bool robot::zig()
{
  if (orientation == east && eastEnd()) 
  {
    turnCW();
    forward(); 
    turnCW();
    moves++;
    return true;
  }
  return false;
}

bool robot::zag()
{
  if (orientation == west && westEnd()) 
  {
    turnAntiCW();
    forward(); 
    turnAntiCW();
    moves++;
    return true;
  }
  return false;
}

int robot::xlocation()
{
  return location.getX();
}

int robot::ylocation()
{
  return location.getY();
}

//assignment 4 - Overloading operators
bool robot::operator++()
{
  return forward();
}

bool robot::operator--()
{
  return reverse();
}

float robot::operator-(robot r1)
{
  float distance;
  float xCoordinate = pow(xlocation() - r1.xlocation(),2);
  float yCoordinate = pow(ylocation() - r1.ylocation(),2);

  distance=sqrt(xCoordinate+yCoordinate);
  return distance;
}

bool robot::operator==(robot r1)
{
  return(xlocation() == r1.xlocation() && ylocation() == r1.ylocation());
}

robot robot::operator=(robot r1)
{
  robot copyConstructor;
  copyConstructor.location.set(r1.xlocation(),r1.ylocation());
  return copyConstructor;
}