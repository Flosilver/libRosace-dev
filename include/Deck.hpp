/*
    Deck represent a pile of Cards. 
    It can be manipulated by the top or the bottom. The TOP is define as the first card visible
    on the Deck, the BOTTOM as the last one. Moreover, TOP correspond to the iterator begin() of
    the pile while BOTTOM correspond to the end() iterator.
*/

#ifndef DECK_HPP
#define DECK_HPP


#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Card.hpp"

using namespace std;
//using namespace rsc;



namespace rsc
{
class Card;

/* class's constant which serv in argument of some methods to define 
if we manipule a Card in the front or in back of the Deck*/
#define TOP 0     
#define BOTTOM 1
#define MID 2
#define RAND 3
    
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
        const int& getSize() const;// {return size;}

        /* méthode */
        void add(Card* c, int loc);             // Add a new Card at the beginning of the pile
        //void add_bottom(Card* c);              // Add a new Card at the end of the pile
        Card* pick_up();                     // Return the first Card of the pile
        void give_to(size_t i, Deck& d, int loc);   // Trade the Card with the id = aId and give it to the front of the Deck in argument
        //void give_to_bottom(int aId, Deck& d);    // Trade the Card with the id = aId and give it to the back of the Deck in argument 
        void shuffle();                      // Shuffle the pile

};

} // namespace src


#endif