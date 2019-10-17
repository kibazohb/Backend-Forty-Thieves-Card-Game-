/**
 * \file Stack.h
 * \author Brian Kibazohi
 * \brief This header file contains the declarations required for the generic stack module
 */
#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>
/**
 * brief : initialize state variable S
 */
template<class T>
class Stack{
private:

  std::vector<T> S;

public:
  /**
   * @brief Stack Constructor for a non empty vector s
   * @param s Generic vector of type T s
   *
   */
  Stack(std::vector<T> s);
  /**
   * @brief Stack Constructor for an empty vector s
   * @param : no parameter
   * @return : A generic stack S
   */
  Stack();
  /**
   * @brief : public method that push an element onto the stack
   * @param e: Element e of type T
   * @return : Generic Stack with element e
   */
  Stack<T> push(T e);
  /**
   * @brief : public method that pop/deletes the top element off the stack
   * @param : no parameter
   * @exception: raise out_of_range exception when an empty stack is popped.
   * @return : Generic Stack with element e
   */
  Stack<T> pop();
  /**
   * @brief : public method that returns the top element of the stack
   * @param : no parameter
   * @exception: raise out_of_range exception when an empty stack is called with top method.
   * @return : element of type T
   */
  T top();
  /**
   * @brief : public method that returns size generic stack<T>
   * @param : no parameter
   * @return : unsigned integer size of stack<T>
   */
  unsigned int size();
  /**
   * @brief : public method that retuns the sequence of elements stack<T>
   * @param : no parameter
   * @return : vector sequence of stack<T>
   */
  std::vector<T> toSeq();

};

#endif
