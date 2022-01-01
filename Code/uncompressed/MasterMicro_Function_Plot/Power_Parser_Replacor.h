#pragma once
#include <string>
#include <math.h>
#include <sstream>
#include "Services.h"

using namespace std;

class Power_Parser_Replacor
{
    friend class Equation_Parser;

private:

    Power_Parser_Replacor();


    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: power_parse_replace
      *
      * Input: (string equation, string variable, string variableValue)

      *         'equation' variable is a string represents an equaiton e.g. ("x^3+2^x+1")
      *
      *         'variable' variable is a string represents a variable in the equation e.g. ("x")
      *
      *         'variableValue' variable is a string represents the value of the variable in the equation e.g. ("3.2")
      *
      * Return: string
      *
      * Description: This function loop on the equation to find each power operator '^' in the equation,
      * for each time it finds this operators it uses the (get_before_operator_value) and (get_after_operator_value)
      * functions of the service class to obtain the base and the power values as a string of the power operator '^'
      * then it uses the (replace) function from the services class to replace the variable of the equation that
      * exist in either the power or the base strings with the string in 'variableValue' variable,
      * then it calculate the result with this form ( result = pow(baseValue,powerValue)  )
      * then the term base^power in the equation will be replaced with the result after converting it to a string.
      * the function will continue looping till that there is no power operator "^" exist in the equation then it
      * returns the new equation.
      *
      * e.g.
      *  equation = "x^3+2^x+1"
      *  variable = "x"
      *  variableValue = "3.2"
      *
      * the new equation will be "32.768+9.1895868+1" then it will be returned from the function
      *
    ----------------------------------------------------------------------------------------------------------------*/
	static string power_parse_replace(string equation, string variable, string variableValue);

};
