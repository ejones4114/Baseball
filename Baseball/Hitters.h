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
   int age;
   int games;
   int plateAppearances;
   int atBats;
   int runs;
   int hits;
   int doubles;
   int triples;
   int homeRuns;
   int rbi;
   int stolenBases;
   int caughtStealing;
   int bb;
   int strikeOuts;
   int battingAvg;
   int onBasePrcnt;
   int slg;
   int ops;
   int opss;
   int tb;     //total bases
   int gdps;   // GroundedIntoDPs
   int hbp;    // HitByPitch
   int sb;     // SacBunts
   int sf;     // SacFlies
   int ibb;    // IntentionalBB
   
   public :
   
   Hitter(std::string name, int age, int games, int plateAppearances, int atBats, int runs, int hits, int doubles,  int triples, int homeRuns, int rbi, int stolenBases, int caughtStealing, int bb, int strikeOuts, int battingAvg, int onBasePrcnt, int slg, int ops, int opss, int tb, int gdps, int hbp, int sb, int sf, int ibb);
   
   ~Hitter();
   
   int getAge();
   int getGames();
   int getRuns();
   int getRBI();
   int getStolenBases();
   int getCaughtStealing();
   int getStrikeOuts();
   int getSLG();
   int getOPS();
   int getOPSS();
   int getTB();
   int getGDPS();
   int getHBP();
   int getSB();
   int getSF();
   int getIBB();
   
   int getBattingAvg();
   int getAtBats();
   int getHomeRuns();
   int getHits();
   int getDoubles();
   int getTriples();
   int getOnBasePrcnt();
   int getBB();
   int getPlateAppearances();
   std::string getName();
   
   void display();
   
   
};





#endif /* Hitters_h */
