#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "ICard.h"
#include "CPlayer.h"
#include "Rand.h"

using namespace std;

class CBlessCard : public ICard
{
    void Activate(CPlayer& targetPlayer, CPlayer& friendlyPlayer);
   
};


