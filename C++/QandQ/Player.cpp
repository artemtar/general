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

void QwintoPlayer::inputBeforeRoll(RollOfDice &)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
void QwintoPlayer::inputAfterRoll(RollOfDice &)
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
void QwixPlayer::inputBeforeRoll(RollOfDice &)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
void QwixPlayer::inputAfterRoll(RollOfDice &)
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