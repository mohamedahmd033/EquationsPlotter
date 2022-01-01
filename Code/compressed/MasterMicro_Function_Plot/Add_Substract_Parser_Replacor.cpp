#include "Add_Substract_Parser_Replacor.h"
#include<iostream>


Add_Substract_Parser_Replacor:: Add_Substract_Parser_Replacor()
{

}


string Add_Substract_Parser_Replacor::add_substract_parse_replace(string equation)
{
	int operatorIndex;
	pair<string, float> beforeSignValue__beforeValueStartIndex;
	pair < string, float > afterSignValue__AfterValueEndIndex;
	string beforeValue;
	string afterValue;
	int startIndex;
	int endIndex;
	float result;
	bool negativeFlag = false;


	for (int i = 0; i < equation.size(); i++)/* loop till no * or / operators exist */
	{
		if (equation[i] == '+' || equation[i] == '-')
		{
			operatorIndex = i;

			if (operatorIndex == 0 && equation[i] == '-')
			{
				negativeFlag = true;
				continue;
			}


			beforeSignValue__beforeValueStartIndex = Services::get_before_operator_value(equation, operatorIndex);
			afterSignValue__AfterValueEndIndex = Services::get_after_operator_value(equation, operatorIndex);

			beforeValue = beforeSignValue__beforeValueStartIndex.first;
			afterValue = afterSignValue__AfterValueEndIndex.first;
			startIndex = beforeSignValue__beforeValueStartIndex.second;
			endIndex = afterSignValue__AfterValueEndIndex.second;

			if (equation[i] == '+') {
				if (negativeFlag)
				{
					result = (stof("-" + beforeValue) + stof(afterValue));

				}
			
				else
				{
					result = (stof(beforeValue) + stof(afterValue));
				}
			}

			if (equation[i] == '-') {
				if (negativeFlag)
				{
					result = (stof("-" + beforeValue) - stof(afterValue));
					
				}
				else
				{
					result = (stof(beforeValue) - stof(afterValue));
				}
			}

			if (negativeFlag)
			{
				equation = equation.replace(startIndex-1, (endIndex - startIndex) + 2, to_string(result));
				negativeFlag = false;
			}
			else
			{
				equation = equation.replace(startIndex, (endIndex - startIndex) + 1, to_string(result));
				negativeFlag = false;
			}
			i = -1;
		}
	}
	return equation;
}
