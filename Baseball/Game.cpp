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
   this->baseRunnersOn = 0;
   
   
   this->homeHitter = -1;
   this->visitingHitter = -1;
   
   
   
   playBall();
   
   
}

void Game::playBall() {
   
   do {
      INNING top = TOP;
      INNING bottom = BOTTOM;
      playInning(top);
      playInning(bottom);
      
   } while(this->inning < 9 && (this->homeScore != this->visitingScore));
}

void Game::playInning(INNING half) {
   
   int out = 0;
   Hitter *h = nullptr;
   int batterNum = this->homeHitter;
   
   if(half == TOP) {
      batterNum = this->visitingHitter;
   }
   while (out < 3) {
      batterNum++;
      if(batterNum > 8) batterNum = 0;
      
      h = static_cast<Hitter*>(visitingTeam->getHitter(batterNum));
      GameAction *gAction = nullptr;
      
      if(gAction->onBaseOrNot(h)) {
         gAction = gAction->typeOfOnBase(h);// get on base
         advanceRunners(gAction->baseReached(), half);
         playByPlay.push_back(gAction);
      }
      
      else {
         gAction = gAction->typeOfOut(h);
         playByPlay.push_back(gAction);
         out++;
      }
   }
   return;
}

int Game::getHitterNum(int hitter) {
   return (hitter >= 9) ? 0 : hitter;
}


void Game::advanceRunners(BASES hit, INNING half) {
   int score = 0;
   if(hit == WALK || hit == HBP) hit = SINGLE;
   //base clearing advances
   if(hit == HR) {
      score += baseRunnersOn + 1;
      clearBases();
   } else if(hit == TRIPLE ) {
      score += baseRunnersOn;
      clearBases();
      baseRunnersOn = 1;
      this->onBase = THIRD;
   }
   
   // 2 base advances
   else if (hit == DOUBLE && (this->onBase >= SECOND && this->onBase < LOADED)) {
      score +=baseRunnersOn;
      baseRunnersOn = 1;
      this->onBase = SECOND;
      
   } else if (hit == DOUBLE && (this->onBase == FIRST_THIRD || this->onBase == FIRST_SECOND || this->onBase == LOADED)) {
      if(this->onBase == LOADED) score++;
      
      score++;
      baseRunnersOn = 2;
      this->onBase = SECOND_THIRD;
      
      // single base advances
   } else {
      if(onBase == EMPTY) {
         onBase = FIRST;
         baseRunnersOn = 1;
      } else if(onBase == FIRST_SECOND) {
         onBase = LOADED;
         baseRunnersOn = 3;
      } else if(onBase == FIRST) {
         onBase = FIRST_SECOND;
         baseRunnersOn = 2;
      } else if(onBase == FIRST_THIRD) {
         score++;
         onBase = FIRST_SECOND;
      } else if(onBase == SECOND) {
         onBase = SECOND_THIRD;
         baseRunnersOn = 2;
      } else if(onBase == THIRD) {
         score++;
         onBase = FIRST;
      } else if(onBase == SECOND_THIRD) {
         score++;
         onBase = FIRST_THIRD;
      } else {
         score++;
      }
   }
}
void Game::clearBases() {
   this->onBase = EMPTY;
   this-> baseRunnersOn = 0;
}




