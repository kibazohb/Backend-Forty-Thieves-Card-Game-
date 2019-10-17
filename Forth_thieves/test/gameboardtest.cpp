#include "catch.h"
#include "CardTypes.h"
#include "CardStack.h"
#include <iostream>
#include <vector>
#include "GameBoard.h"
#include "Stack.h"
#include <stdexcept>


TEST_CASE("tests for Game Board", "[BoardT]"){
  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }
  SECTION("Constructor test"){
    BoardT board(d);
    CardStackT test_seq = board.get_tab(0);
    REQUIRE(test_seq.top().r == ACE);
  }

  SECTION("Constructor test"){
    BoardT board(d);
    CardStackT test_seq = board.get_tab(0);
    REQUIRE(test_seq.top().s == Diamond);
  }

    //checking that all the tableaus have 4 cards in each
    //also checks in get_tab works correctly


    //test get_foundation and makes sure that no cards exist in there
    SECTION( "get_foundation"){
        BoardT board(d);
        CardStackT foundation = board.get_foundation(0);
        REQUIRE(foundation.size() == 0);
    }

    //test get_deck and makes sure that there is 64 cards
    SECTION( "get_deck"){
        BoardT board(d);
        CardStackT deck = board.get_deck();
        REQUIRE(deck.size() == 64);
    }

    //test get_waste and makes sure that there are no cards initially
    SECTION( "get_waste"){
        BoardT board(d);
        CardStackT waste = board.get_waste();
        REQUIRE(waste.size() == 0);
    }


    std::vector<CardT> deck2;
    for (RankT rank = ACE; rank <= KING; rank++) {
        for (unsigned int suit = 0; suit < 4; suit++) {
        CardT n = { static_cast<SuitT>(suit), rank };
        //made with 2 decks
        deck2.push_back(n);
        }
    }


    SECTION( "general tests for valid tab move" )
    {
        std::random_shuffle(d.begin(), d.end());
        BoardT board(d);
        try {
        board.is_valid_tab_mv(Foundation, 1, 3);
        }catch (std::out_of_range &e) {}
        REQUIRE(board.is_valid_tab_mv(Foundation, 1, 3) == 0);
    }

    SECTION( "general tests for valid tab move(c = Waste)" )
    {
        std::random_shuffle(d.begin(), d.end());
        BoardT board(d);
        REQUIRE(board.is_valid_tab_mv(Waste, 1, 3) == 0);
    }

    SECTION( "general tests for valid waste move- exception will raise" )
    {
        BoardT board2(d);
        try {
        std::cout << "Valid waste move? " << board2.is_valid_waste_mv(Foundation, 0) << std::endl;
        } catch (std::invalid_argument &e) {}
        REQUIRE_THROWS_AS(board2.is_valid_waste_mv(Foundation, 1), std::invalid_argument);
    }

    SECTION( "general tests for valid deck move" )
    {
        BoardT board2(d);
        REQUIRE(board2.is_valid_deck_mv() == 1);
    }

    SECTION( "general tests for is win state, will fail as game has not been played" )
    {
        BoardT board3(d);
        REQUIRE(board3.is_win_state() ==  0);
    }

    SECTION( "general tests for valid move exists" )
    {
        BoardT board4(d);
        board4.deck_mv();
        REQUIRE(board4.valid_mv_exists() == 0);
    }

    SECTION( "general tests for valid tab move" )
    {
        BoardT board5(d);
        try {
        board5.tab_mv(Tableau, 0, 1);
        } catch (std::invalid_argument &e) {}
        REQUIRE(true);
    }

    SECTION( "general tests for valid tab move" )
    {
        BoardT board7(d);
        try {
        board7.waste_mv(Tableau, 0);
        } catch (std::invalid_argument &e) {}
        REQUIRE_THROWS_AS(board7.waste_mv(Tableau, 0), std::invalid_argument);
    }
}
//collaborated gameboardtest.cpp with Yerin Thevarajah
