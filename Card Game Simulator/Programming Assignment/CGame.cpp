#include "CGame.h"

void CGame::Run()
{
    for (mCurrentRound = 1; mCurrentRound < mMaximumRounds; mCurrentRound++)
    {
        // every round
        cout << endl;
        cout << "Round " << mCurrentRound << endl;
        // putting information from deck into hand 
        if (sorceress.deck.size() <= 0)
        {
            cout << "sorceress has no cards. wizard wins" << endl;
            system("pause");
        }
        cout << "Sorceress draws " << sorceress.deck.front()->name << endl;
        sorceress.hand.push_front(sorceress.deck.front());

        // deleting the information from the deck to look like it moved from the deck to hand 
        sorceress.deck.pop_front();

        // Selecting a random card from hand
        int randomSorceressCardIndex = Random(sorceress.hand.size() - 1);
        ICard* SorceressCardInHand = sorceress.hand[randomSorceressCardIndex];

        //if card is minion
        if (SorceressCardInHand->type == 1 || SorceressCardInHand->type == 5 || SorceressCardInHand->type == 9) // minions
        {
            // place card from hand to table
            sorceress.table.push_back(SorceressCardInHand);
            cout << "sorceress plays " << SorceressCardInHand->name << endl;
            // deleting the information from the hand to look like it moved from hand to table
            CardList::iterator iterator;
            iterator = sorceress.hand.begin();
            iterator += randomSorceressCardIndex;
            sorceress.hand.erase(iterator);
        }
        else if (SorceressCardInHand->type == 2 || SorceressCardInHand->type == 3 || SorceressCardInHand->type == 4) // spells
        {
            // spell attacks all the cards on the table
            SorceressCardInHand->Activate(wizard, sorceress);

            // lighting is deleted once been used 
            delete SorceressCardInHand;

            // erase pointer from deque
            CardList::iterator deleteSpellCardIterator;
            deleteSpellCardIterator = sorceress.hand.begin();
            deleteSpellCardIterator += randomSorceressCardIndex;
            sorceress.hand.erase(deleteSpellCardIterator);
        }

        // Display cards
        cout << "Cards on table: ";
        for (auto& card : sorceress.table)
        {
            cout << " " << card->name << "(" << card->health << ")" << ",";
        }
        for (auto& card : wizard.table)
        {
            cout << " " << card->name << "(" << card->health << ")" << ",";
        }
        cout << endl;

        // sorceress attacks with each card in its table
        for (auto& card : sorceress.table)
        {
            // Attack card
            card->Activate(wizard, sorceress);
        }

        // End turn
        cout << endl;

        // putting information from deck into hand
        if (wizard.deck.size() <= 0)
        {
            cout << "wizard has no cards. sorceress wins" << endl;
            system("pause");
        }
        cout << "Wizard draws " << wizard.deck.front()->name << endl;
        wizard.hand.push_front(wizard.deck.front());
        // deleting the information from the deck to lock ilke it moved from the deck to hand 
        wizard.deck.pop_front();
        // Selecting a random
        int randomWizardCardIndex = Random(wizard.hand.size() - 1);
        ICard* WizardCardInHand = wizard.hand[randomWizardCardIndex];

        if (WizardCardInHand->type == 1 || WizardCardInHand->type == 5 || WizardCardInHand->type == 9)
        {
            wizard.table.push_back(WizardCardInHand);
            // deleting the information from the hand to look like it moved from hand to table 
            cout << "wizard plays " << WizardCardInHand->name << endl;
            CardList::iterator wizardIterator;
            wizardIterator = wizard.hand.begin();
            wizardIterator += randomWizardCardIndex;
            wizard.hand.erase(wizardIterator);
        }
        else if (WizardCardInHand->type == 2 || WizardCardInHand->type == 3 || WizardCardInHand->type == 4)
        {
            // Attack card
            WizardCardInHand->Activate(sorceress, wizard);

            // fireball is deleted once been used 
            delete WizardCardInHand;

            // erase pointer from deque
            CardList::iterator deleteSpellIterator;
            deleteSpellIterator = wizard.hand.begin();
            deleteSpellIterator += randomWizardCardIndex;
            wizard.hand.erase(deleteSpellIterator);
        }

        // Display cards
        cout << "Cards on table: ";
        for (auto& card : sorceress.table)
        {
            cout << " " << card->name << "(" << card->health << ")" << ",";
        }
        for (auto& card : wizard.table)
        {

            cout << " " << card->name << "(" << card->health << ")" << ",";
        }
        cout << endl;

        // wizard attacks with each card in its table 
        for (auto& wizardCard : wizard.table)
        {
            wizardCard->Activate(sorceress, wizard);
        }

        // if any of the players health is less than or equal to zero than the other player wins 
        if (sorceress.health <= 0 || wizard.health <= 0)
        {
            cout << endl;
            cout << "game over" << endl << endl;
            if (sorceress.health <= 0)
            {
                cout << "Wizard Wins" << endl << endl;
            }
            else
            {
                cout << "Sorceress Wins" << endl << endl;
            }
            break;
        }
    }
}