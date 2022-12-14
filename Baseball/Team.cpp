//
//  Team.cpp
//  Baseball
//
//  Created by Eric Jones on 11/12/22.
//

#include "Team.h"
#include "Hitters.h"
#include "CurlObject.cpp"
#include <sstream>
#include <vector>


Team::Team(std::string name) {
   this->name = name;
   this->nameAbbr = getAbbr(name);
   this->score = 0;
   this->batterUp = 0;
   this->hits = 0;
   
   populateTeam();
}

Team::~Team() {
   for(int i = 0; i < 9; i++) {
      delete hitters[i];
   }
}

std::string Team::getAbbr(std::string name) {
   std::string res = "";
   if(name == "seattle`mariners" || name == "mariners" || name =="seattle") res += "SEA";
   else if(name == "chicago`white`sox" || name =="white`sox") res += "CHW";
   else if(name ==  "cleveland`guardians" || name =="guardians" ) res += "CLE";
   else if(name == "detroit`tigers" || name == "tigers" ) res += "DET";
   else if(name == "kansas`city`royals" || name =="royals") res += "KCR";
   else if(name == "minnesota`twins" || name == "twins") res += "MIN";
   else if(name == "chicago`cubs" ||  name == "cubs") res += "CHC";
   else if(name ==  "cincinnati`reds" ||  name =="reds") res += "CIN";
   else if(name == "milwaukee`brewers" ||  name =="brewers" ||name =="milwaukee") res += "MIL";
   else if(name == "pittsburhgh`pirates" ||name == "pirates" ||name =="pittsburg") res += "PIT";
   else if(name == "st`louis`cardinals" ||name == "cardinals" ||name == "st`louis") res += "STL";
   else if(name == "baltimore`orioles" || name =="orioles" || name == "baltimore") res += "BAL";
   else if(name == "boston`red`sox" ||name == "red'sox" ||name == "boston" ) res += "BOS";
   else if(name == "new`york`yankees"  ||name == "yankees") res += "NYY";
   else if(name == "tampa`bay`rays" ||name == "rays" ||name == "tampa'bay") res += "TBR";
   else if(name ==  "toronto`blue`jays" || name == "blue`jays") res += "TOR";
   else if(name == "atlanta`braves" || name == "braves") res += "ATL";
   else if(name == "miami`marlins" || name == "marlins") res += "MIA";
   else if(name == "new`york`mets" || name == "mets") res += "NYM";
   else if(name == "philadelphia`phillies" || name == "phillies") res += "PHI";
   else if(name == "washington`nationals" || name == "nationals") res += "WSN";
   else if(name == "houston`astros" || name == "astros") res += "HOU";
   else if(name == "los`angeles`angels" || name == "angles") res += "LAA";
   else if(name ==  "oakland`athletics" ||name == "athletics") res += "OAK";
   else if(name ==  "texas`rangers" || name == "rangers") res += "TEX";
   else if(name ==  "arizona`diamondbacks" || name == "diamondbacks") res += "ARI";
   else if(name == "colorado`rockies" || name == "rockies") res += "COL";
   else if(name ==  "los`angeles`dodgers" || name == "dodgers") res += "LAD";
   else if(name == "san`diego`padres" || name == "padres") res += "SDP";
   else res += "SFG";
   return res;
}

void Team::populateTeam() {
   std::string url = "https://www.baseball-reference.com/teams/";
   url += this->nameAbbr;
   url += "/2022.shtml";
   CurlObject *curl = new CurlObject(url);
   
   std::string info = curl->getData();
   GumboOutput *out = gumbo_parse(info.c_str());
   
   std::string hitters = (curl->cleantext(out->root));
   
   hitters = curl->stringToParse(hitters);
   gumbo_destroy_output(&kGumboDefaultOptions, out);
   
   buildLineUp(hitters);
}

//stats[0] = Age
//stats[1] = Games
//stats[2] = plateAppearances
//stats[3] = At bats
//stats[4] = Runs
//stats[5] = Hits
//stats[6] = 2B
//stats[7] = 3B
//stats[8] = HR
//stats[9] = RBI
//stats[10] = StolenBases
//stats[11] = CaughtStealing
//stats[12] = BB
//stats[13] = StrikeOuts
//stats[14] = BattingAvg
//stats[15] = On Base percnt
//stats[16] = SLG
//stats[17] = OPS
//stats[18] = OPS+
//stats[19] = TB
//stats[20] = GroundedIntoDPs
//stats[21] = HitByPitch
//stats[22] = SacBunts
//stats[23] = SacFlies
//stats[24] = IntentionalBB
void Team::buildLineUp(std::string hitters) {
   std::string name = "";
   std::istringstream is(hitters);
   int stats[25];
   for(int i = 0; i < 9; i++) {
      name = playerName(is, i);
      playerStats(is, stats);
      this->hitters[i] = new Hitter(name, stats[0], stats[1], stats[2], stats[3], stats[4], stats[5], stats[6], stats[7], stats[8], stats[9], stats[10], stats[11], stats[12],
         stats[13], stats[14], stats[15], stats[16], stats[17], stats[18], stats[19], stats[20],stats[21], stats[22], stats[23], stats[24]);
   }
}



std::string Team::playerName(std::istringstream &is, int lineUpNum) {
   int size = 5;
   std::string name = "";
   if(lineUpNum == 0) size = 4;
   
   for(int j = 0; j < size; j++) {
      is.get();
   }
   
   std::string n;
   char c = is.peek();
   while((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
      
      if(c == ' ') {
         is.get();
         c = is.peek();
      }
      
      else {
         is >> n;
         name += n;
         name += " ";
         c = is.peek();
      }
   }
   return name;
}

void Team::playerStats(std::istringstream &is, int *stats) {
   
   for(int i = 0; i < 25; i++) {
      while(is.peek() < '0' || is.peek() > '9') {
         is.get();
      }
      is >> stats[i];
   }
}

Player* Team::getHitter(int lineUpNum) {
   return this->hitters[lineUpNum];
}

int Team::getBatterUp() {
   return this->batterUp;
}

void Team::setBatterUp(int batterUp) {
   this->batterUp = batterUp;
}


int Team::getScore() {
   return this->score;
}
void Team::setScore(int score) {
   this->score += score;
}

void Team::setHits() {
   this->hits++;
}

int Team::getHits() {
   return this->hits;
}

std::string Team::getTeamName() {
   return this->name;
}
