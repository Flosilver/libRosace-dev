#include "Deck.hpp"

using namespace rsc;
using namespace std;

Deck::~Deck(){
    for(list<Card*>::iterator it = pile.begin() ; it != pile.end() ; ++it){
        delete *it;
    }
    pile.clear();
}

Deck& Deck::operator=(const Deck& d){
    for(list<Card*>::const_iterator it = d.pile.begin() ; it != d.pile.end() ; ++it){
        pile.push_back(*it);
    }
    size = d.size;

    return *this;
}

void Deck::add_front(Card* c){
    pile.push_front(c);
    size++;
}

void Deck::add_back(Card* c){
    pile.push_back(c);
    size++;
}

Card* Deck::pick_up(){
    if (pile.size() == 0){
        return NULL;
    }

    list<Card*>::iterator it = pile.begin();
    pile.pop_front();
    return *it;
}

void Deck::give_front(int aId, Deck& d){
    if (pile.size() == 0){
        cout << "No Card to give" << endl;
        return;
    }

    Card* target = NULL;
    Card* pc;
    for(list<Card*>::iterator it = pile.begin() ; it != pile.end() ; ++it){
        pc = *it;
        if ( pc->getId() == aId ){
            target = *it;
            pile.erase(it);
            break;
        }
    }

    if(target != NULL){
        d.add_front(target);
    }
}

void Deck::give_back(int aId, Deck& d){
    if (pile.size() == 0){
        cout << "No Card to give" << endl;
        return;
    }

    Card* target = NULL;
    Card* pc;
    for(list<Card*>::iterator it = pile.begin() ; it != pile.end() ; ++it){
        pc = *it;
        if ( pc->getId() == aId ){
            target = *it;
            pile.erase(it);
            break;
        }
    }

    if(target != NULL){
        d.add_back(target);
    }
}