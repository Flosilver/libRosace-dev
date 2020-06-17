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

const Player* Game::getPlayer(int id) const {
    return players[id];
}

void Game::setState(const int s) {
    state = s;
}





