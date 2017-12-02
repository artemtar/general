#include "Player.h"

Player::Player(const string &_name) : name{_name}
{
}

inline void Player::setStatusActive()
{
    status = true;
}
inline void Player::setStatusInactuve()
{
    status = false;
}
inline bool Player::getStatus()
{
    return status;
}

//initilizing qiwinto player
QwintoPlayer::QwintoPlayer(QwintoScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}

void QwintoPlayer::inputBeforeRoll(RollOfDice& rd)
{
    if (getStatus())
    {
        rd.roll();
        //score(rd, Color c, pos);
    }
    else
    {
        cout << "Hey man, watcha gonna do with those dices?" << endl;
        cout << "1.Pass; 2.Some sweet input: ";
        int choice = 0;
        cin >> choice;
    }
}
void QwintoPlayer::inputAfterRoll(RollOfDice& rd)
{
    if (getStatus())
    {
        
    }
    else
    {
    }
}

//qwinto player ends

//qwixplayer intitialization
QwixPlayer::QwixPlayer(QwixScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}
void QwixPlayer::inputBeforeRoll(RollOfDice& rd)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
void QwixPlayer::inputAfterRoll(RollOfDice& rd)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
//qwixpalyer ends
int main()
{
    //test
}