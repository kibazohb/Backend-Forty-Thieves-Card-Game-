#include <vector>
#include <iostream>
#include "CardTypes.h"
#include "Stack.h"
#include <stdexcept>



template<class T>
Stack<T>::Stack(std::vector<T> s){
  this->S = s;
}

template<class T>
Stack<T>::Stack(){
  std::vector<T> s;
  this->S = s;

}

template<class T>
Stack<T> Stack<T>::push(T e){
  std::vector<T> temp_stack(this->S);
  temp_stack.push_back(e);
  return temp_stack;
}

template<class T>
Stack<T> Stack<T>::pop(){
  if (this->S.size() == 0){
    throw std::out_of_range("empty stack");
  }
  else{
    this->S.pop_back();
    return Stack(this->S);
  }
}

template<class T>
T Stack<T>::top(){
  if (this->S.size() == 0){
    throw std::out_of_range("empty stack");
  }
  else{
    T last_elem = this->S.back();
    return last_elem;
  }
}

template<class T>
unsigned int Stack<T>::size(){
  std::vector<T>temp_stack = this->S;
  return temp_stack.size();
}

template<class T>
std::vector<T> Stack<T>::toSeq(){
  return this->S;
}


// Keep this at bottom
template class Stack<CardT>;
