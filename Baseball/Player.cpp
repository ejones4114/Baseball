//
//  Player.cpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#include <stdio.h>
#include <string>
#pragma once

class Player {

protected:
   std::string name;
   int playerNum;
   
public:
   
   virtual ~Player() { }
   
   std::string getName() {
      return this->name;
   }
   
   int getPlayerNum() {
      return this->playerNum;
   }
   
   virtual void display() = 0;
   
};
