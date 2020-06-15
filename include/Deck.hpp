#ifndef DECK_HPP
#define DECK_HPP

#include <list>

#include "Card.hpp"
#include <iostream>

using namespace std;
//using namespace rsc;

namespace rsc
{
    
class Deck
{
    protected:
        int size;
        list<Card*> pile;

    public:
        Deck(): size(0) {}
        Deck(const Deck& d);

        ~Deck();

        /* Operateur */
        Deck& operator=(const Deck& d);
        Card* operator[](size_t i) const;

        /* Accesseurs */
        const int& getSize() const {return size;}

        /* méthode */
        void add_front(Card* c);            // Add a new Card at the beginning of the pile
        void add_back(Card* c);             // Add a new Card at the end of the pile
        Card* pick_up();                    // Return the first Card of the pile
        void give_front(int aId, Deck& d);  // Trade the Card with the id = aId and give it to the front of the Deck in argument
        void give_back(int aId, Deck& d);   // Trade the Card with the id = aId and give it to the back of the Deck in argument 
        void shuffle();                     // Shuffle the pile

};

} // namespace src


#endif