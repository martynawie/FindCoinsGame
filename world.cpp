//world.cpp:
#include "world.h"
#include <iostream>
#include <fstream>
using namespace std;

world::world(){}

void  world::print()  const
{
  for(int i=0; i<3; i++)
    {
      cout << "Coin " << i+1 << " location: ";
      coins[i].print();
      cout << endl;
    }
}

void  world::set( int i, int x, int y )
{
    for(int i=0; i<3; i++)
  {
    x = rand() % 10;
    y = rand() % 10;
    coins[i].set(x,y);
  }
}    

bool world::searchWorld(int x, int y)
{
  for(int i=0; i<3; i++)
  {
    if(coins[i].getX()==x && coins[i].getY()==y)
    {
      cout << "I am at (" << coins[i].getX() << ", " << coins[i].getY() << ") and I found #" << i+1 << " coin. I’m gonna be rich!  Yippee!" << endl;
      return true;
    }
  }
  return false;
}

int world::coinsXLocation(int i)
{
  return coins[i].getX();
}

int world::coinsYLocation(int i)
{
  return coins[i].getY();
}

void world:: deletememory()
{
  delete [] coins;
}


world::~world()
{
  deletememory();
}