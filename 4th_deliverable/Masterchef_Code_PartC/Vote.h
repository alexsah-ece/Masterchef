//Alexandros Sahinis 8906, alexsach@ece.auth.gr-6987892482
//Nikolaos Pigkas 9329, ngpigkas@ece.auth.gr-6970623440

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Vote{

    string voted;
    string reason;

public:

    Vote(){voted=" "; reason=" ";}
    Vote(string v, string r){voted=v; reason=r;}
    ~Vote(){cout << "Object Vote is destroyed." << endl;}

    string getVoted(){return voted;}
    string getReason(){return reason;}

    void setVoted(string v){voted=v;}
    void setReason(string r){reason=r;}
    void status(){
        cout << "Voted: " << voted << endl;
        cout << "Reason: " << reason << endl;
    }
};

#endif // VOTE_H_INCLUDED
