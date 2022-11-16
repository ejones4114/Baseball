//
//  Hitters.cpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#include "Hitters.h"
#include <iostream>


Hitter::   Hitter(std::string name, int age, int games, int plateAppearances, int atBats, int runs, int hits, int doubles,  int triples, int homeRuns, int rbi, int stolenBases, int caughtStealing, int bb, int strikeOuts, int battingAvg, int onBasePrcnt, int slg, int ops, int opss, int tb, int gdps, int hbp, int sb, int sf, int ibb) {
   this->battingAvg = battingAvg;
   this->atBats = atBats;
   this->homeRuns = homeRuns;
   this->hits = hits;
   this->doubles = doubles;
   this->triples = triples;
   this->name = name;
   this->playerNum = playerNum;
   this->onBasePrcnt = onBasePrcnt;
   this->bb = bb;
   this->plateAppearances = plateAppearances;
   this->age = age;
   this->games = games;
   this->plateAppearances = plateAppearances;
   this->runs = runs;
   this->rbi = rbi;
   this->stolenBases = stolenBases;
   this->caughtStealing = caughtStealing;
   this->strikeOuts = strikeOuts;
   this->slg = slg;
   this->ops = ops;
   this->opss = opss;
   this->tb = tb;
   this->hbp = hbp;
   this->sb = sb;
   this->ibb = ibb;
}

Hitter::~Hitter() {
   delete this;
}

std::string Hitter::getName() {
   return Player::getName();
}

int Hitter::getBattingAvg() {
   return this->battingAvg;
}
int Hitter::getAtBats() {
   return this->atBats;
}
int Hitter::getHomeRuns() {
   return this->homeRuns;
}
int Hitter::getHits() {
   return this->hits;
}
int Hitter::getDoubles() {
   return this->doubles;
}
int Hitter::getTriples() {
   return this->triples;
}

int Hitter::getOnBasePrcnt() {
   return this->onBasePrcnt;
}

int Hitter::getBB() {
   return this->bb;
}

int Hitter::getPlateAppearances() {
   return this->plateAppearances;
}

int Hitter::getAge() {
   return this->age;
}
int Hitter::getGames() {
   return this->games;
}
int Hitter::getRuns() {
   return this->runs;
}
int Hitter::getRBI() {
   return this->rbi;
}
int Hitter::getStolenBases() {
   return this->stolenBases;
}
int Hitter::getCaughtStealing() {
   return this->caughtStealing;
}
int Hitter::getStrikeOuts() {
   return this->strikeOuts;
}
int Hitter::getSLG() {
   return this->slg;
}
int Hitter::getOPS() {
   return this->ops;
}
int Hitter::getOPSS() {
   return this->opss;
}
int Hitter::getTB() {
   return this->tb;
}
int Hitter::getGDPS() {
   return this->gdps;
}
int Hitter::getHBP() {
   return this->hbp;
}
int Hitter::getSB() {
   return this->sb;
}
int Hitter::getSF() {
   return this->sf;
}
int Hitter::getIBB() {
   return this->ibb;
}



void Hitter::display() {
   std::cout << "I am a hitter" << std::endl;
   std::cout << "My name is " << this->name;
   std:: cout << ". Here are my stats" << std::endl;
   std::cout << "Home Runs: " << homeRuns << std::endl;
   std::cout << "Doubles: " << doubles<< std::endl;
   std::cout << "Triples: " << triples<< std::endl;
   std::cout << "Batting average ." << battingAvg << std::endl;
   std::cout << "Hits: " << hits << std::endl;
   
}
