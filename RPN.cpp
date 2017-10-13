#include "RPN.h"
#include "Conv.h"


//contains and returns the weight of the operators
int Expression::Precedence(char a)
{
	int numb = 0;
	if (a == '+' || a == '-')
		numb = 2;
	else if (a == '*' || a == '/')
		numb = 3;
	return numb;
}

//converts the infix expression to a postfix expression
void Expression::ConvertToPostfix(Expression exp) //used the for loop structure from: http://www.cplusplus.com/forum/beginner/16722/

{
	Stack stak;

	//stringstream that contains the postfix expression
	stringstream postfixEx;

	//for loop goes through all of the elements of the user input
	for (unsigned i = 0; i < exp.infixEx.length(); i++)
	{
		//if the symbol is a '(' push it onto the stack
		if (exp.infixEx[i] == '(')
		{
			stak.addToEnd(&exp.infixEx[i]);
		}
			
		//if the symbol is a ')' ...
		else if (exp.infixEx[i] == ')')
		{
			//append and pop symbols from stack until most recent left bracket
			while (stak.getEnd() != '(')
			{
				postfixEx << stak.getEnd();
				stak.pop();
			}
			//pop the right bracket
			stak.pop();
		}
		//if the symbol is an operator...
		else if (exp.infixEx[i] == '+' || exp.infixEx[i] == '-' || exp.infixEx[i] == '*' || exp.infixEx[i] == '/')
		{
			//append and pop to the postfix expression all symbols above the most recent left bracket and that weigh
			//more or equal to the new operator
			while (stak.IsEmpty() == false && Precedence(stak.getEnd()) >= Precedence(exp.infixEx[i]))
			{
				postfixEx << stak.getEnd();
				stak.pop();
			}
			//add the operator to the stack
			stak.addToEnd(&exp.infixEx[i]);
		}
		//if the symbol is an operand append it to the postfix expression
		else
		{
			postfixEx << exp.infixEx[i];
		}
	}
	//append and pop to the postfix expression all symbols until the stack is empty
	while (!stak.IsEmpty())
	{
		postfixEx << stak.getEnd();
		stak.pop();
	}
	//store postfix stringstream to a string
	data = postfixEx.str();
}

//Store the user input into a variable
Expression::Expression(string input)
{
	infixEx = input;
}

//return the infix expression
string Expression::showInfix()
{
	return infixEx;
}

//return the postfix expression
string Expression::showPostfix()
{
	return data;
}



