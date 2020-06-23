#include "Game.hpp"

using namespace rsc;

/* Constructeur */
Game::Game(){
    deck = Deck();
    discard = Deck();
}

/* Destructeur */
Game::~Game() {}

/* Operateur */
Game& Game::operator=(const Game& g){
    deck = g.deck;
    discard = g.discard;
    state = g.state;
    players = g.players;

    return *this;
}

/* Accesseurs */
const int& Game::getState() const {
    return state;
}

const Deck& Game::getDeck() const {
    return deck;
}

const Deck& Game::getDiscard() const {
    return discard;
}

const Player* Game::getPlayer(int dir) const {
    return players[dir];
}

void Game::setState(const int s) {
    state = s;
}

int Game::initialize_game(){
    printf("enet_initialize()\n");

	if (enet_initialize () != 0)
	{
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        return 1;   // FAILURE
    }
    return 0;   // SUCCESS
}

void Game::launch_game(int serv_addr_port){
    address.host = ENET_HOST_ANY;

	address.port = serv_addr_port;
	printf("enet_host_create()\n");

	server = enet_host_create (& address, NB_J_MAX, 2, 0, 0);
	if (server == NULL)
	{
       		fprintf (stderr, 
			"An error occurred while trying to create an ENet server host.\n");
       		exit (EXIT_FAILURE);
    	}
}

void Game::sendBroadcast(char *mess){
    char buffer[256];

	//for (int i=0;i<12;i++)
	for (int i=0;i<8;i++)
		buffer[i]=0;
	//buffer[8]=1;
	buffer[8]=4;

	int len=strlen(mess);
	int cpt=0;
	for (cpt=0;cpt<len;cpt++)
		buffer[9+cpt]=mess[cpt];
	buffer[9+cpt]=0;

	printf("len=%d %s\n",len,mess);

	ENetPacket * packet = enet_packet_create (buffer, 10+len, ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast (server, 1, packet);
}

void Game::sendIsConnected(int dir){
    printf("%d est connecte\n",dir);
}

void Game::sendIsAlreadyConnected(int dir){
    printf("%d est déjà connecte\n",dir);
}