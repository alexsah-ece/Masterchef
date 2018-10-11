//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#include "CreativityCompetition.h"
#include <iostream>

using namespace std;

//Initialize the static array of ingredients
string CreativityCompetition::ingredients[10]={"eggs", "flour", "oil", "salt", "pepper", "tomatoes", "beef", "pork", "vegetables", "spices"};

//Prints the basic info of the Competition, plus
//info on the Excursion Award and the ingredients
//that the players had in hand.
void CreativityCompetition::status()
{
    Competition::status();
    cout << "The excursion award is : "<< endl;
    excursionAward.status();
    cout<< "The ingredients are:"<<endl;
    for (int i=0; i<10;i++){
        cout<<i+1<<". "<< ingredients[i]<<endl;
    }
}


//Has the references of the 2 teams as inputs. Uses them to
//get the pointer to the first element of the Players[11] array of each team.
//Uses these pointers to construct an array of pointers that cointains
//pointers to the players of both teams. Using this array, the function
//searches for the most skilled player so he can be named as the winner of the Competition.
void CreativityCompetition::compete(Team &team1, Team &team2)
{
    Player* PlayersOfTheTeam1=team1.getPlayers();
    Player* PlayersOfTheTeam2=team2.getPlayers();
    //Array of pointers to the players of both teams
    Player* allPlayers[team1.getNumberOfPlayers()+team2.getNumberOfPlayers()];
    //Set the right pointers to the allPlayers[] array
    for (int i=0,j=team1.getNumberOfPlayers(); i<team1.getNumberOfPlayers(); i++, j++){
        allPlayers[i]=PlayersOfTheTeam1+i;
        allPlayers[j]=PlayersOfTheTeam2+i;
    }
    //Find the most skilled player
    float maxTechnique=-1.0;
    int maxIndex=-1;
    for(int i=0; i<team1.getNumberOfPlayers() + team2.getNumberOfPlayers(); i++){
        float technique = allPlayers[i]->getTechnique();
        if ( technique > maxTechnique){
            maxTechnique = technique;
            maxIndex = i;
        }
    }
    //Update the necessary information
    Competition::setWinner(allPlayers[maxIndex]->getName());
    allPlayers[maxIndex]->status();
    allPlayers[maxIndex]->setWins(allPlayers[maxIndex]->getWins()+1);
    allPlayers[maxIndex]->setTechnique(allPlayers[maxIndex]->getTechnique()+excursionAward.getTechniqueBonus());
    allPlayers[maxIndex]->setPopularity(allPlayers[maxIndex]->getPopularity()+excursionAward.getPopularityPenalty());
}
