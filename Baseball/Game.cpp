//
//  Game.cpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#include "Game.h"



Game::Game(std::string homeTeam, std::string visitingTeam) {
   this->homeTeam = new Team(homeTeam);
   this->visitingTeam = new Team(visitingTeam);
   
   this->homeScore = 0;
   this->visitingScore = 0;
   this->inning = 1;
   
   
}



