//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#include "TeamCompetition.h"

using namespace std;

//Printing the basic info of the competition,
//plus info on the award and the results of
//each round of the challenge.
void TeamCompetition::status()
{
    Competition::status();
    foodAward.status();
    cout <<"Individual rounds' results:"<<endl;
    for(int i=0; i<3; i++){
        cout <<"\t";
        rounds[i].status();
    }
    cout << endl;
}

//Simulates the Team Competition. It has 3 rounds. For every
//round 5 players of each team take part, randomly.
//The team that wins 2 rounds gets the prize. The function
//returns 0 if the red team loses and 1 if the blue team loses.
int TeamCompetition::compete(Team &team1, Team &team2)
{
    int wins1=0, wins2=0, round=1;
    while (round<4){
        //Update the info for every Round object
        rounds[round-1].setId(round);
        rounds[round-1].setDuration(3*60*60);
        //Declare the necessary, to find the round winner, variables
        Player *participants1[5], *participants2[5];
        float skill_1=0, fatigue_1=0, skill_2=0, fatigue_2=0;
        //Select the participants from each team
        randomSelection(team1, participants1);
        randomSelection(team2, participants2);
        //Compute the skill and fatigue of each team
        for(int i=0; i<5; i++){
            //Team RED
            participants1[i]->compete();
            skill_1+=participants1[i]->getTechnique();
            fatigue_1+=participants1[i]->getFatigue();
            //Team BLUE
            participants2[i]->compete();
            skill_2+=participants2[i]->getTechnique();
            fatigue_2+=participants2[i]->getFatigue();
        }
        //Decide the winner of the current round
        if((skill_1 > skill_2) || (skill_1==skill_2 && fatigue_1 < fatigue_2)){
            rounds[round-1].setWinner("Red");
            wins1++;
        }else{
            rounds[round-1].setWinner("Blue");
            wins2++;
        }
        round++;
    }
    //Decide the winner of the Team Competition and update the necessary info
    if(wins1>=2){
        team1.setWins(team1.getWins()+1);
        team1.setSupplies(team1.getSupplies()+foodAward.getBonusSupplies());
        Competition::setWinner("Red");
        return 1;
    }else{
        team2.setWins(team2.getWins()+1);
        team2.setSupplies(team2.getSupplies()+foodAward.getBonusSupplies());
        Competition::setWinner("Blue");
        return 0;
    }
}

//Has a reference to a team and a pointer to the first element of an array of pointers as inputs.
//Randomly picks 5 players of the "team" and updates the
//array "participants" with pointers to the players that are going
//to take part in the current round. It uses the boolean selceted[11] array
//so it can check whether a player has already been included on the participant list or not.
void TeamCompetition::randomSelection(Team &team, Player** participants)
{
    int select;
    //Flag array so we can know if a player has already been chosen
    bool selected[11]={false, false, false, false, false, false, false, false, false, false, false};
    //For every one of the 5 places of the participants list
    for(int i=0; i<5; i++){
        do{
            //Randomly select a player
            select=rand()%11;
        //While we pick players that already have been chosen, repeat the proccess to find a new one
        }while(selected[select]);
        //Mark the player as selected
        selected[select]=true;
        //Add the player on the participants list
        participants[i]=(team.getPlayers()+select);
    }
}
