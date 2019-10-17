
/**
 * \file CardTypes.h
 * \author Brian Kibazohi
 * \brief This header file contains the signatures required to create the card data type.
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Enumerator for card Suits.
 */
enum SuitT{Heart, Diamond, Club, Spade};

 /**
  * \brief Enumerator for Category of cards..
  */
enum CategoryT{Tableau, Foundation, Deck, Waste};

/**
 * \brief struct for data type cardT.
 */
 struct CardT{
   SuitT s;
   RankT r;
 };

 typedef struct CardT CardT;
#endif
