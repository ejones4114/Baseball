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
#include "Hitters.h"
#include <iostream>

class Team {
   
private:
   std::string name;
   std::string nameAbbr;
   int score;
   int batterUp;
   int hits;
   
   Player *hitters[9];
   Player *pitcher;
 
   void populateTeam();
   void buildLineUp(std::string hitters);
   std::string playerName(std::istringstream &is, int lineUpNum);
   void playerStats(std::istringstream &is, int *stats);
   
   
   
   
   
public:
   
   Player* getHitter(int lineUpNum);
   Team(std::string name);
   ~Team();
   
   std::string getAbbr(std::string name);
   std::string getTeamName();
   
   void setBatterUp(int batterUp);
   int getBatterUp();
   int getScore();
   void setScore(int score);
   void setHits();
   int getHits();
   
   
   
   
};




#endif /* Team_hpp */
