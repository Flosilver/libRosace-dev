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
        std::string name; // player name
        int id;           // player ID 0,1,2,3
        Pawn pawn;           // player's pawn
        Deck hand;        // player's hand

    public:
        Player(): name(""), id(0), pawn(), hand() {}
        Player(std::string n): name(n), id(0), pawn(), hand() {}
        Player(std::string n, int aId, Pawn& pa): name(n), id(aId), pawn(pa), hand(Deck()) {}
        Player(std::string n, int aId, Deck& d): name(n), id(aId), pawn(Pawn()), hand(d) {}
        Player(std::string n, int aId, Pawn& pa, Deck& d): name(n), id(aId), pawn(pa), hand(d) {}
        ~Player() {}

        /* Operateurs */
        Player& operator=(const Player& p);

        /* accesseur */
        const std::string& getName() const {return name;}
        const int& getId() const {return id;}
        const Pawn& getPawn() const {return pawn;}
        const Vect2f& getPosition() const {return pawn.getPosition();}
        const Deck& getHand() const {return hand;}

        /* méthode */
        void login();
        void logout();
        void movePawn(const Vect2f& v);
        void movePawnTo(const Vect2f& v);
};

} // namespace rsc

#endif
