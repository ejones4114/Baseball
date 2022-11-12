//
//  main.cpp
//  Baseball
//
//  Created by Eric Jones on 11/10/22.
//


#include <iostream>
#include "TeamNameTrieTree.h"
#include "UserInput.h"
#include "Game.h"

using namespace std;

class Baseball {
   public :
   Baseball() {
      TeamNameTrieTree t;
      UserInput in;
      std::string home = in.gatherHomeData(t);
      std::string visiting = in.gatherVisitingData(t);
      Game g(home, visiting);
   }
   
   
   
   
};






int main() {
   Baseball b;

   

   
   return 0;
}
