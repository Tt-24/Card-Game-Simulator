#pragma once
#include <string>
#include <deque>

class ICard;

using namespace std;

// typedef for cards
using CardList = deque<ICard*>;

// the player owns deck, hand, table
class CPlayer
{
public:
    string name;
    int health = 30;
    CardList deck;
    CardList hand;
    CardList table;
};
