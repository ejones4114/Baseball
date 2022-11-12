//
//  Hitters.hpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#ifndef Hitters_h
#define Hitters_h
#include "Player.cpp"
#include <stdio.h>


class Hitter : public Player {
   private :
   double battingAvg;
   int atBats;
   int homeRuns;
   int hits;
   int doubles;
   int triples;
   
   public :
   
   Hitter(std::string name, int playerNum, double battingAvg, int atBats, int homeRuns, int hits, int doubles, int triples);
   
   ~Hitter();
   
   double getBattingAvg();
   int getAtBats();
   int getHomeRuns();
   int getHits();
   int getDoubles();
   int getTriples();
   void display();
   
   
   
};





#endif /* Hitters_h */
