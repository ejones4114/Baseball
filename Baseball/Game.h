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
#include <vector>



class Game {
   
private:
   
   enum INNING {TOP, BOTTOM};
   
   enum BASECONDITIONS {EMPTY, FIRST, FIRST_SECOND, FIRST_THIRD, SECOND, THIRD, SECOND_THIRD, LOADED };
   
   BASECONDITIONS onBase;
   Team *homeTeam;
   Team *visitingTeam;
   std::vector<GameAction*> playByPlay;
   std::vector<std::vector<int>> boxScore;

   int homeHitter;
   int visitingHitter;
   int homeScore;
   int visitingScore;
   int inning;
   int baseRunnersOn;
   
   
   std::string getTeamAbbr(std::string name);
   
   void playBall();
   void playInning(INNING half);
   int getHitterNum(int hitter);
   void advanceRunners(BASES base, INNING half);
   void clearBases();
   
   
public:
   Game(std::string homeTeam, std::string visitingTeam);
   
   
   
};



#endif /* Game_h */
