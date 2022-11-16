//
//  Calculations.cpp
//  Baseball
//
//  Created by Eric Jones on 11/13/22.
//

#include "Calculations.h"
#include "Hitters.h"
#include <iostream>


bool Calculations::onBase(int onBasePrcnt) {
   int randomNumber = getRandomNumber(1000);
   return (randomNumber <= onBasePrcnt) ? true : false;
}

bool Calculations::howBaseWasReached(Hitter *hitter) {
   int total = hitter->getHits() + hitter->getBB() + hitter->getIBB() + hitter->getHBP();
   return (getRandomNumber(total) <= hitter->getHits()) ? true : false;
}

int Calculations::getRandomNumber(int upperBound) {
   
   std::uniform_int_distribution<rng_type::result_type> udist(0, upperBound);
   rng_type rng;
   
   rng_type::result_type const seedval = get_seed();
   rng.seed(seedval);
   rng_type::result_type random = udist(rng);
   
   return random;
}

std::size_t Calculations::get_seed() {
    std::random_device entropy;
    return entropy();
}

int Calculations::typeOfHit(Hitter* hitter) {
   int upperBound = hitter->getHits();
   int hitChart[upperBound];
   int homeRuns = hitter->getHomeRuns();
   int triples = hitter->getTriples();
   int doubles = hitter->getDoubles();
   
   for(int i = 0; i <= upperBound; i++) {
      if(homeRuns > 0) {
         hitChart[i] = 4;
         homeRuns--;
      } else if(triples > 0) {
         hitChart[i] = 3;
         triples--;
      } else if(doubles > 0) {
         hitChart[i] = 2;
         doubles--;
      } else {
         hitChart[i] = 1;
      }
   }
   int rand = getRandomNumber(upperBound);
   int result = hitChart[rand];
   if(result <= 0 || result >= 5) {
      std::cout << "STOP HERE!!";
      std::cout << "I MEAN IT";
   }
   
   return result;
}

int Calculations::typeOfNonHit(Hitter *hitter) {
   int total = hitter->getBB() + hitter->getIBB() + hitter->getHBP();
   int bb = hitter->getBB() + hitter->getIBB();
   int chart[total];
   
   for(int i = 0; i <= total; i++) {
      if(bb > 0) {
         chart[i] = 5;
         bb--;
      } else {
         chart[i] = 6;
      }
   }
   int rand = getRandomNumber(total);
   int result = chart[rand];
   if(result <= 4 || result >= 7) {
      std::cout << "STOP HERE!!";
      std::cout << "I MEAN IT";
   }
   return result;
}

int Calculations::typeOfOut(Hitter *hitter) {
   int totalOuts = hitter->getPlateAppearances() - hitter->getHits() - hitter->getHBP() - hitter->getIBB() - hitter->getBB();
   int SO = hitter->getStrikeOuts();
   int flys = (totalOuts - SO) / 2;
   int outChart[totalOuts];
   
   
   
   
   for(int i = 0; i <= totalOuts; i++) {
      if(SO > 0) {
         outChart[i] = 1;
         SO--;
      } else if(flys > 0) {
         outChart[i] = 2;
         flys--;
      } else {
         outChart[i] = 3;
      }
   }
   
   int rand = getRandomNumber(totalOuts);
   int result = outChart[rand];
   
   if(result <= 0 || result >= 4) {
      std::cout << "STOP HERE!!";
      std::cout << "I MEAN IT";
   }
   return outChart[result];
}

