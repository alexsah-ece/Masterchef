//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "Team.h"
#include "ExcursionAward.h"
#include <string.h>
#include <iostream>

using namespace std;

class CreativityCompetition:public Competition{

    ExcursionAward excursionAward;
    static string ingredients[10];

public:

    CreativityCompetition(){}
    CreativityCompetition(int idnum, string n, ExcursionAward excursionAward): Competition(idnum, n){this->excursionAward = excursionAward;}
    ~CreativityCompetition(){cout << "CreativityCompetition object with name " << name << "is destroyed." << endl;}

    ExcursionAward getExcursionAward(){return excursionAward;}
    void setExcursionAward(ExcursionAward val){excursionAward=val;}
    void status();
    void compete(Team &team1, Team &team2);
};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
