#include "CBlessCard.h"

using namespace std;

    void CBlessCard :: Activate(CPlayer& targetPlayer, CPlayer& friendlyPlayer)
    {
        if (targetPlayer.table.size() > 0)
        {
            // Bool random so that the bless can choose to use on either friendly or enemy minion
            if (BoolRandom() == true) // target enemy
            {
                if (BoolRandom() == true && targetPlayer.table.size() > 0)
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
                    // if the bless choose player randomly
                    targetPlayer.health -= attack;
                    cout << name << " attacks " << targetPlayer.name << " ." << " Health now " << targetPlayer.health << endl;
                }
            }
            else // target friendly
            {
                if (BoolRandom() == true && friendlyPlayer.table.size() > 0)
                {
                    // Get random index (for targeting)
                    int targetIndex = Random(friendlyPlayer.table.size() - 1);

                    // Get target card from wizard table
                    ICard* target = friendlyPlayer.table[targetIndex];

                    target->health += heal;
                    cout << name << " heals " << target->name << ". " << target->name << " health now " << target->health << endl;
                }
                else
                {
                    // if the bless choose player randomly
                    friendlyPlayer.health += heal;
                    cout << name << " heals " << friendlyPlayer.name << " ." << " Health now " << friendlyPlayer.health << endl;
                }
            }
        }
    }

