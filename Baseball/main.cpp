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
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Baseball {
   public :
   Baseball() {
      TeamNameTrieTree t;
      UserInput in;
      std::string home = in.gatherHomeData(t);
      std::string visiting = in.gatherVisitingData(t);
      Game g(home, visiting);
      g.displayLineScore();
   }
   
   
   
   
};

std::size_t get_seed() {
    std::random_device entropy;
    return entropy();
}


int main() {
   
   
   Baseball b;

   

   
   return 0;
}
