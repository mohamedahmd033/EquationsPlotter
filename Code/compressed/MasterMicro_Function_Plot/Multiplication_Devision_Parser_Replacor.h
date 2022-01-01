#pragma once
#include<string>
#include"Services.h"
using namespace std;

class Multiplication_Devision_Parser_Replacor
{
    friend class Equation_Parser;
private:
    Multiplication_Devision_Parser_Replacor();



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: Multiplication_Devision_Parse_Replace
      *
      * Input: string equation

      *         'equation' variable is a string represents an equaiton with no variables e.g. ("2*3+2/6+1")
      *
      *
      * Return: string
      *
      * Description: This function loop on the equation to find each multiplication '*' or division '/' operator
      * in the equation,for each time it finds one of these operators it uses the (get_before_operator_value)
      * and (get_after_operator_value) functions of the service class to obtain the values before and after
      * the operator, then it calculates the result with this form ( result = beforeValue (the operator) afterValue )
      * then, the values before and after the operator and also the operator will be replaced with the result
      * after converting it to a string.
      * the function will continue looping till that there is no multiplication '*' or division '/' operators exist
      * in the equation then it returns the new equation.
      *
      * e.g.
      *  equation = "2*3+2/6+1"
      * the new equation will be "6+0.33333333+1" then it will be returned from the function
      *
      *
      * Remarks: This function doesn't accept in its input any character but a number or a decimal point or an operator
      *  it doesn't handle the input if the equation input in a wrong mathematical form e.g. "5+*3-/1" or an equation
      *  with a variable e.g. "5*x-3/x".
      *
      *  This function need to be called after calling (power_parse_replace) function in the
      *  Power_Parser_Replacor Class
        --------------------------
    ----------------------------------------------------------------------------------------------------------------*/
	static string Multiplication_Devision_Parse_Replace(string equation);
};

