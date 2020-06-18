#ifndef ROSACE_HPP
#define ROSACE_HPP

#include <memory>

#include "Vector2.hpp"
#include "Vector3.hpp"

#include "IMovable.hpp"

#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Pawn.hpp"
#include "Game.hpp"

namespace rsc{
typedef enum{North, East, South, West} player_t;     // [0,1,2,3]  number of the player according to it's position
typedef shared_ptr<Card> sp_Card;
}

#endif