//Αλέξανδρος Σαχίνης 8906 alexsach@ece.auth.gr
//Νικόλαος Πίγκας 9329 ngpigkas@ece.auth.gr
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//Cointains all the information and the functions needed
//to simulate a player in the game "Masterchef"
class Player {

	string name;
	int age;
	string gender;
	string employment;
	int fatigue;
	double popularity;
	double ability;
	int winTotal;


public:

	Player();
	Player(string na, int ag, string ge, string em);
	~Player();

	void setName(string val);
	void setAge(int val);
	void setGender(string val);
	void setEmployment(string val);
	void setFatigue(int val);
	void setPopularity(double val);
	void setAbility(double val);
	void setWinTotal(int val);

	string getName();
	int getAge();
	string getGender();
	string getEmployment();
	int getFatigue();
	double getPopularity();
	double getAbility();
	int getWinTotal();

	void work();
	void practice();
	void eat();
	void sleep();
	void socialize();
	void status();
};

#endif // PLAYER_H_INCLUDED
