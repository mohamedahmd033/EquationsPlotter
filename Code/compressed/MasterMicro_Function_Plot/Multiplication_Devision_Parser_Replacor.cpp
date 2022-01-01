#include "Multiplication_Devision_Parser_Replacor.h"



Multiplication_Devision_Parser_Replacor:: Multiplication_Devision_Parser_Replacor()
{

}

string Multiplication_Devision_Parser_Replacor::Multiplication_Devision_Parse_Replace(string equation)
{
	int operatorIndex;
	pair<string, float> beforeSignValue__beforeValueStartIndex;
	pair<string, float> afterSignValue__AfterValueEndIndex;
	string beforeValue;
	string afterValue;
	int startIndex;
	int endIndex;
	float result;



	for (int i = 0; i < equation.size(); i++)/* loop till no * or / operators exist */
	{
		if (equation[i] == '*' || equation[i] == '/')
		{
			operatorIndex = i;

			beforeSignValue__beforeValueStartIndex = Services::get_before_operator_value(equation, operatorIndex);
			afterSignValue__AfterValueEndIndex = Services::get_after_operator_value(equation, operatorIndex);

			beforeValue = beforeSignValue__beforeValueStartIndex.first;
			afterValue = afterSignValue__AfterValueEndIndex.first;
			startIndex = beforeSignValue__beforeValueStartIndex.second;
			endIndex = afterSignValue__AfterValueEndIndex.second;

			if (equation[i] == '*') {
				result = (stof(beforeValue) * stof(afterValue));
			}

			if (equation[i] == '/') {
	
				result = (stof(beforeValue) / stof(afterValue));
			}

			equation = equation.replace(startIndex, (endIndex - startIndex) + 1, to_string(result));

		}
	}
	return equation;
}
