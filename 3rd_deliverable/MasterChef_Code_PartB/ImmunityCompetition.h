//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "ImmunityAward.h"
#include "Team.h"
#include <string>
#include <iostream>

using namespace std;

class ImmunityCompetition : public Competition {

    ImmunityAward immunityAward;

public:
    ImmunityCompetition(){}
    ImmunityCompetition(int idnum, string n, ImmunityAward imAw):Competition(idnum, n){immunityAward=imAw;}
    ~ImmunityCompetition(){cout<< "ImmunityCompetition object with name : " << name << "is destroyed." << endl;}

    ImmunityAward getImmunityAward(){return immunityAward;}
    void setImmunityAward(ImmunityAward val){immunityAward = val;}

    void status();
    void compete(Team &team);

};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
