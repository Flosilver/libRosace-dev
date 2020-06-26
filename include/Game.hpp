#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Deck.hpp"

#include <vector>
#include <cstring>
#include <iostream>
#include <enet/enet.h>

#define NB_J_MAX 4

namespace rsc
{
typedef enum{North, East, South, West} player_t;     // [0,1,2,3]  number of the player according to it's position
typedef std::shared_ptr<Player> sp_player;

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
        
    
    public:
        int state;                                                          // game's state
        std::vector<sp_player> players = std::vector<sp_player>(NB_J_MAX);  // list of 4 players
        // abstract field for different types of map

        Game();
        ~Game();


        /* Operateurs */
        Game& operator=(const Game& g);

        /* accesseur */
        const int& getState() const;
        const sp_player getPlayer(int dir) const;
        void setState(const int s);

        /* méthode */
        static void initialize_server();
        void launch(int serv_addr_port);
        void sendBroadcast(char* mess); 
        const bool& isConnected(int dir) const;

        virtual void handleIncomingMessage() = 0;
};

} // namespace rsc

#endif
