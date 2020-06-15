#ifndef DECK_HPP
#define DECK_HPP

#include <list>

#include "Card.hpp"

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

        /* Operateur */
        Deck& operator=(const Deck& d);
        Card* operator[](size_t i) const;

        /* Accesseurs */
        const int& getSize() const {return size;}

        /* méthode */
        void add_front(const Card* c);      // add a new Card at the beginning of the pile
        void add_back(const Card* c);       // add a new Card at the end of the pile
        Card* pick_up();                    // return the first Card of the pile
        void shuffle();

};

} // namespace src


#endif