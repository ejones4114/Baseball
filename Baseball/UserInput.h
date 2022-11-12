//
//  UserInput.hpp
//  GUmbo2
//
//  Created by Eric Jones on 11/12/22.
//

#ifndef UserInput_h
#define UserInput_h

#include <stdio.h>
#include <iostream>
#include "TeamNameTrieTree.h"


class UserInput {
   
public:
   
   UserInput();
   
   std::string gatherHomeData(const TeamNameTrieTree &t) const;
   std::string gatherVisitingData(const TeamNameTrieTree &t) const;
   
};




#endif /* UserInput_h */
