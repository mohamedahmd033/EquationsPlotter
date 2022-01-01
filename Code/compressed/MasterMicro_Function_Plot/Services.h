#pragma once

#include <string>
using namespace std;
class Services {

	friend class Equation_Validator;
	friend class Power_Parser_Replacor;
	friend class Multiplication_Devision_Parser_Replacor;
	friend class Add_Substract_Parser_Replacor;
	friend class Equation_Parser;

private:

    Services();




    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isMinusOperator
      *
      * Input: char character
      *
      * Return: bool
      *
      * Description:  This Function takes a character, check if the character is a minus operator '-'
      *
      *               the functions returns true if it is an operator, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isMinusOperator(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isPlusORMinusOperator
      *
      * Input: char character
      *
      * Return: bool
      *
      * Description:  This Function takes a character, check if the character is a minus '-' or plus '+' operator
      *
      *               the functions returns true if it is an operator, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isPlusORMinusOperator(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isOtherOperator
      *
      * Input: char character
      *
      * Return: bool.
      *
      * Description:  This Function takes a character, check if the character is one of these operators {+,*,/,^}.
      *
      *              the functions returns true if it is an operator, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isOtherOperator(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isOperator
      *
      * Input: char character
      *
      * Return: bool.
      *
      * Description:  This Function takes a character, check if the character is one of these operators {-,+,*,/,^}.
      *
      *              the functions returns true if it is an operator, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isOperator(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isValidInput
      *
      * Input: char character
      *
      * Return: bool.
      *
      * Description:  This Function takes a character, check if the character is one of these operators {-,+,*,/,^}
      *               or a number from 0 to 9 {0,1,2,3 ... 9}, or x character 'x'.
      *
      *              the functions returns true if it is one of the specified characters, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isValidInput(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: isDot
      *
      * Input: char character
      *
      * Return: bool
      *
      * Description:  This Function takes a character, check if the character is a decimal point '.'
      *
      *               the functions returns true if it is a decimal point, false otherwise.
    ----------------------------------------------------------------------------------------------------------------*/
	static bool isDot(char character);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: get_before_operator_value
      *
      * Input: (string equation, int SignIndex)
      *
      *        'equation' is a string for an equation e.g. (x^2+32*x-1)
      *
      *        'SignIndex' is an index for a certain operator e.g.(6) which is an index for the
      *        multiplication '*' operator in the 'equation' variable.
      *
      * Return: pair<string, int>
      *
      * Description:  This funciton starts from the given index 'SignIndex', store all the previous characters
      *                of the 'equation' variable until it finds an operator, it will then store these characters
      *                as a string and aslo will store the index of the first character of these characters in
      *                the 'equation' variable as an integer.
      *
      *                e.g.  ( equation = x^2+32*x-1 , SignIndex = 6
      *                        the stored string will be "32", and the stored index will be 4.
      *                        these string and int will be returned as a pair)
      *
      * Remarks: This function doesn't handle the case that the operator is the first element in the equation
      *          this case must be handled before calling this function.
    ----------------------------------------------------------------------------------------------------------------*/
    static pair<string, int> get_before_operator_value(string equation, int SignIndex);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: get_after_operator_value
      *
      * Input: (string equation, int SignIndex)
      *
      *        'equation' is a string for an equation e.g. (x^2+32*x-1)
      *
      *        'SignIndex' is an index for a certain operator e.g.(6) which is an index for the
      *        multiplication '*' operator in the 'equation' variable.
      *
      * Return: pair<string, int>
      *
      * Description:  This funciton starts from the given index 'SignIndex', store all the next characters
      *                of the 'equation' variable until it finds an operator, it will then store these characters
      *                as a string and aslo will store the index of the first character of these characters in
      *                the 'equation' variable as an integer.
      *
      *                e.g.  ( equation = x^2+32*x-1 , SignIndex = 6
      *                        the stored string will be "x", and the stored index will be 7.
      *                        these string and int will be returned as a pair)
      *
      * Remarks: This function doesn't handle the case that the operator is the last element in the equation
      *          this case must be handled before calling this function.
    ----------------------------------------------------------------------------------------------------------------*/
    static pair<string, int> get_after_operator_value(string equation, int SignIndex);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: replace
      *
      * Input: (string equation, string toRemoveSubstring, string toAddSubstring)
      *
      *         'equation' variable is a string represents an equaiton e.g. (x-3+2*x+1)
      *
      *         'toRemoveSubstring' variable is a string represnts only and just only one character
      *          but for the mechanism of the function it needed to be given as a string e.g. ("x")
      *
      *         'toAddSubstring' is a string will replace 'toRemoveSubstring' variable
      *
      * Return: string
      *
      * Description:  This function will loop on the 'equation' variable, replace any 'toRemoveSubstring' variable
      *               with 'toAddSubstring' variable, override the 'equation' variable with the new equation after replacment
      *               til that there is no more 'toRemoveSubstring' character in 'equation' variable.
      *
      *                e.g.  ( equation = x-2+32*x-1 , toRemoveSubstring = "x" ,toAddSubstring = "3.2"
      *                        new equation will be "3.2-2+32*3.2-1" and will be returned from the function)
      *
    ----------------------------------------------------------------------------------------------------------------*/
	static string replace(string equation, string toRemoveSubstring, string toAddSubstring);
};
