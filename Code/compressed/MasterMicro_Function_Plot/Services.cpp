#include "Services.h"
#include <iostream>
using namespace std;

Services::Services()
{

}

bool Services::isMinusOperator(char character)
{
	if (character == '-')
		return true;
	else
		return false;
}
bool Services::isOtherOperator(char character)
{
	if (character == '+' || character == '*' || character == '/' || character == '^')
		return true;
	else
		return false;
}
bool Services::isPlusORMinusOperator(char character)
{
	if (character == '+' || character == '-')
		return true;
	else
		return false;
}
bool Services::isOperator(char character)
{
	if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
		return true;
	else
		return false;
}
bool Services::isValidInput(char character)
{
	if (isdigit(character) || isOperator(character) || character == 'x')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Services::isDot(char character)
{
	if (character == '.')
		return true;
	else
		return false;
}

pair<string, int>  Services::get_before_operator_value(string equation, int operatorIndex)
{
    int startIndex = operatorIndex - 1;
	int currentIndex = startIndex;
	int ValueRange;
	string value_string;

	while (!(isOperator(equation[currentIndex])))
	{
		startIndex = currentIndex;

		if (currentIndex == 0)
		{
			break;
		}
		currentIndex--;
	}

	ValueRange = operatorIndex - startIndex;

	value_string = equation.substr(startIndex, ValueRange);

	return { value_string,startIndex };

}
pair<string, int>  Services::get_after_operator_value(string equation, int operatorIndex)
{
    int endIndex = operatorIndex + 1;
	int currentIndex = endIndex;
	int ValueRange;
	string value_string;


	if (equation[currentIndex] == '-')
	{
		currentIndex++;
	}
	while (!(isOperator(equation[currentIndex])))
	{
		endIndex = currentIndex;

		if (currentIndex == equation.size() - 1)
		{
			break;
		}
		currentIndex++;
		
	}

	ValueRange = endIndex - operatorIndex;

	value_string = equation.substr(operatorIndex + 1, ValueRange);

	return { value_string,endIndex };

}

string Services::replace(string equation, string toRemoveSubstring, string toAddSubstring)
{
	int index = equation.find(toRemoveSubstring);
	while (index != -1)
	{
		equation = equation.replace(index, 1, toAddSubstring);
		index = equation.find(toRemoveSubstring);
	}
	return equation;
}
