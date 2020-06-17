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

        Game();
        ~Game() {}


        /* Operateurs */
        Game& operator=(const Game& g);

        /* accesseur */
        const int& getState() const;
        const Deck& getDeck() const;
        const Deck& getDiscard() const;
        const Player* getPlayer(int id) const;

        void setState(const int s);

        /* méthode */

};

} // namespace rsc

#endif
