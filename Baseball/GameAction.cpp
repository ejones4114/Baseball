//
//  GameAction.cpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#include "GameAction.h"
#include "Actions.h"



bool GameAction::onBaseOrNot(Hitter* hitter) {
   return c.onBase(hitter->getOnBasePrcnt());
}

std::string GameAction::description() {
   return "Unknown Game Action";
}
BASES GameAction::baseReached() {
   return NONE;
}


GameAction* GameAction::typeOfOnBase(Hitter *hitter) {
   bool result = c.howBaseWasReached(hitter); // true = Hit
   int whatBase = 0;
   if(result == true) { // it was a hit
      whatBase = c.typeOfHit(hitter);
   } else if(result == false) {
      whatBase = c.typeOfNonHit(hitter);
   }
   
   if(whatBase <= 0 || whatBase >= 7) {
      std::cout << "STOP HERE!!";
      std::cout << "I MEAN IT";
   }
   
   GameAction *a = nullptr;
   switch (whatBase) {
      case 1:
         a = new Single;
         break;
      case 2:
         a = new Double;
         break;
      case 3:
         a = new Triple;
         break;
      case 4:
         a = new HomeRun;
         break;
      case 5:
         a = new Walk;
         break;
      case 6:
         a = new HitByPitch;
         break;
   }
   return a;
}

GameAction* GameAction::typeOfOut(Hitter *hitter) {
   GameAction *a = nullptr;
   
   int result = c.typeOfOut(hitter);
   
   if(result <= 0 || result >= 4) {
      std::cout << "HALT";
   }
   
   switch(result) {
      case 1: a = new Strikeout;
         break;
      case 2: a = new Flyout;
         break;
      case 3: a = new Groundout;
         break;
   }
   return a;
}


void GameAction::setPlayerName(std::string name) {
   this->playerName = name;
}

std::string  GameAction::getPlayerName() {
   return this->playerName;
}


