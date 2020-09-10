#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Deck.hpp"

#include <vector>
#include <memory>
#include <cstring>
#include <iostream>
#include <ctime>
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

        char recMess[200];
        char mess[200];
        int nbConnectes = 0;
        
    
    public:
        int state;                                   // game's state
        ENetEvent event;

        Game();
        virtual ~Game();


        /* Operateurs */
        
        Game& operator=(const Game& g);

        /* accesseur */

        const int& getState() const;
        void setState(const int s);

        /* méthode */

        static void initialize_server();
        void launch(int serv_addr_port);
        void sendBroadcast(char* mess); 
        const int game_host_service();
        void receive_event();

        virtual void handleIncomingMessage() = 0;
};

} // namespace rsc

#endif
