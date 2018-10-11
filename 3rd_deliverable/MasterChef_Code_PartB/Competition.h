//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Competition{

protected:

    int id;
    string name;
    string winner;

public:

    Competition(){id=0; name=" "; winner=" ";}
    Competition(int id, string name){this->id=id; this->name=name; winner=" ";}
    ~Competition(){cout << "Competition object is being destroyed..." << endl;}

    int getID(){return id;}
    string getName(){return name;}
    string getWinner(){return winner;}

    void setID(int id){this->id=id;}
    void setName(string name){this->name=name;}
    void setWinner(string winner){this->winner=winner;}

    void status(){
        cout << "Competition id: "<< id << endl;
        cout << "Competition name: "<< name << endl;
        cout << "Winner of the Competition: "<< winner<< endl;
    }
};

#endif // COMPETITION_H_INCLUDED
