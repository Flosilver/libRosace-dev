#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>


namespace rsc
{
class Player
{
    protected:
        std::string name;       // player name
        int id;                 // player ID 0,1,2,3

    public:
        Player();
        Player(std::string n);
        Player(std::string n, int aId);
        ~Player();

        /* Operateurs */
        Player& operator=(const Player& p);

        /* accesseur */
        const std::string& getName() const;
        const int& getId() const;

        /* méthode */
        void login();
        void logout();
};

} // namespace rsc

#endif
