//
//  Actions.h
//  Baseball
//
//  Created by Eric Jones on 11/13/22.
//
#include "GameAction.h"
#include <iostream>
#include "Game.h"





#ifndef Actions_h
#define Actions_h



class Hit : public GameAction {
public:
   virtual std::string description() {
      return "Unknown Hit type";
   }
   virtual BASES baseReached() {
      return NONE;
   }
};


class Single : public Hit {
public:
   std::string description() {
      return this->getPlayerName() + " singles";
   }
   BASES baseReached(){
      return SINGLE;
   }
};

class Double : public Hit {
public:
   std::string description() {
      return this->getPlayerName() + " doubles";
   }
   BASES baseReached() {
      return DOUBLE;
   }
};

class Triple : public Hit {
public:
   std::string description() {
      return  this->getPlayerName() + " triples";
   }
   
   BASES baseReached() {
      return TRIPLE;
   }
};

class HomeRun : public Hit {
public:
   std::string description() {
      return this->getPlayerName() + " homers";
   }
   BASES baseReached() {
      return HR;
   }
};

class ReachedBaseNoHit : public GameAction {
public:
   virtual std::string description() {
      return "Unknown base reached";
   }
   virtual BASES baseReached() {
      return NONE;
   }
};

class Walk : public ReachedBaseNoHit {
public:
   std::string description() {
      return "walk";
   }
   BASES baseReached() {
      return WALK;
   }
};

class HitByPitch : public ReachedBaseNoHit {
public:
   std::string description() {
      return this->getPlayerName() +  " hit by pitch";
   }
   BASES baseReached() {
      return HBP;
   }
};

class Out : public GameAction {
   std::string description() {
      return "you'rrrre out!";
   }
   BASES baseReached() {
      return NONE;
   }
};

class Strikeout : public Out {
   std::string description() {
      return this->getPlayerName() + " strikes out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};

class Groundout : public Out {
   std::string description() {
      return this->getPlayerName() + " grounds out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};

class Flyout : public Out {
   std::string description() {
      return this->getPlayerName() + " flys out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};

class EndOfInningHalf : public GameAction {

private:
   Team *visiting;
   Team *home;
   std::string half;
   
public:
   
   EndOfInningHalf(int inning, Team *home, Team *visiting, std::string half) {
      this->home = home;
      this->visiting = visiting;
      this->half = half;
   }
   
   std::string description() {
      std::string result = "End of the " + half + "\n";
      result += "The score is " + this->home->getTeamName() + " ";
      result += home->getScore();
      result += this->visiting->getTeamName() + " ";
      result += this->visiting->getScore();
      return result;
   }
   
   BASES baseReached() {
      return NONE;
   }
};





#endif /* Actions_h */
