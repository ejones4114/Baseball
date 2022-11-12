//
//  UserInput.cpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#include "UserInput.h"


UserInput::UserInput() { }

std::string UserInput::gatherHomeData(const TeamNameTrieTree &t) const{
   
   std::cout << "What is your home team?" << std::endl;
   std::string homeTeam;
   getline(std::cin, homeTeam);
   homeTeam = t.sanitizeInput(homeTeam);
   homeTeam = t.teamResult(homeTeam);
   return homeTeam;
}
  
std::string UserInput::gatherVisitingData(const TeamNameTrieTree &t) const {
   std::cout << "What is your visitng team" << std::endl;
   std::string visitingTeam;
   getline(std::cin, visitingTeam);
   visitingTeam = t.sanitizeInput(visitingTeam);
   visitingTeam = t.teamResult(visitingTeam);
   return visitingTeam;
   
}
