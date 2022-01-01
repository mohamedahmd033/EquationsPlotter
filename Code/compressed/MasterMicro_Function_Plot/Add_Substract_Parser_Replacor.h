#pragma once
#include<string>
#include"Services.h"

class Add_Substract_Parser_Replacor
{
    friend class Equation_Parser;

private:
    Add_Substract_Parser_Replacor();


    /*----------------------------------------------------------------------------------------------------------------
          * Function Name: add_substract_parse_replace
          *
          * Input: string equation
          *
          *         'equation' variable is a string represents an equaiton with no variables e.g. ("-2+3-4-5+2.234")
          *
          *
          *
          * Return: string
          *
          *
          * Description: This function loop on the equation to find each plus '+' or minus '-' operator in the
          * equation,for each time it finds one of these operators it uses the (get_before_operator_value)
          * and (get_after_operator_value) functions of the service class to obtain the values before and after
          * the operator, then it calculates the result with this form ( result = beforeValue (the operator) afterValue )
          * then, the values before and after the operator and also the operator will be replaced with the result
          * after converting it to a string.
          * the function will continue looping till that there is no plus '+' or minus '-' operators exist in
          * the equation then it returns the new equation.
          *
          * e.g.
          *  equation = "-2+3-4-5+2.234"
          * the new equation will be "-5.766" then it will be returned from the function
          *
          * Remarks: This function doesn't accept in its input any character but a number or a decimal point or an operator
          *  it doesn't handle the input if the equation input in a wrong mathematical form e.g. "5+*3-1" or an equation
          *  with a variable e.g. "5+x-3+1".
          *
          *  This function need to be called after calling (Multiplication_Devision_Parse_Replace) function
          *  in the Multiplication_Devision_Parser_Replacor class respectively.
        ----------------------------------------------------------------------------------------------------------------*/
	static string add_substract_parse_replace(string equation);
};

