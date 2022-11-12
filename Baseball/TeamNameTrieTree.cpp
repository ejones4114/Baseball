//
//  TeamNameTrieTree.cpp
//  Baseball
//
//  Created by Eric Jones on 11/11/22.
//

#include "TeamNameTrieTree.h"

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


std::string TeamNameTrieTree::teamResult(std::string team) const {
   if(names->teamName[team[0] - '`'] == nullptr) {
      return "";
   }
   
   TrieTreeNode *curr = names;
   TrieTreeNode *prev = names;
   for(int i = 0; i < team.length(); i++) {
      if(curr == nullptr) {
         
      }
      curr = curr->teamName[team[i] - '`'];
   }
   
   std::string result = *curr->fullName;
   curr = nullptr;
   prev = nullptr;
   return result;
}

