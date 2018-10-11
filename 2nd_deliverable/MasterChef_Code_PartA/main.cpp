//Αλέξανδρος Σαχίνης 8906 alexsach@ece.auth.gr
//Νικόλαος Πίγκας 9329 ngpigkas@ece.auth.gr
#include "Team.h"
#include <time.h>

using namespace std;

//Function prototypes
void addPlayerToTeam();
void displayTeamDetails();
void displayPlayer();
int insertAge();
string insertGender();
string insertTeam();

//Create the two teams as global variables, so the changes
//to them throughout the whole program can be saved
Team blue("Blue", 0, " ", 0);
Team red("Red", 0, " ", 0);

//Runs an iterative menu untill the user decides to exit the programm
int main(){
    srand(time(NULL));
    bool quit=false;
    do{
        int input;
        cout << "Press 1 if you want to add a player on a team. "<<endl;
        cout << "Press 2 if you want to display the details of a team."<<endl;
        cout << "Press 3 if you want to display the details of a team's player."<<endl;
        cout << "Press anything else  if you want to Exit."<<endl;
        cin >> input;
        switch(input){
        case 1:
            addPlayerToTeam();
            break;
        case 2:
            displayTeamDetails();
            break;
        case 3:
            displayPlayer();
            break;
        default:
            cout << "Exiting..."<<endl;
            quit=true;
        }
    }while(!quit);

    return 0;
}

void addPlayerToTeam(){
    //If both the teams are full, dont let the user add any players
    if(red.getCurNuOfMembers()==11 && blue.getCurNuOfMembers()==11){
        cout << "Both teams are full. You can not add more players!" <<endl;
        return;
    }
    string name, gender, employment,team;
    int age;
    cout << "Insert the name of the player you want to add."<<endl;
    getline(cin, name);
    getline(cin, name);
    cout << "Insert the age of "<<name<< " (>=18)."<<endl;
    age=insertAge();
    cout << "Insert the gender of "<<name<< " (male/female)."<<endl;
    gender=insertGender();
    cout << "Insert the employment of "<<name<< "."<<endl;
    getline(cin, employment);
    getline(cin, employment);
    //If the red team is full, insert the player into the blue team
    if(red.getCurNuOfMembers()==11){
        cout << "Red team is full! Player added on Blue team."<<endl;
        team="blue";
    }
    //If the blue team is full, insert the player into the red team
    else if(blue.getCurNuOfMembers()==11){
        cout << "Blue team is full! Player added on Red team."<<endl;
        team="red";
    }
    //If none of the teams are full, let the user decide
    else{
        cout <<"In which team do you want to add "<<name<<"? (blue/red)"<<endl;
        team=insertTeam();
    }
    //Creation of object player
    Player p(name, age, gender, employment);
    //Insertion of the player into the right team
    if(team=="blue"){
        blue.addMember(p);
    }else{
        red.addMember(p);
    }

}

//Reads and returns the age, ensuring it is >=18
int insertAge(){
    int age;
    cin >> age;
    while(age<18){
        cout<<"Age must be >=18. Insert again, please."<<endl;
        cin >> age;
    }
    return age;
}

//Reads and returns the gender, ensuring it is "male" or "female"
string insertGender(){
    string gender;
    cin >> gender;
    while(gender!="male" && gender!="female"){
        cout << "Gender must be \"male\" or \"female\". Insert again, please."<<endl;
        cin >> gender;
    }
    return gender;
}

//Reads and returns the team, ensuring it is "blue" or "red"
string insertTeam(){
    string team;
    cin >> team;
    while(team!="blue" && team!="red"){
        cout<<"You must choose between \"blue\" or \"red\". Insert again, please."<<endl;
        cin >> team;
    }
    return team;
}

//Displays the details of a team, based on the users selection
void displayTeamDetails(){
    string team;
    cout << "Which team's details do you want to be displayed? (blue/red)"<<endl;
    team=insertTeam();
    if (team=="blue"){
        blue.status();
    }else{
        red.status();
    }
}

//Searches for a player in a team,based on the user selection and displays his details
void displayPlayer(){
    string team, name;
    int input, number;
    //User selects the team in which the player search will be held
    cout << "From which team do you want to search a player? (blue/red)" <<endl;
    team=insertTeam();
    if (team=="blue"){
        blue.status();
    }else{
        red.status();
    }
    //Users choses between name and number search of a player
    cout << "Press 1 if you want to search the player by name. "<<endl;
    cout << "Press 2 if you want to search the player by number."<<endl;
    cout << "Press anything else  if you want to Cancel."<<endl;
    cin >> input;
    switch(input){
    case 1:
        cout << "Insert the name of the player whose details you want to see."<<endl;
        getline(cin, name);
        getline(cin, name);
        if(team=="blue"){
            blue.dispPlayer(name);
        }else{
            red.dispPlayer(name);
        }
        break;
    case 2:
        cout << "Insert the number of the player whose details you want to see."<<endl;
        cin >> number;
        if(team=="blue"){
            blue.dispPlayer(number);
        }else{
            red.dispPlayer(number);
        }
        break;
    default:
        cout << "Cancelling..."<< endl;
    }
}
