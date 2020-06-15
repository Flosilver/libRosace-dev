#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <list>

namespace rsc
{
class Game
{
    protected:
        std::vector<Player*> players(4);    // list of 4 players
        Deck deck;                          // deck
        Deck discard;                       // a deck were we put used cards
        // abstract field for different types of map


    public:
        int state;                          // game's state

        Game(): deck(Deck()), discard(Deck()) {}


        /* Operateurs */

        /* accesseur */
        const int& getState() const {return state;}
        const Deck& getDeck() const {return deck;}
        const Deck& getDiscard() const {return discard;}
        const Player& getPlayer(int id) const {return &players[id];}

        void setState(const int s) {state = s;}

        /* méthode */

};

} // namespace rsc

#endif
