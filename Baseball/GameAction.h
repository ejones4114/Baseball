//
//  GameAction.hpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#ifndef GameAction_h
#define GameAction_h

#include <stdio.h>
#include <string>
#include "Calculations.h"
#include "Hitters.h"

enum BASES { SINGLE, DOUBLE, TRIPLE, HR, WALK, HBP, NONE };

class GameAction {
   
   Calculations c;
   
   public:
      
   
   virtual std::string description();
   virtual BASES baseReached();
   
   bool onBaseOrNot(Hitter* hitter);
   
   GameAction* typeOfOnBase(Hitter *hitter);
   
   GameAction* typeOfOut(Hitter *hitter);
   
};





#endif /* GameAction_h */
