#ifndef Conv_H
#define Conv_H

#include "RPN.h"
#include <iostream>
#include <stack>
#include <string>
#include <limits>
#include <sstream>


using namespace std;

//Definition of the node class
class Symbol
{
private:
	char* caracter;
	Symbol* next;
	Symbol* previous;
public:
	Symbol();
	Symbol(char* symbolOp);
	void setNext(Symbol* nextNode);
	Symbol* getNext();
	char* getSymbol();
	void setPrevious(Symbol* previous);
	Symbol* getPrevious();
};

//Definition of the list class
class Stack
{
	Symbol* start;
	Symbol* end;
public:
	Stack();
	bool IsEmpty();
	void addFirst(char* symbolOp);
	void addToEnd(char* symbolOp);
	void pop();
	char getEnd();
};

#endif // !Conv_H