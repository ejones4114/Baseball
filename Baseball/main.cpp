//
//  main.cpp
//  Baseball
//
//  Created by Eric Jones on 11/10/22.
//


#include <iostream>
#include "CurlObject.cpp"
#include "TeamNameTrieTree.h"
#include "UserInput.h"

using namespace std;

class Baseball {
   
   
   
   
};






int main() {
   
   TeamNameTrieTree t;

   
   
   CurlObject *curl = new CurlObject("https://www.baseball-reference.com/teams/SEA/2022.shtml");
   string info = curl->getData();
   
   GumboOutput *out = gumbo_parse(info.c_str());

   std::cout << curl->cleantext(out->root) << std::endl;
   gumbo_destroy_output(&kGumboDefaultOptions, out);
   
   return 0;
}
