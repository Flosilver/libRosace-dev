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
    pile.clear();
}

Deck& Deck::operator=(const Deck& d){
    /*for(list<sp_Card>::const_iterator it = d.pile.begin() ; it != d.pile.end() ; ++it){
        pile.push_back(*it);
    }*/
    pile.clear();
    for (const sp_Card& spc : d.pile){
        pile.push_back(make_shared<Card> (Card(*spc)));
    }
    size = pile.size();

    return *this;
}

sp_Card& Deck::operator[](size_t i){
    list<sp_Card>::iterator it = pile.begin();
    advance(it, i);
    // If the indicator of the asked Card is bigger than the size of the pile, then the last Card is returned.
    if(i >= size){
        it = pile.end();
    }
    return *it;
}

void Deck::add(sp_Card c, int loc){
    
    list<sp_Card>::iterator it = pile.begin();
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

sp_Card Deck::pick_up(){
    if (pile.empty())
        return nullptr;
    sp_Card c = pile.front(); // renvoie par référence le premier élément
    pile.pop_front();
    return c;
}

void Deck::give_to(size_t i, Deck& d, int loc){
    if (pile.empty() || pile.size()-1 < i){
        cerr << "***ERROR: Deck::give_to() : No Card to give" << endl;
        return;
    }
    
    list<sp_Card>::iterator it = pile.begin();
    advance(it,i);
    sp_Card target = *it;
    pile.erase(it);


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


void Deck::shuffle(){
    if (!pile.empty()){
        int haz;
        //sp_Card temp;
        for ( sp_Card& spc : pile ){
            cout << "---\nspc: " << spc->getValue() << endl;
            haz = rand() % size;
            cout << "haz: " << haz << endl;
            cout << "(*this)[haz]: " << (*this)[haz]->getValue() << endl;
            //temp = (*this)[haz];
            //cout << "temp:" << temp->getValue() << endl;
            spc.swap((*this)[haz]);
            cout << "spc: " << spc->getValue() << endl;
            cout << "(*this)[haz]: " << (*this)[haz]->getValue() << endl;
            //cout << "temp:" << temp->getValue() << endl;

        }
    }
    else{
        cerr << "***ERROR: Deck::shuffle() : No card to shuffle" << endl;
    }
}