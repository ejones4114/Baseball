//
//  Calculations.cpp
//  Baseball
//
//  Created by Eric Jones on 11/13/22.
//

#include "Calculations.h"
#include "Hitters.h"


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
   
   for(int i = 0; i < upperBound; i++) {
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
   return hitChart[getRandomNumber(upperBound)];
}

int Calculations::typeOfNonHit(Hitter *hitter) {
   int totalOuts = hitter->getPlateAppearances() - hitter->getHits() - hitter->getHBP() - hitter->getIBB() - hitter->getBB();
   int SO = hitter->getStrikeOuts();
   int flys = totalOuts / SO;
   int outChart[totalOuts];
   
   for(int i = 0; i < totalOuts; i++) {
      if(SO > 0) {
         outChart[i] = 1;
      } else if(flys > 0) {
         outChart[i] = 2;
      } else {
         outChart[i] = 3;
      }
   }
   return outChart[getRandomNumber(totalOuts)];
}


