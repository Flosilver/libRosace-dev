#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Deck.hpp"

#include <vector>
#include <cstring>
#include <enet/enet.h>

#define NB_J_MAX 4

namespace rsc
{
typedef enum{North, East, South, West} player_t;     // [0,1,2,3]  number of the player according to it's position
class Game
{
    protected:
        ENetAddress address;
        ENetHost *server;
        ENetPeer *peer;
        ENetEvent event;

        char recMess[200];
        char mess[200];
        int nbConnectes = 0;
        bool isConnected[NB_J_MAX];
    
    public:
        int state;                                                  // game's state
        std::vector<Player*> players = std::vector<Player*>(NB_J_MAX);     // list of 4 players
        Deck deck;                                                  // deck
        Deck discard;                                               // a deck were we put used cards
        // abstract field for different types of map

        Game();
        ~Game();


        /* Operateurs */
        Game& operator=(const Game& g);

        /* accesseur */
        const int& getState() const;
        const Deck& getDeck() const;
        const Deck& getDiscard() const;
        const Player* getPlayer(int dir) const;

        void setState(const int s);

        /* méthode */
        static int initialize_game();
        int launch_game(int serv_addr_port);
        void sendBroadcast(char* mess); 
        void sendIsConnected(int dir);
        void sendIsAlreadyConnected(int dir);
};

} // namespace rsc

#endif
