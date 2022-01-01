#include "Equation_Validator.h"


int Equation_Validator:: dotIsRepeatedCount = 0;


Equation_Validator::Equation_Validator()
{

}


 errorType Equation_Validator::minusOperatorChecker(string equation, int index)
{
	dotIsRepeatedCount = 0;

	errorType error = "none";

	if (Services::isPlusORMinusOperator(equation[index - 1]))
	{
		error = "un expected token at index " + to_string(index) + " (" + equation[index] + " and " + equation[index - 1] + ") " + "are two concatenative arithmetic operators which are not allowed to concatenate).";
	}

	return error;
}
 errorType Equation_Validator::notMinusOperatorChecker(string equation, int index)
{
	dotIsRepeatedCount = 0;

	errorType error = "none";

	if (Services::isOperator(equation[index - 1]))
	{
		error = "un expected token at index " + to_string(index) + " (" + equation[index] + " and " + equation[index - 1] + ") " + "are two concatenative arithmetic operators which are not allowed to concatenate).";
	}

	return error;
}
 errorType Equation_Validator::numberChecker(string equation, int index)
{
	errorType error = "none";

	if (equation[index - 1] == 'x')
	{
        error = "un expected token at index " + to_string(index) + " ('x' can't be followed by a number).";
	}

	return error;
}
 errorType Equation_Validator::XChecker(string equation, int index)
 {
	 errorType error = "none";

	 if (equation[index - 1] == 'x')
	 {
		 error = "un expected token at index " + to_string(index) + " ('x' can't be repeated twice in a row).";
	 }
	 else if (isdigit(equation[index - 1]))
	 {
		 error = "un expected token at index " + to_string(index) + " ('x' can't follow a number, if you meant to multiplicate this number with x, try to put '*' operator between them).";
	 }
	 else if (Services::isDot(equation[index - 1]))
	 {
		 error = "un expected token at index " + to_string(index) + " ('x' can't follow a decimal point '.').";
	 }

	 return error;
 }
 errorType Equation_Validator::dotChecker(string equation, int index)
 {
	 dotIsRepeatedCount++;
	 errorType error;
	 error = "none";

	 if (dotIsRepeatedCount > 1)
	 {
		 error = "un expected token at index " + to_string(index) + " ('.' can't be repeated twice in a number, numbers with decimal point must be in this form: (integral part).(fractional part) with only one decimal point\n";
		 dotIsRepeatedCount = 0;
	 }

	 else if (index == 0)
	 {
		 error = "un expected token at index " + to_string(index) + " ('.' can't be the first element of the equation, numbers with decimal point must be in this form: (integral part).(fractional part)\n";
	 }
	 else if (index == equation.size()-1)
	 {
		 error = "un expected token at index " + to_string(index) + " ('.' can't be the last element of the equation, numbers with decimal point must be in this form: (integral part).(fractional part)).\n";

	 }
	 else if (!isdigit(equation[index - 1])) /*not number before the '.'*/
	 {
		 error = "un expected token at index " + to_string(index) + " ('.' can follow only a decimal number, numbers with decimal point must be in this form: (integral part).(fractional part).\n";
	 }
	 else if (!isdigit(equation[index + 1])) /*not number after the '.'*/
	 {
		 error = "un expected token at index " + to_string(index) + " ('.' can be followed by only a decimal number, numbers with decimal point must be in this form: (integral part).(fractional part).\n";
	 }

	 return error;
 }

errorType Equation_Validator::invalidInputError(char character, int index)
 {
	 errorType error;
	 error = "invalid token at " + to_string(index) + " (" + character + " is invalid input" + ")";
	 return error;
 }
errorType Equation_Validator::lastIsOperatorError(char character, int index)
{
	errorType error;
	error = "invalid token at " + to_string(index) + " (" + character + " can't be the last element in the equation" + ")";
	return error;
}



 errorType Equation_Validator::equationValidatorChecker(string equation)
{
	errorType error = "none";

	if (!(Services::isValidInput(equation[0])))
	{
		return invalidInputError((equation[0]), 0);
	}

	for (int i = 1; i < equation.size(); i++)
	{

		if (equation[i] == 'x')
			error = XChecker(equation, i);

		else if (isdigit(equation[i]))
			error = numberChecker(equation, i);

		else if (Services::isMinusOperator(equation[i]))
			error = minusOperatorChecker(equation, i);

		else if (Services::isOtherOperator(equation[i]))
			error = notMinusOperatorChecker(equation, i);

		else if (Services::isDot(equation[i]))
			error = dotChecker(equation, i);

        else if (equation[i]=='X')
            error = "un expected token at index " + to_string(i) + " (the upper case of x is not supported, replace any upper case of x with a lowercase x.\n";


		else
			error = invalidInputError((equation[i]), i);


		if (  (i == equation.size() - 1)   && Services::isOperator(equation[i])  )
		{
			return lastIsOperatorError((equation[i]), i);
		}


		if (error != "none")
		{
			return error;
		}
	}

	return error;
}



