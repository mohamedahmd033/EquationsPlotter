#pragma once
#include "Services.h"
#include <string>
using namespace std;

typedef string errorType;


class Equation_Validator
{
    friend class Equation_Plotter;

	static int dotIsRepeatedCount;

private:
	Equation_Validator();

    /*----------------------------------------------------------------------------------------------------------------
      * Function minusOperatorChecker:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3*x-x^2/5+3")
      *
      *        'index' is an index for a minus operator in the 'equation' variable
      *        e.g.(3) which is the index for the plus operator in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typdef of a string.
      *
      * Description: This function takes a string represents an equation and an integer represents the minus
      * operator index, it then check for the error that the character which its index is just before the
      * given operator index is one of these character {-,+}.or the error that the operator index is the last
      * element in the equation.
      * it returns errorType represents the error description if one of these errors is found,
      * otherwise it return the errorType containing "none".
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType minusOperatorChecker(string equation, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function minusOperatorChecker:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3*x-x^2/5+3")
      *
      *        'index' is an index for an operator of these operators {+,*,/,^} in the 'equation' variable
      *        e.g.(1) which is the index for the multiplication operator in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typdef of a string.
      *
      * Description: This function takes a string represents an equation and an integer represents an
      * operator index of these operators {+,*,/,^}.
      * it then check for the error that the character which its index is just before the
      * given operator index is one of these character {-,+,*,/,^}. or check the error that is the operator
      * index is the first or the last element in the equation.
      * it returns errorType represent the error description if one of these errors is found,
      *  otherwise it return the errorType containing "none".
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType notMinusOperatorChecker(string equation, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function numberChecker:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3*x-x^2/5+3")
      *
      *        'index' is an index for a number in the 'equation' variable
      *        e.g.(0) which is the index for the number(3) in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typedef of a string
      *
      * Description: This function takes a string represents an equation and an integer represents the
      * number index.
      * it then check for the error that the character which its index is just before the
      * given index is an 'x' character or any other undefined character which is not an x or number or
      * arithmetic operator character.
      * it return errorType represent the error description if this error is found, otherwise it return
      * the errorType containing "none".
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType numberChecker(string equation, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function XChecker:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3*x-x^2/5+3")
      *
      *        'index' is an index for an 'x' character in the 'equation' variable
      *        e.g.(2) which is the index for one of the 'x' characters in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typedef of a string
      *
      * Description: This function takes a string represents an equation and an integer represents the
      * 'x' character index.
      * it then check for the error that the character which its index is just before the
      * given index is a 'x' character or a number without an operator between them or any other
      * undefined character which is not an x or number or arithmetic operator character.
      * it return errorType represent the error description if this error is found, otherwise it return
      * the errorType containing "none".
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType XChecker(string equation, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function dotChecker:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3.1*x-x^2/5+3")
      *
      *        'index' is an index for an 'x' character in the 'equation' variable
      *        e.g.(1) which is the index for the '.' character in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typedef of a string
      *
      * Description: This function takes a string represents an equation and an integer represents the
      * '.' character index.
      * it then check for the error that the character which its index is just before the
      * given index is any character other than a number character.
      * it return errorType represent the error description if this error is found, otherwise it return
      * the errorType containing "none".
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType dotChecker(string equation,int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function invalidInputError:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("3.1*z-x^2/5+3")
      *
      *        'index' is an index for an 'x' character in the 'equation' variable
      *        e.g.(4) which is the index for the 'z' character in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typedef of a string
      *
      * Description: This function takes a string represents an equation and an integer represents the
      * undefined character index which is not an operator or an 'x' or a number or a decimal point.

      * it return errorType represent the error description that no undefined character can be found in
      * the equation.
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType invalidInputError(char character, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function lastIsOperatorError:
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("2*x-x^2/5-3+")
      *
      *        'index' is an index for an operator character which is the last element in the equation.
      *        e.g.(11) which is the index for the '+' character in the equation.
      *
      *
      * Return: errorType
      *         errorType is a typedef of a string
      *
      * Description: This function takes a string represents an equation and an integer represents an index
      * for an operator character which is the last element in the equation.
      * it return errorType represents the error description that no operator can be the last element in the equation.
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType lastIsOperatorError(char character, int index);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: equationValidatorChecker
      * Input:(string equation, int index)
      *
      *        'equation' variable is a string represents an equaiton e.g. ("2*x-x^2/5-3")
      *
      *
      * Return: errorType
      *        errorType is a typedef of a string
      *
      *
      * Description: This function uses the previous functions to check all 'equation' variable characters
      * if there is any type of violation in the equation form and return a description for the error
    ----------------------------------------------------------------------------------------------------------------*/
	static errorType equationValidatorChecker(string equation);

};

