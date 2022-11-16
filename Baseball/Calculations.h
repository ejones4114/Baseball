//
//  Calculations.hpp
//  Baseball
//
//  Created by Eric Jones on 11/13/22.
//

#ifndef Calculations_h
#define Calculations_h

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Hitters.h"
#include <random>
#include <functional>



#endif /* Calculations_h */

typedef std::mt19937 rng_type;

class Calculations {
   
private:
   
   std::size_t get_seed();
   int getRandomNumber(int upperBound);
   
public:
   //Given a batting average returns
   bool onBase(int battingAvg);
   
   bool howBaseWasReached(Hitter* hitter);
   
   int typeOfHit(Hitter* hitter);

   int typeOfNonHit(Hitter *hitter);

   int typeOfOut(Hitter *hitter);
   
   
};
