#include "Deck.hpp"

using namespace rsc;
using namespace std;

Deck::Deck(){
    size = 0;
}

Deck::Deck(const Deck& d){
    *this = d;
}

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

const Card* Deck::operator[](size_t i) const{
    list<Card*>::const_iterator it = pile.begin();
    advance(it, i);
    if(i >= size){
        it = pile.end();
    }
    return *it;
}

void Deck::add(Card* c, int loc){
    
    list<Card*>::iterator it = pile.begin();
    switch(loc){
        case TOP:
            pile.push_front(c);
            size = pile.size();
            break;

        case BOTTOM:
            pile.push_back(c);
            size = pile.size();
            break;

        case MID:
            advance(it,size/2);
            pile.insert(it,c);
            size = pile.size();
            break;

        case RAND:
            advance(it,rand()%(size));
            pile.insert(it,c);
            size = pile.size();
            break;

        default:
            cerr << "***ERROR: Deck::add() : Wrong location" << endl;
            break;
    }
}

/*void Deck::add_bottom(Card* c){
    pile.push_back(c);
    size++;
}*/

Card* Deck::pick_up(){
    if (pile.size() == 0){
        return NULL;
    }

    list<Card*>::iterator it = pile.begin();
    pile.pop_front();
    return *it;
}

void Deck::give_to(int aId, Deck& d, int loc){
    if (pile.size() == 0 || pile.size()-1 < aId){
        cerr << "***ERROR: Deck::give_to() : No Card to give" << endl;
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
        switch(loc){
            case TOP:
                d.add(target, TOP);
                break;

            case BOTTOM:
                d.add(target, BOTTOM);
                break;

            case MID:
                d.add(target, MID);
                break;

            case RAND:
                d.add(target, RAND);
                break;

            default:
                cerr << "***ERROR: Deck::give_to() : Wrong location" << endl;
                break;
        }
    }
}

/*void Deck::give_back(int aId, Deck& d){
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
}*/

void Deck::shuffle(){
    
}