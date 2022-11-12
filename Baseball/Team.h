//
//  Team.hpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#ifndef Team_h
#define Team_h

#include <stdio.h>
#include <string>
#include "Player.cpp"
#include <iostream>

class Team {
   
private:
   std::string name;
   std::string nameAbbr;
   Player *hitters[9];
   Player *pitcher;
 
   void populateTeam();
   void buildLineUp(std::string hitters);
   std::string playerName(std::istringstream &is, int lineUpNum);
   void playerStats(std::istringstream &is, int *stats);
   
   
   
   
   
public:
   
   Team(std::string name);
   
   std::string getAbbr(std::string name);
   
   
   
   
   
   
};




#endif /* Team_hpp */
