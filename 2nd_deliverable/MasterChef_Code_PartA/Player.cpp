//Αλέξανδρος Σαχίνης 8906 alexsach@ece.auth.gr
//Νικόλαος Πίγκας 9329 ngpigkas@ece.auth.gr
#include "Player.h"

using namespace std;

//Constructors-Destructors

Player::Player(){
	name=" ";
	age=0;
	gender=" ";
	employment=" ";
	fatigue=0;
	popularity=50;
	ability= rand() % 81;
	winTotal=0;
}

Player::Player(string na, int ag, string ge, string em){
	name=na;
	age=ag;
	gender=ge;
	employment=em;
	fatigue=0;
	popularity=50;
	ability=rand() % 81;
	winTotal=0;
}

Player::~Player(){
	cout << "Player object with name \"" << name << "\" is destroyed." << endl;
}


//Setters

void Player::setName(string val){
	name=val;

}

void Player::setAge(int val){
	age=val;

}

void Player::setGender(string val){
	gender=val;

}

void Player::setEmployment(string val){
	employment= val;

}

void Player::setFatigue(int val){
	fatigue= val;

}

void Player::setPopularity(double val){
	popularity= val;

}

void Player::setAbility(double val){
	ability= val;

}

void Player::setWinTotal(int val){
	winTotal= val;

}


//Getters

string Player::getName(){
	return name;
}

int Player::getAge(){
	return age;
}

string Player::getGender(){
	return gender;
}

string Player::getEmployment(){
	return employment;
}

int Player::getFatigue(){
	return fatigue;
}

double Player::getPopularity(){
	return popularity;
}

double Player::getAbility(){
	return ability;
}

int Player::getWinTotal(){
	return winTotal;
}


//Rest of the functions

//Increaces randomly the fatigue(+20-40 absolutely) and the
//ability (+5%), while ensuring they both stay <=100
void Player::work(){
	fatigue = fatigue + ( rand() % 21 ) + 20;
	fatigue = (fatigue >=100)? 100: fatigue;
	ability = (5 * ability)/100 + ability;
	ability = (ability >= 100)? 100: ability;
}

//Randomly changes the popularity of a player by +-20%
//while ensuring it stays between [0,100]
void Player::socialize(){
	popularity = (popularity * ((rand() % 21 ) -10))/100 + popularity;
	popularity = (popularity <=0)? 0: popularity;
	popularity = (popularity >=100)? 100: popularity;
}

//Increases the ability by +5% while ensuring it stays <=100
void Player::practice(){
	ability = (5 * ability)/100 + ability;
	ability = (ability >= 100)? 100: ability;
}

//Sets the fatigue to 0
void Player::sleep(){
	fatigue= fatigue * 0;
}

void Player::eat(){

	cout << "Hmmm...This meal was delicious"<< endl;
}

//Displays the details of a player
void Player::status(){
    cout << "The details of the player are:"<< endl;
    cout << "Name: "<< name << endl;
    cout << "Age: "<< age << endl;
    cout << "Gender: "<< gender << endl;
    cout << "Employment: "<< employment << endl;
    cout << "Fatigue: " << fatigue << endl;
    cout << "Popularity: "<< popularity << endl;
    cout << "Ability: "<< ability << endl;
    cout << "Wins: "<< winTotal << endl;
}
