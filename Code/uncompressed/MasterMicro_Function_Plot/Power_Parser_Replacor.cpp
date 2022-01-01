#include "Power_Parser_Replacor.h"


Power_Parser_Replacor::Power_Parser_Replacor()
{

}

string Power_Parser_Replacor::power_parse_replace(string equation,string variable, string variableValue)
{
	int powerSignIndex;
	pair<string, float> baseValue__baseValueStartIndex;
	pair<string, float> powerValue__powerValueEndIndex;
	string baseValue;
	string powerValue;
	int startIndex;
	int endIndex;
	float power_result;


	powerSignIndex = equation.find("^");
	while (powerSignIndex != -1) /* loop till no ^ operator exist */
	{
			baseValue__baseValueStartIndex = Services::get_before_operator_value(equation, powerSignIndex);
			powerValue__powerValueEndIndex = Services::get_after_operator_value(equation, powerSignIndex);

			baseValue = baseValue__baseValueStartIndex.first;
			powerValue = powerValue__powerValueEndIndex.first;
			startIndex = baseValue__baseValueStartIndex.second;
			endIndex = powerValue__powerValueEndIndex.second;

			baseValue = Services::replace(baseValue, variable, variableValue);
			powerValue = Services::replace(powerValue, variable, variableValue);

			power_result = pow(stof(baseValue), stof(powerValue));

			equation = equation.replace(startIndex, (endIndex - startIndex)+1, to_string(power_result));
			
			powerSignIndex = equation.find("^");
	}

	return equation;
}

