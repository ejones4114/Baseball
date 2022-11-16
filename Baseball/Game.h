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
#include "Actions.h"
#include <vector>
#include <iomanip>
#include <iostream>



class Game {
   
   enum INNING {TOP, BOTTOM, END};

private:
      
   enum BASECONDITIONS {EMPTY, FIRST, FIRST_SECOND, FIRST_THIRD, SECOND, THIRD,
                        SECOND_THIRD, LOADED };
   
   BASECONDITIONS onBase;
   INNING half;
   Team *homeTeam;
   Team *visitingTeam;
   std::vector<GameAction*> playByPlay;
   int lineScore[2][20];

   int homeScore;
   int visitingScore;
   int inning;
   int baseRunnersOn;
   
   
   std::string getTeamAbbr(std::string name);
   
   void playBall();
   INNING playInning(Team *team, INNING half);
   int getHitterNum(int hitter);
   void advanceRunners(BASES base, Team *team);
   void singleBaseAdvances(BASES base, Team *team);
   void doubleBaseAdvances(BASES base, Team *team);
   void tripleBaseAdvances(BASES base, Team *team);
   void baseClearingAdvances(BASES base, Team *team);
   void clearBases();
   int playExtraInning(INNING bottom);
   void endTheInning(Team *team, int currScore, INNING half, int batterUp);
   int upDateInning(Team *team, GameAction *gAction, int batterUp);
   INNING playFinalInning(Team *team, INNING half);
   void displayLineScore(Team *team, int num);
   
public:
   Game(std::string homeTeam, std::string visitingTeam);
  
   
   void displayLineScore();
   void displayFullGameResults();
   void displayPlayByPlay();
   
   
   
   
};



#endif /* Game_h */
