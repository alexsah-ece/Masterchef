//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#include "Team.h"
#include "FoodAward.h"
#include "ExcursionAward.h"
#include "ImmunityAward.h"
#include "TeamCompetition.h"
#include "CreativityCompetition.h"
#include "ImmunityCompetition.h"
#include  <random>
#include  <time.h>

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 0;
int teamLost=-1;
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

//Every team works and eats in the morning,
//eats, socializes and sleeps in the afternoon
void normalDay()
{
    cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;

    for(int i=0; i<2; i++){
        //Morning
        teams[i].teamWorks();
        teams[i].teamEats();
        //Evening
        teams[i].teamEats();
        teams[i].teamSocializes();
        //Night
        teams[i].teamSleeps();

    }
}

/*
 *Every team does the same activities as a normal day
 *with the addition of competing in a team challenge.
 *For this purpose, we create the challenge, giving its id
 *name and award. We then run the challenge and when it is finished
 *we present its information.
 */
void teamCompetitionDay()
{
    cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;

    for(int i=0; i<2; i++){
        //Morning
        teams[i].teamWorks();
        teams[i].teamEats();
    }

    competitionId++;
    FoodAward foodAward("Award #"+to_string(competitionId)+" (Food)", false);
    TeamCompetition TeamComp(competitionId, "Competition #"+ to_string(competitionId)+" (Team)", foodAward);
    teamLost=TeamComp.compete(teams[0], teams[1]);
    TeamComp.status();

    for(int i=0; i<2; i++){
        //Evening
        teams[i].teamEats();
        teams[i].teamSocializes();
        //Night
        teams[i].teamSleeps();
    }
}

/*
 *Every team does the same activities as a normal day.
 *The team that lost the team challenge has to go through an
 *immunity challenge.
 *For this purpose, we create the challenge, giving its id
 *name and award. We then run the challenge and when it is finished
 *we present its information.
 */
void immunityCompetitionDay()
{

    cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;

   for(int i=0; i<2; i++){
        teams[i].teamWorks();
        teams[i].teamEats();
    }

    competitionId++;
    ImmunityAward immunityAward("Award #"+to_string(competitionId)+" (Immunity)", true);
    ImmunityCompetition immunityComp(competitionId, "Competiton #" + to_string(competitionId)+" (Imunity)", immunityAward);

    switch (teamLost){
    case 0:
            immunityComp.compete(teams[0]);
            break;
    case 1:
            immunityComp.compete(teams[1]);
            break;
    default:
            cout << "No team competitions have been played yet"<<endl;
    }
    immunityComp.status();

    for(int i=0; i<2; i++){
        teams[i].teamEats();
        teams[i].teamSocializes();
        teams[i].teamSleeps();
    }

}

/*
 *Every team does the same activities as a normal day with
 *the addition of both teams taking part in an creativity challenge.
 *The prize is individual and goes to the player with the best tecnique.
 *For this purpose, we create the challenge, giving its id
 *name and award. We then run the challenge and when it is finished
 *we present its information.
 */
void creativityCompetitionDay()
{

    cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;

    for(int i=0; i<2; i++){
        teams[i].teamWorks();
        teams[i].teamEats();
    }

    competitionId++;
    ExcursionAward excursionAward("Award #" + to_string(competitionId)+" (Excursion)", true);
    CreativityCompetition creativityComp(competitionId, "Competition #" + to_string(competitionId)+" (Creativity)", excursionAward);
    creativityComp.compete(teams[0], teams[1]);
    creativityComp.status();

    for(int i=0; i<2; i++){
        teams[i].teamEats();
        teams[i].teamSocializes();
        teams[i].teamSleeps();
    }
}
