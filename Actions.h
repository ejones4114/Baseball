//
//  Actions.h
//  Baseball
//
//  Created by Eric Jones on 11/13/22.
//
#include "GameAction.h"
#include <iostream>





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
      return "base hit";
   }
   BASES baseReached(){
      return SINGLE;
   }
};

class Double : public Hit {
public:
   std::string description() {
      return "double";
   }
   BASES baseReached() {
      return DOUBLE;
   }
};

class Triple : public Hit {
public:
   std::string description() {
      return  "triple";
   }
   
   BASES baseReached() {
      return TRIPLE;
   }
};

class HomeRun : public Hit {
public:
   std::string description() {
      return "home run";
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
      return "hit by pitch";
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
      return "strikes out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};

class Groundout : public Out {
   std::string description() {
      return "grounds out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};

class Flyout : public Out {
   std::string description() {
      return "flys out";
   }
   
   BASES baseReached() {
      return NONE;
   }
};





#endif /* Actions_h */
