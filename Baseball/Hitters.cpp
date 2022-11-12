//
//  Hitters.cpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#include "Hitters.h"
#include <iostream>


Hitter::Hitter(std::string name, int playerNum, double battingAvg, int atBats, int homeRuns, int hits, int doubles, int triples) {
   this->battingAvg = battingAvg;
   this->atBats = atBats;
   this->homeRuns = homeRuns;
   this->hits = hits;
   this->doubles = doubles;
   this->triples = triples;
   this->name = name;
   this->playerNum = playerNum;
}


double Hitter::getBattingAvg() {
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
