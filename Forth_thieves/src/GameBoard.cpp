
#include "CardTypes.h"
#include "CardStack.h"
#include <iostream>
#include <vector>
#include "GameBoard.h"
#include "Stack.h"
#include <stdexcept>


BoardT::BoardT(std::vector<CardT> deck){

  if (!(two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT()))){
    throw std::invalid_argument("can't construct");

  }

  else{

    this->T = tab_deck(std::vector<CardT>(deck.begin(), deck.begin() + 39));
    this->F = init_seq(8);
    this->D = CardStackT(std::vector<CardT>(deck.begin()+40, deck.end()));
    this->W = CardStackT();


  }
}

bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1 ){
  switch(c){
    case Tableau:
      if(!((is_valid_pos(Tableau, n_0)) && is_valid_pos(Tableau, n_1))){
        throw std::out_of_range("exceeded limit");
      }
      else{
        return valid_tab_tab(n_0, n_1);
      }

    case Foundation:
      if(!((is_valid_pos(Tableau, n_0)) && is_valid_pos(Foundation, n_1))){
        throw std::out_of_range("exceeded limit");
      }
      else{
        return valid_tab_foundation(n_0,n_1);
      }
    case Deck:
      return false;
    case Waste:
      return false;
  }
}

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n){
  if(W.size() == 0){
    throw std::invalid_argument("is not valid number");
  }
  else{
    switch(c){

      case Tableau:
        if(!(is_valid_pos(Tableau, n))){
          throw std::out_of_range("exceeded limit");
        }
        else{
          return valid_waste_tab(n);
        }
        break;
      case Foundation:
        if(!(is_valid_pos(Tableau, n))){
          throw std::out_of_range("exceeded limit");
        }
        else{
          return valid_waste_foundation(n);
        }
        break;
      case Deck:
        if (W.size() == 0){
          throw std::invalid_argument("wrong argument");
        }
        else{return false;}
        break;

      case Waste:
        return false;

    }

  }


}

bool BoardT::is_valid_deck_mv(){
  return D.size() > 0;
}

void BoardT::tab_mv(CategoryT c, unsigned int n_0, unsigned n_1){
  if (!(is_valid_tab_mv(c, n_0, n_1))){ throw std::invalid_argument("exceeded limit");}
  else{
    switch(c){
      case Tableau:
        T[n_1] = T[n_1].push(T[n_0].top());
        T[n_0] = T[n_0].pop();
        break;
      case Foundation:
        F[n_1] = F[n_1].push(T[n_0].top());
        T[n_0] = T[n_0].pop();
        break;
      case Deck:
        throw std::invalid_argument("cannot process deck");
      case Waste:
        throw std::invalid_argument("cannot procees waste");


    }
  }
}

void BoardT::waste_mv(CategoryT c, unsigned int n){
  if((is_valid_waste_mv(c,n))){throw std::invalid_argument("invalid");}
  else{
    switch (c){
      case Tableau:
        W = W.pop();
        T[n] = T[n].push(W.top());
      case Foundation:
        W = W.pop();
        F[n] = F[n].push(W.top());
      case Deck:
        break;
      case Waste:
        break;
    }
  }
}

void BoardT::deck_mv(){
  if (!(is_valid_deck_mv())){throw std::invalid_argument("exceeded limit");}
  else{D = D.pop();
  W = W.push(D.top());}
}

CardStackT BoardT::get_tab(unsigned int i){
  if(!(is_valid_pos(Tableau, i))){throw std::out_of_range("you exceeded limit");}
  else{
    return T[i];
  }
}

CardStackT BoardT::get_foundation(unsigned int i){
  if(!(is_valid_pos(Foundation, i))){throw std::out_of_range("you passed the range");}
  else{
    return F[i];
  }
}

CardStackT BoardT::get_deck(){
  return D;
}

CardStackT BoardT::get_waste(){
  return W;
}

bool BoardT::valid_mv_exists (){
  bool valid_tab_mv;
  bool valid_waste_mv;
  CategoryT category[] = {Tableau, Foundation};
  for (CategoryT i : category){
    for(unsigned j = 0; j < 10; j++){
      for (unsigned k = 0; k < 10; k++){
        if (is_valid_pos(Tableau, j) && is_valid_pos(i,k)){
          valid_tab_mv = is_valid_tab_mv(i, j, k);
          return valid_tab_mv;
        }
      }
      if(is_valid_pos(i, j)){
        valid_waste_mv = is_valid_waste_mv(i, j);
        return valid_waste_mv;
      }
    }
  }
  return is_valid_deck_mv();
}

