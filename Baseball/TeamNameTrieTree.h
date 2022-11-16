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
      TrieTreeNode *teamName[27] = { nullptr };
      char ch = '0';
      std::string *fullName = nullptr;
      std::list <char> nextChars;
      
      // Method adds a team name into the trie
      void build(std::string &name) {
         TrieTreeNode *curr = this;
         long len = name.length() - 1;
         int loc = 0;
         for(char c : name) {
            c -= '`'; // ` is used to notate spaces between words
            
            if(curr->teamName[c] == nullptr) {
               curr->teamName[c] = new TrieTreeNode;
               char save = c + '`';
               curr->teamName[c]->ch = save;
            }
            curr = curr->teamName[c];
            if(loc < len) curr->nextChars.push_back(name[loc + 1]);
            loc++;
         }
         curr->fullName = &name;  // hold full name at the last node
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
