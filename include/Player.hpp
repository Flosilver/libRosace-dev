#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Vector2.hpp"
#include "Deck.hpp"
#include "Pawn.hpp"


namespace rsc
{
class Player
{
    protected:
        std::string name;       // player name
        int id;                 // player ID 0,1,2,3
        Pawn pawn;              // player's pawn
        Deck hand;              // player's hand

    public:
        Player();
        Player(std::string n);
        Player(std::string n, int aId, Pawn& pa);
        Player(std::string n, int aId, Deck& d);
        Player(std::string n, int aId, Pawn& pa, Deck& d);
        ~Player();

        /* Operateurs */
        Player& operator=(const Player& p);

        /* accesseur */
        const std::string& getName() const;
        const int& getId() const;
        const Pawn& getPawn() const;
        const Vect2f& getPawnPosition() const;
        const Deck& getHand() const;

        /* méthode */
        void login();
        void logout();
        void movePawn(const Vect2f& v);
        void movePawnTo(const Vect2f& v);
};

} // namespace rsc

#endif
