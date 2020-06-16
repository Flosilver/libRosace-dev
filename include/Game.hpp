#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Deck.hpp"

#include <vector>

namespace rsc
{
class Game
{
    protected:
    
    public:
        int state;                                                  // game's state
        std::vector<Player*> players = std::vector<Player*>(4);     // list of 4 players
        Deck deck;                                                  // deck
        Deck discard;                                               // a deck were we put used cards
        // abstract field for different types of map

        Game(): deck(Deck()), discard(Deck()) {}
        ~Game() {}


        /* Operateurs */
        Game& operator=(const Game& g);

        /* accesseur */
        /*const int& getState() const {return state;}
        const Deck& getDeck() const {return deck;}
        const Deck& getDiscard() const {return discard;}
        const Player* getPlayer(int id) const {return players[id];}*/

        void setState(const int s) {state = s;}

        /* méthode */

};

} // namespace rsc

#endif
