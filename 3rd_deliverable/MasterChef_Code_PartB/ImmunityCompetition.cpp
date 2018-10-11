//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#include "ImmunityCompetition.h"

using namespace std;

//Prints the basic information of the competition,
//plus the information of the immunity award.
void ImmunityCompetition::status()
{
    Competition::status();
    cout << "The immunity award is : "<< endl;
    immunityAward.status();
}

//Has a reference to a team as an input. Searches for
//the player with the best combination of 75% tecnique
//and 25% rest and makes him the winner of Immunity.
void ImmunityCompetition::compete(Team &team)
{
    int maxIndex = -1;
    float maxRating=-1.0;
    for (int i=0 ; i < team.getNumberOfPlayers(); i++){
        float rating=0.75*team.getPlayers()[i].getTechnique()+0.25*(100-team.getPlayers()[i].getFatigue());
        if(rating > maxRating){
            maxRating=rating;
            maxIndex=i;
        }
    }
    Competition::setWinner(team.getPlayers()[maxIndex].getName());
    team.getPlayers()[maxIndex].setWins(team.getPlayers()[maxIndex].getWins()+1);
}
