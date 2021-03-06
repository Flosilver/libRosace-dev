#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include <memory>


namespace rsc
{

class Player
{
    protected:
        int dir;                 // player ID 0,1,2,3 / North, East, South, West
        bool connected;

    public:
        Player();
        Player(int aDir);
        ~Player();

        /* Operateurs */
        Player& operator=(const Player& p);

        /* accesseur */
        const int& getDir() const;
        const bool& isConnected() const;

        /* méthode */
        void login();
        void logout();
};

typedef std::shared_ptr<Player> sp_player;

} // namespace rsc

#endif
