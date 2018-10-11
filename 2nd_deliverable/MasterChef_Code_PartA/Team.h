//Αλέξανδρος Σαχίνης 8906 alexsach@ece.auth.gr
//Νικόλαος Πίγκας 9329 ngpigkas@ece.auth.gr
#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Player.h"

using namespace std;

//Cointains all the information and the functions needed
//to simulate a team in the game "Masterchef"
class Team{

    Player members[11];
    int curNuOfMembers;
	string color;
	int numOfMeals;
	string ingredients;
	int winTotal;

public:
	Team();
	Team(string co, int nu, string in, int wi);
	~Team();


	void setColor(string val);
	void setNumOfMeals(int val);
	void setIngredients(string val);
	void setWinTotal(int val);
	void setCurNuOfMembers(int val);

	string getColor();
	int getNumOfMeals();
	string getIngredients();
	int getWinTotal();
	int getCurNuOfMembers();

    void addMember(Player mem);
	void status();
	void dispMembers();
	void dispPlayer(int number);
	void dispPlayer(string name);

};

#endif // TEAM_H_INCLUDED
