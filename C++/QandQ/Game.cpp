#include "ScoreSheet.h"
#include "Player.h"
#include "Dices.h"
#include <iostream>
#include <vector>
#include <algorithm>

int inputCheckerForMain(int boundA, int boundB)
{
    int choice = -1;
    while (42)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
        if (!(choice < boundA) && !(choice > boundB))
            break;
        else
            cout << "Invalid input. Try again: ";
    }
    return choice;
}

bool findWinner(Player *p1, Player *p2)
{
    return *p1 > *p2;
}

int main()
{
    int gameVersion = -1;
    cout << "Please chose game" << endl;
    cout << "1. Qwinto" << endl;
    cout << "2. Qwixx" << endl;
    cout << "Input: ";
    gameVersion = inputCheckerForMain(1, 2);
    cout << endl;
    //get Number Of Players
    int numOfPlayers = -1;
    cout << " Please input the number of player that you want to have, minimum requerment is 2 : ";
    numOfPlayers = inputCheckerForMain(2, 6); //let 6 be the max
    cout << endl;
    vector<Player *> players; //to keep the players

    //poolimorphic part  is here, depending on game vertion,
    //we are having different players, after switch statement
    //the game should look the same for both game types
    switch (gameVersion)
    {
    case 1:
    {
        //create all required players and
        int count = 0;
        for (int i = 0; i < numOfPlayers; i++)
        {
            string tempName;

            cout << "What is the name of the player " << i + 1 << ": ";
            cin >> tempName;
            cout << endl;
            QwintoScoreSheet *tempScoreSheet = new QwintoScoreSheet{tempName};
            Player *tempPlayer = new QwintoPlayer{tempScoreSheet, tempName};
            players.push_back(tempPlayer);
            cout << "Player " << i + 1 << " with name : " << tempName << " is created." << endl;
            ++count;
        }
        cout << "LET THE GAMES BEGIN! " << count << endl; //this line, and custom distructor helped me to find the bug
    }
    break;

    case 2:
    {
        //locks for board in all players
        int *locks = new int[4];
        for (int i = 0; i < 4; ++i){
        *(locks + i) = 0;
        }
        int count = 0;
         for (int i = 0; i < numOfPlayers; i++)
        {
            string tempName;
            cout << "What is the name of the player " << i + 1 << ": ";
            cin >> tempName;
            cout << endl;
            QwixScoreSheet *tempScoreSheet = new QwixScoreSheet{tempName, locks};
            Player *tempPlayer = new QwixPlayer{tempScoreSheet, tempName};
            players.push_back(tempPlayer);
            cout << "Player " << i + 1 << " with name : " << tempName << " is created." << endl;
            cout << endl << *tempPlayer->sheet;
            ++count;
        }
            
    }
    break;
    }
     RollOfDice currentRoll{};// = *currentRollPtr;
     bool gameOver;
    //main loop will run till one of the boards is full
    while (1)
    {
        while(true){
        for (Player *currentPlayer : players)//to get turns of the players;
        {
            while (true)//the loop to be in the turn
            {
                cout << "The active player is " << currentPlayer->name << endl;
                currentPlayer->setStatusActive();
                int currentRollNumOfDices = -1;
                cout << "Please input the number of dices you want to roll as a number? ";
                //ask how many dices to roll
                if(gameVersion == 1){
                    cout << "(1..3) : ";
                    currentRollNumOfDices = inputCheckerForMain(1, 3);
                }
                else{
                    cout << "(1..6 for Qwix) : "; 
                    currentRollNumOfDices = inputCheckerForMain(1, 6);
                }

                //get the colours of the dices from the user and roll the dices with the selected collour
                int currentScore = *(currentRoll.roll(currentPlayer->inputBeforeRoll(currentRoll,currentRollNumOfDices)));//currentPlayer.roll(currentPlayer->inputBeforeRoll(currentRoll, currentRollNumOfDices));

                cout << "The roll gave " << currentScore << " points. " << endl;
                
                if (!(currentPlayer->sheet->checkForFail(&currentRoll,currentPlayer->sheet)))//danger but should be ok //current board only in thos scope
                {
                    ScoreSheet* currentboard = currentPlayer->getScoreSheet();
                    cout << *currentboard;
                //check if not fail
                    currentPlayer->inputAfterRoll(&currentRoll);
                     if (!(*(currentPlayer->sheet))){break;};//check if get out of the game
                }
                else{
                    currentPlayer->sheet->num_failed++;
                    cout<<currentPlayer->name<<", you have "<<currentPlayer->sheet->num_failed<<" fails."<<endl;
                    //checkif the game ends
                    if (!(*(currentPlayer->sheet))){break;};//check if get out of the game for 4 fails /CHECKED
                }
                for (Player *tempPlayer : players)
                {
                    if (tempPlayer == currentPlayer)
                        continue;//
                    bool wantToPutInScoreheet = -1;
                    cout << *tempPlayer; //print the scoresheet of the player we ask if wants to put result in scoresheet
                    cout << tempPlayer->name << ", do you want to put this roll in your scoresheet?(1 for yes, 0 for no) ";
                    wantToPutInScoreheet = inputCheckerForMain(0, 1);
                    if (wantToPutInScoreheet){tempPlayer->inputAfterRoll(&currentRoll);}

                    if (!(*(tempPlayer->sheet))){currentPlayer = tempPlayer;break;}
                }
                currentPlayer->setStatusInactuve();                
                break;
            }
            gameOver = !(*(currentPlayer->sheet));
          }
          if(gameOver){break;}
        }
        //checking if game is ended
        for (Player *p : players)
        {
            ScoreSheet &playersScoreSheet = *(p->getScoreSheet());
            if (!playersScoreSheet)
            {
                cout << "Game is ended on player" << p->name << endl;
                break;
            }
}
//game ended
//setting tottal score
   for_each(players.begin(), players.end(), [](Player *p) {ScoreSheet* s = p->getScoreSheet(); s->setTotal(); });
   //looking for winner
    sort(players.begin(), players.end(), findWinner);
    Player  *p1 = players.at(0);
    Player *p2 = players.at(1);
    //check for draw
     if(p1->getScoreSheet()->getScore() != p2->getScoreSheet()->getScore())
        {Player *winner = players.at(0);
        cout << endl << "The winner is: " << winner->name << "!" << endl;}//this is winner
        else {cout << endl << "There is a draw" << endl; }
        for (Player* p : players)
        cout << p->name << " has score of: " << (p->getScoreSheet())->getScore() << endl;  
break;
    }
}
