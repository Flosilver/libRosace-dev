#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Vector2.hpp"


namespace rsc
{
class Player
{
    protected:
        std::string name; // player name
        int id;           // player ID 0,1,2,3
        Pawn p;           // player's pawn
        Deck hand;        // player's hand

    public:
        Player(std::string n): name(n), id(0), p(), hand() {}
        Player(std::string n, int identif, Pawn pa): name(n), id(identif), p(pa), hand(Deck()) {}
        Player(std::string n, int identif, Deck d): name(n), id(identif), p(Pawn()), hand(d) {}
        Player(std::string n, int identif, Pawn pa, Deck d): name(n), id(identif), p(pa), hand(d) {}
        ~Player() {}

        /* Operateurs */

        /* accesseur */
        const std::string getName() const {return name;}
        const int& getId() const {return id;}
        const Pawn& getPawn() const {return p;}
        const int& getPosition() const {return p.getPosition();}
        const Deck& getDeck() const {return Deck;}

        /* méthode */
        void login();
        void logout();
        void movePawn(const vect2f& v);
        void movePawnTo(const vect2f& v);
};

} // namespace rsc

#endif
