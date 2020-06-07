#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include "ICard.h"
#include "CPlayer.h"
#include "Rand.h"
#include "CMinionCard.h"
#include "CFireballCard.h"
#include "CLightingCard.h"
#include "CBlessCard.h"
#include "CVampireCard.h"

using namespace std;

class CGame
{
public:
    CPlayer sorceress;
    CPlayer wizard;
    int mCurrentRound;
    int mMaximumRounds;
    void Run();
};

