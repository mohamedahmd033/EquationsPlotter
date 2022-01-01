#pragma once
#include <algorithm>
#include "Power_Parser_Replacor.h"
#include "Multiplication_Devision_Parser_Replacor.h"
#include "Add_Substract_Parser_Replacor.h"

class Equation_Parser
{
    friend class Equation_Plotter;

private:
	Equation_Parser();

    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: equation_result
      * Input: string equation, string variable, string variableValue
      *
      *         'equation' variable is a string represents an equaiton e.g. ("x^3+2^x+1")
      *
      *         'variable' variable is a string represents a variable in the equation e.g. ("x")
      *
      *         'variableValue' variable is a string represents the value of the variable in the equation e.g. ("3.2")
      *
      *
      * return: float
      *
      *
      * Description:This Function Call All Parsers Functions starting with the (power_Parse_Replace) function
      * in the (Power_Parser_Replacor) class then it call the (replace) function in the services class to
      * replace all 'variable' in the equation with the 'variableValue'.
      * then it call the (multiplication_Devision_Parse_Replace) function in the Multiplication_Devision_Parser_Replacor
      * class, then it call the (Add_Substract_Parse_Replace) function int the Add_Substract_Parser_Replacor
      * class, then finally in convert the equation returned from the (Add_Substract_Parse_Replace) function to
      * a float number and return it.
      *
      * so basically get the result of an equation(x) if x = a certain value which is 'variableValue' input
      * e.g.
      * equation =  "x^3+2^x+1"
      * variable = x
      * variableValue = 2
      *
      * returned result will be 13
    ----------------------------------------------------------------------------------------------------------------*/
    static float equation_result(string equation, string variable, string variableValue);

};

