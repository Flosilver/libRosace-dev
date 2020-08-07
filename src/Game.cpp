#include "Game.hpp"

using namespace rsc;
using namespace std;

/* Constructeur */
Game::Game(){
	server = nullptr;
	peer = nullptr;


	state = 0;

	/*for (int i=0 ; i<NB_J_MAX ; i++){
		players[i] = make_shared<Player>();
	}*/
}

/* Destructeur */
Game::~Game() {
	cout << "***destructeur de Game" << endl;
	delete server;
	delete peer;

	cout << "***serveur et peer detruits" << endl;
	//players.clear();
	cout << "***ensemble des players détruits" << endl;

	cout << "***deinitialisation de enet" << endl;
	enet_deinitialize();
	cout << "\t***dest Game" << endl;
}

/* Operateur */
Game& Game::operator=(const Game& g){
	address = g.address;
	server = g.server;
	peer = g.peer;
	nbConnectes = g.nbConnectes;
	
    state = g.state;

    /*for (int i=0 ; i<NB_J_MAX ; i++){
		players[i] = make_shared<Player>(Player(*g.players[i]));
	}*/

    return *this;
}

/* Accesseurs */
const int& Game::getState() const {
    return state;
}

void Game::setState(const int s) {
    state = s;
}

/* First command in a main before the creation of a new Game */
void Game::initialize_server(){
    printf("enet_initialize()\n");
	
	srand(time(0));

	if (enet_initialize () != 0)
	{
        fprintf (stderr, "***ERROR: An error occurred while initializing ENet.\n");
        exit(EXIT_FAILURE);   // FAILURE
    }
}

void Game::launch(int serv_addr_port){
    address.host = ENET_HOST_ANY;

	address.port = serv_addr_port;
	printf("enet_host_create()\n");

	server = enet_host_create (& address, NB_J_MAX, 2, 0, 0);
	if (server == NULL)
	{
       		fprintf (stderr, 
			"***ERROR: An error occurred while trying to create an ENet server host.\n");
       		exit (EXIT_FAILURE);
    	}
}

void Game::sendBroadcast(char *mess){
    char buffer[256];

	//for (int i=0;i<12;i++)
	//merci M. Pecheux pour votre temps
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

const int Game::game_host_service(){
	return enet_host_service(server, &event, 0);
}

void Game::receive_event(){
	peer = event.peer;
	int idx=0;
	for (int i=9;i<(int)event.packet->dataLength;i++)
	{
		//printf("%c",(char)event.packet->data[i]);
		recMess[idx++]=(char)event.packet->data[i];
	}
	recMess[idx++]='\0';
	//printf("recMess=|%s|\n",recMess);
	cout << "\n[->] recMess=|" << recMess << "|" << endl;
	enet_packet_destroy (event.packet);
}