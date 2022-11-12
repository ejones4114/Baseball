//
//  Game.hpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "Team.h"
#include "GameAction.h"


class Game {
   
private:
   Team *homeTeam;
   Team *visitingTeam;
   GameAction *gameAction;
//   std::vector<GameAction*> gameDetails;
   int homeScore;
   int visitingScore;
   int inning;
   
   void populateTeam(std::string name);
   
   std::string getTeamAbbr(std::string name);
   
   
   
public:
   Game(std::string homeTeam, std::string visitingTeam);
   
   
};



#endif /* Game_h */
