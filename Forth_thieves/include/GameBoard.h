/**
 * \file GameBoard.h
 * \author Brian Kibazohi
 * \brief This header file contains the declarations required for the gmeboard module.
 */
#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_
#include "CardTypes.h"
#include "CardStack.h"
#include <vector>
//defining the st
typedef std::vector<CardStackT> SeqCrdStckT;
class BoardT{
private:
  SeqCrdStckT T;
  SeqCrdStckT F;
  CardStackT D;
  CardStackT W;
  bool two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W);
  unsigned int cnt_cards_seq(std::vector<CardStackT> S, CardT c);
  unsigned int cnt_cards_stack(CardStackT s, CardT c);
  unsigned int cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W, CardT c);
  SeqCrdStckT init_seq(unsigned int n);
  SeqCrdStckT tab_deck(std::vector<CardT> deck);
  bool is_valid_pos(CategoryT c, unsigned int n);
  bool valid_tab_tab(unsigned int n_0, unsigned int n_1);
  bool valid_tab_foundation(unsigned int n_0, unsigned int n_1);
  bool valid_waste_tab(unsigned int n);
  bool valid_waste_foundation(unsigned int n);
  bool tab_placeable(CardT c, CardT d);
  bool foundation_placeable(CardT c, CardT d);


public:
  /**
   * @brief : constructor for GameBoard, uses the two_decks method to distribute
              the cards across the respective CardStacks and initiliaze them as well
   * @param deck: vector of type CardT
   * @exception: throws invalid argument exception if the function two decks returns false
   */
  BoardT(std::vector<CardT> deck);
  /**
   * @brief : This method returns a boolean to check whether it is valid to move a Card
              from the tableau to another valid CategoryT
   * @param c: c of type CategoryT, can be Tableau, Foundation, Deck or waste
   * @param n_0: unsigned interger n_0
   * @param n_1: unsigned interger n_1
   * @exception: throws out_of_range exception if the the n_0 and n_1 exceeded the size of Tableau or Foundation
   * @return boolean
   */
  bool is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);
  /**
   * @brief : This method returns a boolean to check whether it is valid to move a Card
              from the waste to another valid CategoryT
   * @param c: c of type CategoryT, can be Tableau, Foundation, Deck or waste
   * @param n_0: unsigned interger n
   * @exception: throws out_of_range exception if n has exceeded the size of CaategoryT
   * @exception: throws invalid invalid_argument exception if the waste is empty
   * @return boolean
   */
  bool is_valid_waste_mv(CategoryT c, unsigned int n);
  /**
   * @brief : This method returns a boolean to check whether it is valid to move a Card
              from the deck to another valid CategoryT
   * @param : no parameter
   * @exception: no exceptions
   * @return : return size of Deck
   */
  bool is_valid_deck_mv();
  /**
   * @brief : This method moves a CardT from the tableau to another valid CategoryT
   * @param c: c of type CategoryT, can be Tableau, Foundation, Deck or waste
   * @param n_0: unsigned interger n_0
   * @param n_1: unsigned interger n_1
   * @exception: throws invalid_argument if the the n_0 and n_1 exceeded the size of Tableau or Foundation
   * @return void
   */
  void tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);
  /**
   * @brief : This method moves a Card from the waste to another valid CategoryT
   * @param c: c of type CategoryT, can be Tableau, Foundation, Deck or waste
   * @param n: unsigned interger n
   * @exception: throws invalid invalid_argument exception if the waste is empty
   * @return void
   */
  void waste_mv(CategoryT c, unsigned int n);
  /**
   * @brief : This method moves a Card from the deck to another valid CategoryT
   * @param : no parameter
   * @exception: raises invalid_argument exception if the deck is empty
   * @return : void
   */
  void deck_mv();
  /**
   * @brief : This method is an accesor method that returns a stack of cards
              from the tableau Sequence.
   * @param : unsigned int
   * @exception: raises out_of_range exception there is no valid placement for card
                from tableau.
   * @return : Tableau of CardStackT
   */
  CardStackT get_tab(unsigned int i);
  /**
   * @brief : This method is an accesor method that returns a stack of cards
              from the foundation Sequence.
   * @param : unsigned int
   * @exception: raises out_of_range exception there is no valid placement for card
                from tableau.
   * @return : Foundation of CardStackT
   */
  CardStackT get_foundation(unsigned int i);
  /**
   * @brief : This method is an accesor method that returns a CardStack
              from the Deck.
   * @no param
   * @return : Deck of CardStackT
   */
  CardStackT get_deck();
  /**
   * @brief : This method is an accesor method that returns a CardStack
              from the waste .
   * @no param
   * @return : Waste of CardStackT
   */
  CardStackT get_waste();
  /**
   * @brief : This method returns boolean to check whether  a valid move is
              possible from different CategoryT elements
   * @no param
   * @return : boolean
   */
  bool valid_mv_exists();
  /**
   * @brief : a method that returns a boolean indicating if the game is won.
   * @no param
   * @return : boolean
   */
  bool is_win_state();

};

#endif
