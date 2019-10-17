#include <vector>
#include <iostream>
#include "CardTypes.h"
#include "Stack.h"
#include "catch.h"
#include "CardStack.h"
#include <stdexcept>

TEST_CASE("tests for Stack<CardT>", "[Stack]"){
  std::vector<CardT> test_stack;
  CardT AceSpades = {Spade, ACE}; test_stack.push_back(AceSpades);
  CardT TwoSpades = {Spade, 2}; test_stack.push_back(TwoSpades);
  CardT ThreeSpades = {Spade, 3}; test_stack.push_back(ThreeSpades);
  CardT FourSpades = {Spade, 4}; test_stack.push_back(FourSpades);
  CardT FiveSpades = {Spade, 5}; test_stack.push_back(FiveSpades);
  CardT SixSpades = {Spade, 6}; test_stack.push_back(SixSpades);
  CardT SevenSpades = {Spade, 7}; test_stack.push_back(SevenSpades);
  CardT EightSpades = {Spade, 8}; test_stack.push_back(EightSpades);
  CardT NineSpades = {Spade, 9}; test_stack.push_back(NineSpades);
  CardT TenSpades = {Spade, 10}; test_stack.push_back(TenSpades);
  CardT JackSpades = {Spade, JACK}; test_stack.push_back(JackSpades);
  CardT QueenSpades = {Spade, QUEEN}; test_stack.push_back(QueenSpades);
  CardT KingSpades = {Spade, KING}; test_stack.push_back(KingSpades);

  SECTION("constructor and cardT"){
    CardT c = {Spade, ACE};
    REQUIRE(c.s == Spade);
    REQUIRE(c.r == ACE);
  }
  SECTION("constructor with empty vector"){
    CardStackT S = Stack<CardT>();
    REQUIRE(S.size() == 0);
  }
  SECTION("Construct a stack with elements in vector"){
    CardStackT S = Stack<CardT>(test_stack);
    REQUIRE (S.size() == 13);
  }
  SECTION("Pop an empty stack"){
    CardStackT S = Stack<CardT>();
    REQUIRE_THROWS_AS(S.pop(),std::out_of_range);
  }
  SECTION("Pop a non empty stack"){
    CardStackT S = Stack<CardT>(test_stack);
    S.pop();
    REQUIRE(S.size() == 12);
  }
  SECTION("Top of an empty stack"){
    CardStackT S = Stack<CardT>();
    REQUIRE_THROWS_AS(S.pop(),std::out_of_range);
  }
  SECTION("Top of non empty stack"){
    CardStackT S = Stack<CardT>(test_stack);
    bool val = S.top().s == Spade && S.top().r == KING;
    REQUIRE( val );
  }
  SECTION("Size of stack"){
    CardStackT S = Stack<CardT>(test_stack);
    REQUIRE (S.size() == 13);
  }
  SECTION("Test toSeq with empty seq"){
    CardStackT S = Stack<CardT>();
    CardStackT check = S.toSeq();
    REQUIRE(check.size() == 0);
  }
  SECTION("Test toSeq with empty seq"){
    CardStackT S = Stack<CardT>(test_stack);
    CardStackT check = S.toSeq();
    REQUIRE(check.size() == 13);
  }  

}
