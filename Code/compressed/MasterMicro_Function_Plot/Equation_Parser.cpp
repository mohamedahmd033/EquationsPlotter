#include "Equation_Parser.h"
#include "Services.h"

 float Equation_Parser:: equation_result(string equation, string variable, string variableValue)
{
	equation = Power_Parser_Replacor::power_parse_replace(equation, variable, variableValue);
	equation = Services::replace(equation, variable, variableValue);
	equation = Multiplication_Devision_Parser_Replacor::Multiplication_Devision_Parse_Replace(equation);
	equation = Add_Substract_Parser_Replacor::add_substract_parse_replace(equation);

	return stof(equation);
}