bool BoardT::is_win_state(){
  bool win = false;
  for (int i = 0; i <= 7; i++){
    if(F[i].size() > 0 && F[i].top().r == KING){
      win = true;
    }
    else{
      win = false;
      break;
    }
  return win;
  }
}

//local functions start here
//init_seq
SeqCrdStckT BoardT::init_seq(unsigned int n){

  SeqCrdStckT s;
  for (int i = 0; i < n; i++){
    s.push_back(CardStackT());
  }
  return s;
}

//tab_deck
SeqCrdStckT BoardT::tab_deck(std::vector<CardT> deck){
  for (int i = 0; i <= 9 ; i++){
    std::vector <CardT> vec = std::vector <CardT>(deck.begin() + 4*i, deck.begin() + 4*(i+1));
    CardStackT newDeck = CardStackT(vec);
    T.push_back(newDeck);
  }
  return T;
}


bool BoardT::is_valid_pos(CategoryT c, unsigned int n){
  switch(c){
    case Tableau:
      for(int i = 0; i <= 9; i++){
        if (n == i){
          return true;
        }
      }
    case Foundation:
      for(int i = 0; i <= 7; i++){
        if (n == i){
          return true;
        }
      }
    case Deck:
        break;
    case Waste:
        break;
    default:
      return false;
  }
}
bool BoardT::valid_tab_tab(unsigned int n_0, unsigned int n_1){
  if(T[n_0].size() > 0){
    if(T[n_1].size() > 0){
      return tab_placeable(T[n_0].top(), T[n_1].top());
    }
    else if(T[n_1].size() == 0){return true;}
  }
  else if(T[n_0].size() == 0){
    if(T[n_1].size() > 0){
      return false;
    }
    else if(T[n_1].size() == 0){return false;}
  }
}
bool BoardT::valid_tab_foundation(unsigned int n_0, unsigned int n_1){
  if(T[n_0].size() > 0){
    if(F[n_1].size() > 0){
      return foundation_placeable(T[n_0].top(), F[n_1].top());
    }
    else if(F[n_1].size() == 0){return (T[n_0].top().r == ACE);}
  }
  else if(T[n_0].size() == 0){
    if(F[n_1].size() > 0){
      return false;
    }
    else if(F[n_1].size() == 0){return false;}
  }
}
bool BoardT::valid_waste_tab(unsigned int n){
  if(T[n].size() > 0){
    return(tab_placeable(W.top(),T[n].top()));
  }
  else if(T[n].size() == 0){
    return true;
  }
}
bool BoardT::valid_waste_foundation(unsigned int n){
  if(F[n].size() > 0){
    return(tab_placeable(W.top(),F[n].top()));
  }
  else if(F[n].size() == 0){
    return (W.top().r == ACE);
  }
}
bool BoardT::tab_placeable(CardT c, CardT d){
  return ((c.s == d.s) && (c.r == (d.r - 1) ));
}
bool BoardT::foundation_placeable(CardT c, CardT d){
  return ((c.s == d.s) && (c.r == (d.r + 1)));
}
//count cards
unsigned int BoardT::cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W, CardT c){
  return cnt_cards_seq(T, c) + cnt_cards_seq(F, c) + cnt_cards_stack(D, c) + cnt_cards_stack(W, c);
}
//count cards Stack
unsigned int BoardT::cnt_cards_stack(CardStackT s, CardT c){
  std::vector<CardT> S = s.toSeq();
  unsigned int count = 0;
  for (int i = 0; i < S.size(); i++){
    if (c.r == S[i].r && c.s == S[i].s){
      count++;
    }
  }
  return count;
}
//cnt_cards_seq
unsigned int BoardT::cnt_cards_seq(std::vector<CardStackT> S, CardT c){
  unsigned int N = 0;
  for(int i = 0; i < S.size(); i++){
    N += cnt_cards_stack(S[i],c);
  }
  return N;
}
//two two_decks
bool BoardT::two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W){
  for(RankT rk = ACE; rk <= KING; rk++){
    for(unsigned int st= 0; st <= 3; st++){
      CardT c = {static_cast<SuitT>(st), rk};
      if (cnt_cards(T,F,D,W, c) != 2){
        return false;
      }
    }
  }

  return true;
}
