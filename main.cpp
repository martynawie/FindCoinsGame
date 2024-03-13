/*
Martyna Wieczorek
The game for the robot and user to find all 3 coins.
*/

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>  
#include <vector>

//for the random number
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 

#include "point.h"
#include "robot.h"
#include "world.h"

using namespace std;

void instruction();

int main() 
{
  ofstream log_file;
  ifstream read;
  ofstream write;
  string myText;
  int x, y;
  vector<string> lines;
  
  read.open("highScore.txt");
  
  //checking if the file "highScore.txt" will open
  if (!read) 
  {
    cerr << "error opening high score file :-(" << endl;
  }
  
  cout<< "Last five scores in the record are as following:"<< endl;

  //reading the last five scores from the file
  while (getline (read, myText)) 
  {
    cout<< myText<<endl;
  }
  read.close();
  cout << "\n" <<endl;

  log_file.open("game_log.txt", ios::app);

  //checking if the file "game_log.txt" will open
  if (!log_file) 
  {
    cerr << "error opening game_log file :-(" << endl;
  }

  //creating objects
  world World;
  robot Myrobot;
  robot User;
  
  int move_count = 0;
  int userCoins = 0;
  int robotCoins = 0;
  int coin_count = 0;
  char c;

  srand(time(NULL));

  //printing the instruction
  instruction();
  
  //setting coin's coordinate to random numbers
  World.set(0, x, y);
  World.set(1, x, y);
  World.set(2, x, y);

  //location of three coins. Commented for the game.
  //World.print(); 
  cout << endl;

  int c_x1 = World.coinsXLocation(0);
  int c_y1 = World.coinsYLocation(0);

  int c_x2 = World.coinsXLocation(1);
  int c_y2 = World.coinsYLocation(1);

  int c_x3 = World.coinsXLocation(2);
  int c_y3 = World.coinsYLocation(2);

  //setting user's and robot's coordinates to (0,0)
  User.init();
  Myrobot.init();

  //testing operator "==" overloading
  if(User == Myrobot)
  {
    cout<<"\nUser and Robot are starting at the same coordinates:\n" <<endl;
  }
  else{
    cout<<"User and Robot are not at the same coordinates"<<endl;
  }

  //printing coordinates
  cout << "User: ";
  User.print();
  cout << "Computer: ";
  Myrobot.print();

  //The loop will repeat until all three coins are found
  while (coin_count != 3) 
  {
    cout << "\nChoose one of the following to move one step:" << endl
         << "N: for North" << endl
         << "S: for South" << endl
         << "E: for East" << endl
         << "W: for West" << endl;
    log_file << "\nChoose one of the following to move one step:" << endl
             << "N: for North" << endl
             << "S: for South" << endl
             << "E: for East" << endl
             << "W: for West" << endl;
    cin >> c;
    log_file << "\nUser input: " << c << endl;

    //user movements
    User.setplayer1orientation(c);
    User.forward();
    cout << "\nUser: ";
    User.print();
    
    if (User.xlocation() == c_x1 && User.ylocation() == c_y1) 
    {
      cout << "User found a coin #1." << endl;
      log_file << "User found a coin #1." << endl;
      c_x1 = -1;
      c_y1 = -1;
      userCoins++;
      coin_count++;
    } 
    else if (User.xlocation() == c_x2 && User.ylocation() == c_y2) 
    {
      cout << "User found a coin #2." << endl;
      log_file << "User found a coin #2." << endl;
      c_x2 = -1;
      c_y2 = -1;
      userCoins++;
      coin_count++;
    } 
    else if (User.xlocation() == c_x3 && User.ylocation() == c_y3) 
    {
      cout << "User found a coin #3." << endl;
      log_file << "User found a coin #3." << endl;
      c_x3 = -1;
      c_y3 = -1;
      userCoins++;
      coin_count++;
    }

    //computer movements
    Myrobot.zig();
    Myrobot.zag();
    Myrobot.forward();
    cout << "Computer: ";
    Myrobot.print();

    if (Myrobot.xlocation() == c_x1 && Myrobot.ylocation() == c_y1) 
    {
      cout << "Robot found a coin #1." << endl;
      log_file << "Robot found a coin #1." << endl;
      c_x1 = -1;
      c_y1 = -1;
      robotCoins++;
      coin_count++;
    }
    if (Myrobot.xlocation() == c_x2 && Myrobot.ylocation() == c_y2) 
    {
      cout << "Robot found a coin #2." << endl;
      log_file << "Robot found a coin #2." << endl;
      c_x2 = -1;
      c_y2 = -1;
      robotCoins++;
      coin_count++;
    }
    if (Myrobot.xlocation() == c_x3 && Myrobot.ylocation() == c_y3) 
    {
      cout << "Robot found a coin #3." << endl;
      log_file << "Robot found a coin #3." << endl;
      c_x3 = -1;
      c_y3 = -1;
      robotCoins++;
      coin_count++;
    }
    move_count++;

    //testing operator "-" overloading - distance between user and robot
    cout<<"Distance between User and Robot is: " << User - Myrobot << endl;
  }

  //determining the winner
  if (robotCoins > userCoins) 
  {
    cout << "\nThe robot won he has " << robotCoins << " coins and the user has "
         << userCoins << " coins." << endl;
    log_file << "The robot won he has " << robotCoins
             << " coins and the user has " << userCoins << " coins." << endl;
  } 
  else
  {
    cout << "\nThe user won he has " << userCoins << " coins and the robot has "
         << robotCoins << " coins." << endl;
    log_file << "The user won he has " << userCoins
             << " coins and the robot has " << robotCoins << " coins." << endl;
  } 

    //testing operator "=" creating coppy of Myrobot
  robot copyRobot(Myrobot);
  copyRobot = Myrobot;

  cout << endl;
  cout <<"Robots coordinates are: (" << copyRobot.xlocation()<< ","<< copyRobot.ylocation()<< ")"<<endl;

  //testing operators "++" and "--" 
  ++Myrobot;
  cout<<"After ++ operator (" << Myrobot.xlocation() <<","<< Myrobot.ylocation()<<")"<<endl;

  --Myrobot;
  cout<<"After -- operator (" << Myrobot.xlocation()<< ","<< Myrobot.ylocation()<<")"<<endl;
  copyRobot.getLocation();
  
  //last five scores
  string N = "";
  read.open("highScore.txt");
  
  while (getline(read, myText))
  {
      lines.push_back(myText);
  }
  read.close();

  write.open("highScore.txt");

  if(lines.size()<10)
  {
    for(int i = 0; i < lines.size(); i ++)
    {
        write<< lines[i]<<endl;
    }
    write << "User          Computer"<< endl;
    write<< userCoins<<"              "<< robotCoins<<endl;
  }
  else
  {
    lines.erase(lines.begin());
    lines.erase(lines.begin());
    for(int i = 0; i < lines.size(); i ++)
    {
      write<< lines[i]<<endl;    
    }
    write << "User          Computer"<< endl;
    write<< userCoins<<"              "<< robotCoins<<endl;
  }


  //closing all the files
  log_file.close();
  write.close();
  read.close();
  
  World.deletememory();
  
  return 0;
}

//function with instruction
void instruction()
{
  cout << "Let's 's start the game!!" << endl << "Above you can see the last five scores, now it's your turn to play!" << endl << "The game is played in a 10x10 world.\nThe goal of the game is to find three coins before the robot does!\nThe game will start automatically.\nYou can move in 4 directions:\nNorth - N,\nSouth - S,\nWest - W,\nEast - E.\nYou will take turns with the robot.\nThe robot moves in zig-zag.\nThe first player to collect all three coins will be declared the winner.\nThe game will automatically end once a player collects all three coins.\nGood luck and have fun!!!\n";
}