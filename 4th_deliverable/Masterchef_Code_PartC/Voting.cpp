//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#include "Voting.h"

using namespace std;

vector<Vote> Voting::votes;
map<string, int> Voting::results;

void Voting::votingProcess(Team &team)
{
    //Check if we meet the special conditions
    if (specialConditions(team)==true){
        return;
    }

    //Every player votes. Every vote is added to the "allVotes" vector.
    Player* p=team.getPlayers();
    for(int i=0; i<11; i++){
        if(p[i].getAge()!=0){
            playerVote(p, i);
        }
    }

    //Show the status of every vote gathered and count them.
    vector<Vote>::iterator v;
    v=votes.begin();
    while(v!=votes.end()){
        if(results.find(v->getVoted())==results.end()){
            results[v->getVoted()]=1;
        }else{
            results[v->getVoted()]++;
        }
        v->status();
        v++;
    }

    //Show the results of the voting after the count.
    cout << "\nThe results of the voting are : " << endl;
    map<string, int>::iterator m;
    m=results.begin();
    while(m!=results.end()){
        cout << m->second << "\t" << m->first << endl;
        m++;
    }

    //Set the candidates to leave
    string candidate1=getCandidate();
    string candidate2=getCandidate();
    cout << "\nThe candidates are: "<< candidate1 << " and "<< candidate2 << endl << endl;
    team.setCandidate(candidate1);
    team.setCandidate(candidate2);

    //Kick player out of the game.
    kickPlayer(team, candidate1, candidate2);

    //Erase the voting data so we can use the same data structures next time.
    votes.clear();
    results.clear();
}

//Check if there is only one or two players on the team.
//If there is one left, then this procedure can't take place.
//If there are two players left, then the one who lost the
//immunity competition is the one to leave the game.

bool Voting::specialConditions(Team &team)
{
    Player* p=team.getPlayers();
    int remainingNuOfPlayers=team.getNumberOfPlayers();
    if(remainingNuOfPlayers==1){
        cout << "\nNo players can be removed from " << team.getColor() << " team.\n" << endl;
        return true;
    }else if (remainingNuOfPlayers==2){
        for(int i=0; i<11; i++){
            if(p[i].getAge()!=0 && p[i].getImmunity()==false){
                cout << endl << p[i].getName() << " left the game.\n" << endl;
                team.removePlayer(p[i].getName());
            }
        }
        return true;
    }
    return false;
}

//Simulates the voting of a single player. The player votes
//as many times as the votes he has in total and he randomly
//choses to vote a player based on:
//a) him being too bad
//b) him being too good
//c) him being unpopular between the players
//Every vote that a player gives is added to the "allVotes" vector.
//Inputs are the array that contains the "players" of a team and the index
//corresponding on the position of the player that currently votes on the above array.

void Voting::playerVote(Player* p, int index)
{
    string voted, reason;
    for(int i=0; i< p[index].getVotes(); i++){
        switch(rand() % 3){
        case 0:
            reason="He is too good. I want him out of this game!";
            voted=goodPlayer(p, index);
            break;
        case 1:
            reason="He is too bad. He has to leave this game!";
            voted=badPlayer(p, index);
            break;
        case 2:
            reason="I don't like him.";
            voted=notPopular(p, index);
            break;
        }
        if(voted==" "){
            continue;
        }
        Vote vote(voted, reason);
        votes.push_back(vote);
    }
}

//Returns the name of the player of the "results" map that has the
//most votes. It also deletes him from the "results" map so the same
//function can be called in order to set the second candidate too.

string Voting::getCandidate()
{
    int maxValue=-1;
    string candidate=" ";
    map<string, int>::iterator itr;
    for(itr=results.begin(); itr!=results.end(); itr++){
        if( itr->second == maxValue){
            switch(rand() % 2){
            case 0:
                maxValue=itr->second;
                candidate=itr->first;
                break;
            case 1:
                break;
            }
        }
        if(itr->second > maxValue){
            maxValue=itr->second;
            candidate=itr->first;
        }
    }
    results.erase(candidate);
    return candidate;
}

//Gets an inputs the team and the two candidates and kicks out the less skilled
//player among the two.

void Voting::kickPlayer(Team &team, string candidate1, string candidate2)
{
    Player *p, *p1, *p2;
    p=team.getPlayers();
    for(int i=0; i<11; i++){
        if(p[i].getName()==candidate1){
            p1=p+i;
        }
        if(p[i].getName()==candidate2){
            p2=p+i;
        }
    }
    //Chose the less skilled player to be the one who leaves.
    if(p1->getTechnique()>p2->getTechnique()){
        cout << p2->getName() << " left the game.\n" << endl;
        team.removePlayer(p2->getName());
    }else{
        cout << p1->getName() << " left the game.\n" << endl;
        team.removePlayer(p1->getName());
    }
}

//Inputs are the array that contains the "players" of a team and the index
//corresponding on the position of the player that currently votes on the above array.
//It returns the least popular player among the remaining, ensuring that
//the returned player isn't the one that is currently voting or the winner of
//the immunity competition.

string Voting::notPopular(Player* p, int index)
{
    double minPopularity=101;
    int minIndex=-1;
    for(int i=0; i<11; i++){
        if(p[i].getAge()!=0 && i!=index && p[i].getImmunity()==false){
            if(p[i].getPopularity() < minPopularity){
                minPopularity=p[i].getPopularity();
                minIndex=i;
            }
        }
    }
    if (minIndex==-1){
        return " ";
    }
    return p[minIndex].getName();
}

//Inputs are the array that contains the "players" of a team and the index
//corresponding on the position of the player that currently votes on the above array.
//It returns the worst player among the remaining, ensuring that
//the returned player isn't the one that is currently voting or the winner of
//the immunity competition.

string Voting::badPlayer(Player* p, int index)
{
    double minTechnique=101;
    int minIndex=-1;
    for(int i=0; i<11; i++){
        if(p[i].getAge()!=0 && i!=index && p[i].getImmunity()==false){
            if(p[i].getTechnique() < minTechnique){
                minTechnique=p[i].getTechnique();
                minIndex=i;
            }
        }
    }
    if (minIndex==-1){
        return " ";
    }
    return p[minIndex].getName();
}

//Inputs are the array that contains the "players" of a team and the index
//corresponding on the position of the player that currently votes on the above array.
//It returns the best player among the remaining, ensuring that
//the returned player isn't the one that is currently voting or the winner of
//the immunity competition.

string Voting::goodPlayer(Player* p, int index)
{
    double maxTechnique=-1;
    int maxIndex=-1;
    for(int i=0; i<11; i++){
        if(p[i].getAge()!=0 && i!=index && p[i].getImmunity()==false){
            if(p[i].getTechnique() > maxTechnique){
                maxTechnique=p[i].getTechnique();
                maxIndex=i;
            }
        }
    }
    if (maxIndex==-1){
        return " ";
    }
    return p[maxIndex].getName();
}
