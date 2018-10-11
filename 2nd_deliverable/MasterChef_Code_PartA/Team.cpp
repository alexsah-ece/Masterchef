//Αλέξανδρος Σαχίνης 8906 alexsach@ece.auth.gr
//Νικόλαος Πίγκας 9329 ngpigkas@ece.auth.gr
#include "Team.h"

using namespace std;

//Constructors and destructors

Team::Team(){
	color = " ";
	numOfMeals = 0;
	curNuOfMembers=0;
	ingredients = " ";
	winTotal = 0;
}

Team::Team(string co, int nu, string in, int wi){
	color = co;
	numOfMeals = nu;
	curNuOfMembers=0;
	ingredients = in;
	winTotal = wi;
}

Team::~Team(){
	cout << "Team object with color : \"" << color << "\" is destroyed." << endl;
}


//Setters

void Team::setColor(string co){
    color=co;
}

void Team::setNumOfMeals(int meals){
    numOfMeals=meals;
}

void Team::setIngredients(string ingred){
    ingredients=ingred;
}

void Team::setWinTotal(int wins){
    winTotal=wins;
}

void Team::setCurNuOfMembers(int n){
    curNuOfMembers=n;
}


//Getters

string Team::getColor(){
    return color;
}

int Team::getNumOfMeals(){
    return numOfMeals;
}

string Team::getIngredients(){
    return ingredients;
}

int Team::getWinTotal(){
    return winTotal;
}

int Team::getCurNuOfMembers(){
    return curNuOfMembers;
}


//Rest of the functions

//Gets as a parameter a player object. Firstly, it checks
//if the team is full. If it is, it displays  an appropriate
//message. If it isn't, it adds the player to the team and
//increases the number of team members by one.
void Team::addMember(Player p){
    if(curNuOfMembers >=11){
        cout << "You can not add anymore players to the "<< color <<" team"<< endl;
    }else{
        members[curNuOfMembers]=p;
        curNuOfMembers++;
    }
}

//Displays the details of the team
void Team::status(){
    cout << "Color: "<< color << endl;
    cout << "Number of meals: "<<numOfMeals<<endl;
    cout << "Ingredients: "<<ingredients<<endl;
    cout << "Win total: "<< winTotal<< endl;
    cout << "Members: "<< endl;
    if (curNuOfMembers==0){
        cout <<"\tNo members on the team" << endl;
    }else{
        for(int i=0; i<curNuOfMembers; i++){
            cout <<"\t "<< i+1<< ". "<< members[i].getName()<< endl;
        }
        cout << "Number of members: "<<curNuOfMembers<<endl;
    }
}

//Searches for a player in the team based on his number (1 to curNumOfMembers).
//If the number is out of range, an error message pops.
//Else, it displays the player's details.
void Team::dispPlayer(int number){
    if (number > curNuOfMembers || number <=0){
        cout << "The player you requested to see does not exist" << endl;
    }else{
        members[number-1].status();
    }
}

//Searches for a player based on his name. If he is found, his
//details get displayed. Else, an error message pops.
void Team::dispPlayer(string name){
    for(int i=0; i<curNuOfMembers; i++){
        if(members[i].getName()==name){
            members[i].status();
            return;
        }
    }
    //Player not found
    cout << "The player you requested to see does not exist" << endl;
}
