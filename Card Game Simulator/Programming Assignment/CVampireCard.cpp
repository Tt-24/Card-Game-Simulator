#include "CVampireCard.h"

using namespace std;

    void CVampireCard :: Activate(CPlayer& targetPlayer, CPlayer& friendlyPlayer)
    {
        if (targetPlayer.table.size() > 0)
        {
            // Get random index (for targeting)
            int targetIndex = Random(targetPlayer.table.size() - 1);

            // Get target card from table
            ICard* target = targetPlayer.table[targetIndex];

            // Subtract health
            target->health -= attack;

            // Deleting the Card once its defeated
            if (target->health <= 0)
            {
                cout << name << " attacks " << target->name << ". " << target->name << " killed " << endl;
                delete target;
                CardList::iterator deleteCardIterator;
                deleteCardIterator = targetPlayer.table.begin();
                deleteCardIterator += targetIndex;
                targetPlayer.table.erase(deleteCardIterator);
            }
            else
            {
                cout << name << " attacks " << target->name << ". " << target->name << " health now " << target->health << endl;
            }
        }
        else
        {
            // player is going to be attacked and its health will reduce.
            targetPlayer.health -= attack;
            
        }
        health++;
    }
