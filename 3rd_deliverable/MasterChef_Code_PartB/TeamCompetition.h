//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "FoodAward.h"
#include "Round.h"
#include "Team.h"
#include <random>
#include <iostream>
#include <string>

using namespace std;

class TeamCompetition: public Competition{

    FoodAward foodAward;
    Round rounds[3];

public:

    TeamCompetition():Competition() {}
    TeamCompetition(int id, string name, FoodAward a): Competition(id, name) {foodAward=a;}
    ~TeamCompetition(){cout << "TeamCompetition object is being destroyed..."<< endl;}

    FoodAward getFoodAward(){return foodAward;}
    Round* getRounds(){return rounds;}

    void setFoodAward(FoodAward a){foodAward=a;}
    void setRounds(Round* r){rounds[0]=r[0]; rounds[1]=r[1]; rounds[2]=r[2];}

    void status();
    int compete(Team &team1, Team &team2);
    void randomSelection(Team &team, Player** participants);
};

#endif // TEAMCOMPETITION_H_INCLUDED
