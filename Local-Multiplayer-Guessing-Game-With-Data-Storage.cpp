#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
using namespace std;

class Session
{
    private:
        int ID;
        string name;
        int squad;
        int rounds;
    public:
        void setID(int ID);
        void setName(string name);
        void setSquad(int squad);
        void setRounds(int rounds);
        void setSession();

        int getID();
        string getName();
        int getSquad();
        int getRounds();
};

class Player
{
    private:
        int points = 0;
    public:
        void setPoints(int points);
        int getPoints();
};

int trial;
void trial_foo();
void game();
void menu();


int main()
{
    srand((unsigned)time(0));// Random random numbers
    menu();
    return 0;
}

void menu()
{
    int x;
    cout << "\n---------------" << endl;
    cout << "---MAIN MENU---" << endl;
    cout << "---------------" << endl;
    cout << "1. Start New Game" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> x;
    cin.ignore();
    switch(x)
    {
    case 1:
        game();
        break;
    case 0:
        cout << "\n\n!Game exitted!\n\n";
        break;
    default:
        cout << "\nInvalid choice!\n";
        menu();
        break;
    }
}

void Session::setID(int ID)
    { this->ID = ID; }

void Session::setName(string name)
    { this->name = name; }

void Session::setSquad(int squad)
    { this->squad = squad; }

void Session::setRounds(int rounds)
    { this->rounds = rounds; }

void Session::setSession()
{
    // input details
    int x = 1;
    string y;
    cout << "\n\n---------------" << endl;
    cout << "--NEW SESSION--" << endl;
    cout << "---------------" << endl;
    cout << "NAME: "; getline(cin,y); setName(y);
    cout << "NUMBER OF PLAYERS: ";
    do
    {
        if(x == 0)
        {
            cout << "Players can be 1 or more\nNUMBER OF PLAYERS: " << endl;
        }
        cin >> x;
    }while(x <= 0);
    setSquad(x);

    cout << "ROUNDS PER GAME: ";
    do
    {
        if(x == 0)
        {
            cout << "ROUNDS can be 1 or more\nROUNDS: " << endl;
        }
        cin >> x;
    }while(x <= 0);
    setRounds(x);

    /* This piece of code below is to have an auto_increment sessionID. File handling is used */
    ifstream sessionRead;
    sessionRead.open("sessionCount.txt");
    if(!sessionRead)
    {
        cout << endl << "File 'sessionCount' not Found" << endl;
    }
    else
    {
        cout << endl << "File 'sessionCount' opened succesfully" << endl;
        sessionRead >> x;
        sessionRead.close();
        x++;
    }

    ofstream sessionWrite;
    sessionWrite.open("sessionCount.txt");
    if(!sessionWrite)
    {
        cout << endl << "File 'sessionCount' not Found" << endl;
    }
    else
    {
        sessionWrite << x;
        sessionWrite.close();
    }
    setID(x);
}

int Session::getID()
    { return ID;}

string Session::getName()
    { return name; }

int Session::getSquad()
    { return squad; }

int Session::getRounds()
    { return rounds; }


void Player::setPoints(int points)
    { this->points = points; }

int Player::getPoints()
    { return points; }

void trial_foo()
{
    cin >> trial;
    // error checking
    if(trial > 100)
    {
        cout << endl << "Number should be between 0 - 100!" << endl;
        trial_foo();
    }
}

void game()
{
    // Creating session
    Session x;
    x.setSession();

    // Creating players
    Player *y;
    y = new Player[x.getSquad()];

    // Game
    cout << endl << endl;
    cout << "\n--GAME START--" << endl;
    cout << endl << endl;

    // gameplay
    // Loop for rounds
    for(int i = 0; i < x.getRounds(); i++)
    {
        // Set random number for the round
        int random_num = (rand() % 100) + 1;
        cout << "-Round " << i+1 << "-" << endl;

        // Loop for players
        for(int j = 0; j < x.getSquad(); j++)
        {
            int p = y[j].getPoints();

            cout << "\nPlayer " << j+1 << ":: ";

            // Player trial
            trial_foo();

            // Calculation
            int variance = pow(trial-random_num,2);

            // Awarding of points
            if (variance == 0)
            {
                p += 10;
                y[j].setPoints(p);
                cout << "\n10 points!" << endl;
                break; // When one wins... they round ends
            }
            else if(variance <= 3)
            {
                p += 7;
                y[j].setPoints(p);
                cout << "\n7 points!" << endl;
            }
            else if(variance <= 5)
            {
                p += 5;
                y[j].setPoints(p);
                cout << "\n5 points!" << endl;
            }
            else if(variance <= 10)
            {
                p += 3;
                y[j].setPoints(p);
                cout << "\n3 points!" << endl;
            }
            else
            {
                p += 0;
                y[j].setPoints(p);
                cout << "\n0 points!" << endl;
            }
        }

        cout << "\nThe answer is " << random_num << endl;
    }

    // writing and saving points into file
    ofstream points_p;
    string file_name = "score_"+ to_string(x.getID()) + x.getName() + ".txt"; // dynamic file name
    points_p.open(file_name);
    for(int k = 0; k < x.getSquad(); k++)
    {
        points_p <<"Player " << k+1 << ": " << y[k].getPoints() << endl;
    }
    points_p.close();

    // displaying scores
    cout << "\n--SCORES--";
    for(int m = 0; m < x.getSquad(); m++)
    {
        cout << "\nPlayer " << m+1 << ": " << y[m].getPoints();
    }
    cout << endl;
    menu();
}




