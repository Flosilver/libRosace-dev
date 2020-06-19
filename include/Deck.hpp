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
#include <memory>

#include "Card.hpp"

using namespace std;



namespace rsc
{
/* class's constant which serv in argument of some methods to define 
if we manipule a Card in the front or in back of the Deck*/
/*#define TOP 0     
#define BOTTOM 1
#define MID 2
#define RAND 3*/
typedef enum{TOP, BOTTOM, MID, RAND} loc_t;

typedef shared_ptr<Card> sp_Card;
    
class Deck
{
    protected:
        size_t size;
        list<sp_Card> pile;

    public:
        Deck();//: size(0) {}
        Deck(const Deck& d);

        ~Deck();

        /* Operateur */
        Deck& operator=(const Deck& d);
        sp_Card& operator[](size_t i);

        /* Accesseurs */
        const int& getSize() const;// {return size;}

        /* méthode */
        void add(sp_Card c, int loc);             // Add a new Card at the beginning of the pile
        sp_Card pick_up();                     // Return the first Card of the pile
        void give_to(size_t i, Deck& d, int loc);   // Trade the Card with the id = aId and give it to the front of the Deck in argument
        void shuffle();                      // Shuffle the pile

};

} // namespace src


#endif