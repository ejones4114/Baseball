//
//  TeamNameTrieTree.cpp
//  Baseball
//
//  Created by Eric Jones on 11/11/22.
//

#include "TeamNameTrieTree.h"
#include <iostream>

TeamNameTrieTree::TeamNameTrieTree() {
   populateListOfTeams();
   buildTeamTree();
}

TeamNameTrieTree::~TeamNameTrieTree() {
   for(int i = 0; i < 27; i++) {
      if(names->teamName[i] != nullptr) {
         deleteNames(names->teamName[i], 0);
      }
   }
}

void TeamNameTrieTree::deleteNames(TrieTreeNode * node, int index) {
   if(index > 27) {
      return;
   }
   index++;
}


void TeamNameTrieTree::buildTeamTree() {
   names = new TrieTreeNode;
   for(int i = 0; i < teamList.size(); i++) {
      names->build(teamList[i].teamName);
   }
}

void TeamNameTrieTree::populateListOfTeams() {
   TeamName t1;
   t1.teamName = "seattle`mariners";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "chicago`white`sox";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "cleveland`guardians";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "detroit`tigers";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "kansas`city`royals";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "minnesota`twins";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "chicago`cubs";
   t1.d = NLC;
   teamList.push_back(t1);
   
   t1.teamName = "cincinnati`reds";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "milwaukee`brewers";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "pittsburhgh`pirates";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "st`louis`cardinals";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "baltimore`orioles";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "boston`red`sox";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "new`york`yankees";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "tampa`bay`rays";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "toronto`blue`jays";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "atlanta`braves";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "miami`marlins";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "new`york`mets";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "philadelphia`phillies";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "washington`nationals";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "houston`astros";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "los`angeles`angels";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "oakland`athletics";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "texas`rangers";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "arizona`diamondbacks";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "colorado`rockies";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "los`angeles`dodgers";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "san`diego`padres";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "san`fransisco`giants";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "mariners";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "white`sox";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "guardians";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "tigers";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "royals";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "twins";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "cubs";
   t1.d = NLC;
   teamList.push_back(t1);
   
   t1.teamName = "reds";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "brewers";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "pirates";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "cardinals";
   t1.d = ALC;
   teamList.push_back(t1);
   
   t1.teamName = "orioles";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "red`sox";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "yankees";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "rays";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "blue`jays";
   t1.d = ALE;
   teamList.push_back(t1);
   
   t1.teamName = "braves";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "marlins";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "mets";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "phillies";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "nationals";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "astros";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "angels";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "athletics";
   t1.d = ALW;
   teamList.push_back(t1);
   
   t1.teamName = "rangers";
   t1.d = NLE;
   teamList.push_back(t1);
   
   t1.teamName = "diamondbacks";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "rockies";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "dodgers";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "padres";
   t1.d = NLW;
   teamList.push_back(t1);
   
   t1.teamName = "giants";
   t1.d = NLW;
   teamList.push_back(t1);
}

std::string TeamNameTrieTree::sanitizeInput(std::string team) const{
   std::string result = "";
   for(int i = 0; i < team.length(); i++) {
      if(team[i] == ' ') {
         result += '`';
      } else if((team[i] >= 'a' && team[i] <= 'z') || (team[i] >= 'A' && team[i] <= 'Z')) {
         
         if(team[i] >= 'A' && team[i] <= 'Z') {   // eliminate upper case letters
            result += team[i] + 32;
         } else {
            result += team[i];
         }
      }
   }
   return result;
}



// Method checks if passed in string is a team from the Trie
// This method will attempt to return what it thinks the user meant if the
// name has been mispelled.
std::string TeamNameTrieTree::teamResult(std::string team) const {
   if(names->teamName[team[0] - '`'] == nullptr) {
      return "Make a method to match similar strings";
   }
   
   TrieTreeNode *curr = names;
   TrieTreeNode *prev = nullptr;
   for(int i = 0; i < team.length(); i++) {
      if(curr == nullptr) {  // when typed response doesnt match trie
         char nextCharGuess = prev->nextChars.front();
         curr = prev->teamName[nextCharGuess - '`'];
         prev = curr;
      } else if (curr->fullName != nullptr) {
         break;
      }
      else {
         prev = curr;
         curr = curr->teamName[team[i] - '`'];
      }
   }
   
   std::string result = *curr->fullName;
   curr = nullptr;
   return result;
}

