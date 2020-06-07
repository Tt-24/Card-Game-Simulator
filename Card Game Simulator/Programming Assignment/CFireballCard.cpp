#include "CFireballCard.h"

using namespace std;

void CFireballCard :: Activate(CPlayer& targetPlayer, CPlayer& friendlyPlayer)
{
    if (targetPlayer.table.size() > 0)
    {
        // Bool random so that the fireball can choose to attack either a minion or a player
        if (BoolRandom() == true)
        {
            // Get random index (for targeting)
            int targetIndex = Random(targetPlayer.table.size() - 1);

            // Get target card from table
            ICard* target = targetPlayer.table[targetIndex];

            target->health -= attack;

            // Deleting the Card once its defeated
            if (target->health <= 0)
            {
                cout << name << " attacks " << target->name << ". " << target->name << " killed " << endl;

                // deallocate memory 
                delete target;

                // erase pointer from deque 
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
            // if the fireball choose player randomly
            targetPlayer.health -= attack;
            cout << name << " attacks " << targetPlayer.name << " ." << " Health now " << targetPlayer.health << endl;
        }
    }
}