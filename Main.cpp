#include "RPN.h"
#include "Conv.h"

#include <iostream>
#include <stack>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

int main()
{
	string input;
	//Save user input to variable
	cout << "Please enter an infix expression: " << endl;
	getline(cin, input);
	//initialise class
	Expression exp(input);
	//clear the console screen
	system("cls");
	//show infix expression using showInfix method
	cout << "Infix expression: " << exp.showInfix() << endl;
	//Call method that converts the infix expression to postfix
	exp.ConvertToPostfix(input);
	//show postfix expression using showPostfix method
	cout << "Postfix expression: " << exp.showPostfix() << endl;
	
	//wait for user to terminate program
	system("pause");
	return 0;

};