#ifndef RPN_H
#define RPN_H


#include "Conv.h"
#include <iostream>
#include <stack>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

//Definition of the Expression class 
class Expression
{
private:
	string data;
	string infixEx;

public:
	int Precedence(char a);
	void ConvertToPostfix(Expression exp);
	Expression(string input);
	string showInfix();
	string showPostfix();

};


#endif // !RPN_H
