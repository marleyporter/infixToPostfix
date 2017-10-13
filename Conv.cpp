#include "Conv.h"

//declaration of the node, setting attributes to null
Symbol::Symbol()
{
	caracter = NULL;
	next = NULL;
	previous = NULL;
}

//gives the current node a value and sets next to null 
Symbol::Symbol(char* symbolOp)
{
	caracter = symbolOp;
	next = NULL;
}

//setting next to the address of the new node
void Symbol::setNext(Symbol* nextNode)
{
	next = nextNode;
}

//returns the address of next
Symbol* Symbol::getNext()
{
	return next;
}

//returns the address of the value of a node
char* Symbol::getSymbol()
{
	return caracter;
}

//sets previous to the address of the previous node
void Symbol::setPrevious(Symbol* prev)
{
	previous = prev;
}

//returns the address of the previous node
Symbol* Symbol::getPrevious()
{
	return previous;
}

////////////////////////////////////////////////////

//declaring the list, assigning null to the start and end (list is empty)
Stack::Stack()
{
	start = NULL;
	end = NULL;
}

//boolean returns true if list is empty and false if the list contains anything
bool Stack::IsEmpty()
{
	if (end == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//add the first node to the list
void Stack::addFirst(char* symbolOp)
{
	Symbol* current;
	current = new Symbol(symbolOp);
	start = current;
	end = current;
}

//checks to see if the list is empty and adds a new node to the linked list containing the symbol.
void Stack::addToEnd(char* symbolOp)
{
	Symbol* current;
	if (end == NULL)
	{
		addFirst(symbolOp);
	}
	else
	{
		Symbol* previous;
		current = new Symbol(symbolOp);
		previous=end;
		end->setNext(current);
		end = current;
		end->setPrevious(previous);
		
	}
}

//deletes the last symbol from the stack
void Stack::pop()
{
	Symbol * old = end;
	end = end->getPrevious();

	if (end == NULL)
	{
		start = NULL;
		delete old;
	}
	else
	{	
		end->setNext(NULL);
		delete old;
	}
}

//returns the last element of the stack
char Stack::getEnd()
{
	return *(end->getSymbol());
	
}