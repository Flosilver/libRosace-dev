#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>


namespace rsc
{
class Player
{
    protected:
        std::string name;       // player name
        int dir;                 // player ID 0,1,2,3 / North, East, South, West
        bool connected;

    public:
        Player();
        Player(std::string n, int aDir);
        ~Player();

        /* Operateurs */
        Player& operator=(const Player& p);

        /* accesseur */
        const std::string& getName() const;
        const int& getDir() const;
        const bool& isConnected() const;

        /* méthode */
        void login();
        void logout();
};

} // namespace rsc

#endif
