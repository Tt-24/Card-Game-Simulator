#include "CLightingCard.h"

using namespace std;

void CLightingCard :: Activate(CPlayer& targetPlayer, CPlayer& friendlyPlayer)
{
    for (CardList::iterator iter = targetPlayer.table.begin(); iter != targetPlayer.table.end(); iter++)
    {
        ICard* target = *iter;
        target->health--;
        if (target->health <= 0)
        {
            cout << name << " attacks " << target->name << ". " << target->name << " killed " << endl;
            delete target;
            iter = targetPlayer.table.erase(iter);
        }
        else
        {
            cout << name << " attacks " << target->name << ". " << target->name << " health now " << target->health << endl;
        }
    }

    // attack the target player
    targetPlayer.health--;
    cout << name << " attacks " << targetPlayer.name << ". " << " Health now " << targetPlayer.health << endl;

}
