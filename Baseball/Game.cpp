//
//  Game.cpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#include "Game.h"

#include <iostream>
#include <cstdio>



Game::Game(std::string homeTeam, std::string visitingTeam) {
   this->homeTeam = new Team(homeTeam);
   this->visitingTeam = new Team(visitingTeam);
   this->half = TOP;
   this->homeScore = 0;
   this->visitingScore = 0;
   this->inning = 1;
   this->baseRunnersOn = 0;
   this->onBase = EMPTY;
   
   for(int i = 0; i < 20; i++) {    //line score is offset by one
      lineScore[0][i] = 0;
      lineScore[1][i] = 0;
   }
   
   
   playBall();
   
   
}

void Game::playBall() {
   
   while(this->inning < 9) {
      playInning(this->visitingTeam, TOP);
      playInning(this->homeTeam, BOTTOM);
   }
   INNING half = TOP;
   
   while(half != END) {
      
      playInning(this->visitingTeam, half);
      
      if(this->homeTeam->getScore() <= this->visitingTeam->getScore()) {
         playInning(this->homeTeam, BOTTOM);
         if(this->homeTeam->getScore() < this->visitingTeam->getScore()) { //game over
            inning--;
            break;
         }
         
         inning++;
      }
      
      else {
         half = END;
      }
   }
}

int Game::playExtraInning(INNING half) {
   return 3;
}

Game::INNING Game::playInning(Team * team, INNING half) {
   this->half = half;
   int out = 0;
   Hitter *h = nullptr;
   int batterUp = team->getBatterUp();
   int currScore = team->getScore();
   
   while (out < 3) {
      
      //End of game conditions
      if(inning >= 9 && half == BOTTOM && this->homeTeam->getScore() > this->visitingTeam->getScore()) {
         lineScore[1][inning] = team->getScore() - currScore;
         inning++;
         return END;
      }
      
      //otherwise play the inning
      h = static_cast<Hitter*>(team->getHitter(batterUp));
      GameAction *gAction = nullptr;
      
      if(gAction->onBaseOrNot(h)) {
         gAction = gAction->typeOfOnBase(h);             // get on base
         advanceRunners(gAction->baseReached(), team);
      }
      
      else {
         gAction = gAction->typeOfOut(h);
         out++;
      }
      batterUp = upDateInning(team, gAction, batterUp);
   }
   
   endTheInning(team, currScore, half, batterUp);
   return (half == TOP) ? BOTTOM : TOP;
}

int Game::upDateInning(Team *team, GameAction *gAction, int batterUp) {
   gAction->setPlayerName(team->getHitter(batterUp)->getName());
   playByPlay.push_back(gAction);
   batterUp++;
   return (batterUp < 9) ? batterUp : 0;
}

void Game::endTheInning(Team *team, int currScore, INNING half, int batterUp) {
   currScore = team->getScore() - currScore;
   team->setBatterUp(batterUp);
   
   if(half == TOP)
      lineScore[0][inning] = currScore;
   else {
      lineScore[1][inning] = currScore;
      inning++;
   }
   
   
   clearBases();
}

int Game::getHitterNum(int hitter) {
   return (hitter >= 9) ? 0 : hitter;
}


void Game::baseClearingAdvances(BASES base, Team *team) {
   team->setScore(baseRunnersOn + 1);
   clearBases();
}

void Game::tripleBaseAdvances(BASES base, Team *team) {
   team->setScore(baseRunnersOn);
   clearBases();
   baseRunnersOn = 1;
   onBase = THIRD;
}

void Game::doubleBaseAdvances(BASES base, Team *team) {
   if(onBase == EMPTY) {
      onBase = SECOND;
      baseRunnersOn = 1;
   } else if(onBase == FIRST) {
      onBase = SECOND_THIRD;
      baseRunnersOn = 2;
   } else if (onBase == FIRST_SECOND){
      team->setScore(1);
      baseRunnersOn = 2;
      onBase = SECOND_THIRD;
   } else if(onBase == FIRST_THIRD) {
      team->setScore(1);
      onBase = SECOND_THIRD;
   } else if(onBase == SECOND) {
      team->setScore(1);
   } else if(onBase == THIRD) {
      team->setScore(1);
      onBase = SECOND;
   } else if(onBase == SECOND_THIRD) {
      team->setScore(2);
      onBase = SECOND;
      baseRunnersOn = 1;
   } else {
      team->setScore(2);
      baseRunnersOn = 2;
      onBase = SECOND_THIRD;
   }
}

void Game::singleBaseAdvances(BASES base, Team *team) {
   if(onBase == EMPTY) {
      onBase = FIRST;
      baseRunnersOn = 1;
   }else if(onBase == FIRST) {
      onBase = FIRST_SECOND;
      baseRunnersOn = 2;
   } else if(onBase == SECOND) {
      onBase = SECOND_THIRD;
      baseRunnersOn = 2;
   } else if(onBase == FIRST_SECOND) {
      onBase = LOADED;
      baseRunnersOn = 3;
   } else if(onBase == FIRST_THIRD) {
      team->setScore(1);
      onBase = FIRST_SECOND;
   } else if(onBase == THIRD) {
      team->setScore(1);
      onBase = FIRST;
   } else if(onBase == SECOND_THIRD) {
      team->setScore(1);
      onBase = FIRST_THIRD;
   } else {
      team->setScore(1);
   }
}

void Game::advanceRunners(BASES hit, Team *team) {
   
   if(hit != WALK || hit != HBP) team->setHits();
   
   if(hit == WALK || hit == HBP) hit = SINGLE;

   if(hit == HR) {
      baseClearingAdvances(hit, team);
   } else if(hit == TRIPLE ) {
      tripleBaseAdvances(hit, team);
   } else if(hit == DOUBLE) {
      doubleBaseAdvances(hit, team);
   } else {
      singleBaseAdvances(hit, team);
   }
}
void Game::clearBases() {
   this->onBase = EMPTY;
   this-> baseRunnersOn = 0;
}

void Game::displayLineScore() {
   std::printf("%-15s", "Team");
   for(int i = 1; i <= inning; i++) {
      std::printf("%-2s", "|");
      std::printf("%-2d", i);
   }
   std::cout << "|  R  |  H  |  E  |" << std::endl;
   
   displayLineScore(this->visitingTeam, 0);
   displayLineScore(this->homeTeam, 1);
}

void Game::displayLineScore(Team *team, int num) {
   std::string t =  team->getTeamName();
   long len = t.length();
   char arr[len + 1];
   std::strcpy(arr, t.c_str());
   std::printf("%-15s", arr);
   for(int i = 0; i < inning; i++) {
      std::printf("%-2s", "|");
      std::printf("%-2d", lineScore[num][i]);

   }
   std::printf("%-3s", "|");
   std::printf("%-3d", team->getScore());
   std::printf("%-3s", "|");
   std::printf("%-3d", team->getHits());
   std::printf("%-3s", "|");
   std::printf("%-3d", 0);
   std::printf("%-3s", "|");
   std::cout << std::endl;
}





