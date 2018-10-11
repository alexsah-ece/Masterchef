//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

#include <vector>
#include <map>
#include "Vote.h"
#include "Team.h"
#include <stdlib.h>

using namespace std;

class Voting{

    static vector<Vote> votes;
    static map<string,int> results;

    //Helping functions
    static bool specialConditions(Team &team);
    static void playerVote(Player* p, int i);
    static void kickPlayer(Team &team, string c1, string c2);
    static string getCandidate();
    static string notPopular(Player* p, int i);
    static string badPlayer(Player* p, int i);
    static string goodPlayer(Player* p, int i);

public:

    static void votingProcess(Team &team);

};

#endif // VOTING_H_INCLUDED
