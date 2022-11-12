//
//  TeamNameTrieTree.hpp
//  Baseball
//
//  Created by Eric Jones on 11/11/22.
//

#ifndef TeamNameTrieTree_h
#define TeamNameTrieTree_h

#include <stdio.h>
#include <string>
#include <list>
#include <vector>



class TeamNameTrieTree {
   
   private :
   
   enum DIVISION { ALE, ALC, ALW, NLE, NLC, NLW };
   
   
   struct TeamName {
      DIVISION d;
      std::string teamName = "";
      
      TeamName() { }
      
      TeamName(std::string name, DIVISION d) {
         this->d = d;
         this->teamName = name;
      }
      
   };
   
   struct TrieTreeNode {
      TrieTreeNode *teamName[27] = { };
      char ch = '0';
      std::string *fullName;
      std::list <char> nextChars;
      
      void build(std::string &name) {
         TrieTreeNode *curr = this;
         for(char c : name) {
            c -= '`';
            if(curr->teamName[c] == nullptr) {
               curr->teamName[c] = new TrieTreeNode;
               char save = c + '`';
               curr->teamName[c]->ch = save;
            }
            curr = curr->teamName[c];
         }
         curr->fullName = &name;
         curr = nullptr;
      }
      
   };
   
   TrieTreeNode * names;
   std::vector<TeamName> teamList;
   
public:
   
   TeamNameTrieTree();
   ~TeamNameTrieTree();
   
   std::string sanitizeInput(std::string team) const;
   
   std::string teamResult(std::string team) const;
   void deleteNames(TrieTreeNode * node, int index);
   
   void buildTeamTree();
   void populateListOfTeams();
   
   
};



#endif /* TeamNameTrieTree_h */
