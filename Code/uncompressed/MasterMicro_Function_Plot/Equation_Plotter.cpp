#include "Equation_Plotter.h"
#include <iostream>

bool Equation_Plotter::equationIsValidVar = false;


Equation_Plotter::Equation_Plotter()
{
	equation = "none";
	variable = "x";
    max_x = 5;
    min_x = -5;
    max_y = 5;
    min_y = -5;
	step = 0.01;
}
Equation_Plotter::Equation_Plotter(string equation, string variable, float max_x, float min_x, float max_y, float min_y, float step)
{
	this->equation = equation;
	this->variable = variable;
	this->step = step;
    this->max_x = max_x;
    this->min_x = min_x;
    this->max_y = max_y;
    this->min_y = min_y;
}


void Equation_Plotter::setXaxisLabel(string x)
{
	this->XaxisLabel = x;
}
void Equation_Plotter::setYaxisLabel(string y)
{
    this->YaxisLabel = y;
}
void Equation_Plotter::setEquation(string equation)
{
	this->equation = equation;
}


/*void Equation_Ploter::setVariable(string variable)
{
	this->variable = variable;
}
*/
void Equation_Plotter::setMax_x(float max_x)
{
	this->max_x = max_x;
}
void Equation_Plotter::setMin_x(float min_x)
{
	this->min_x = min_x;
}
void Equation_Plotter::setMax_y(float max_y)
{
	this->max_y = max_y;
}
void Equation_Plotter::setMin_y(float min_y)
{
	this->min_y = min_y;
}
void Equation_Plotter::setStep(float step)
{
	this->step = step;
}


float  Equation_Plotter::getMax_x(void)
{
	return max_x;
}
float  Equation_Plotter::getMin_x(void)
{
	return min_x;
}
float  Equation_Plotter::getMax_y(void)
{
	return max_y;
}
float  Equation_Plotter::getMin_y(void)
{
	return min_y;
}
float  Equation_Plotter::getStep(void)
{
    return step;
}
string Equation_Plotter::getXaxisLabel(void)
{
    return XaxisLabel;
}
string Equation_Plotter::getYaxisLabel(void)
{
    return YaxisLabel;
}


errorType Equation_Plotter::getEquationError(void)
{
    return equationError;
}
string    Equation_Plotter::getEquation(void)
{
    return equation;
}
errorType Equation_Plotter::getErrorConfig(void)
{
    return errorConfig;
}


vector<double> Equation_Plotter::getXvalues(void)
{
	return Xvalues;
}
vector<double> Equation_Plotter::getYvalues(void)
{
	return Yvalues;
}


bool Equation_Plotter::checkConfigErrors(void)
{
    string configrationError;

    bool error_found = false;
	if (equation.empty() == 1)
	{
        configrationError += "*Insert the function(x) to be plotted.\n";
        error_found = true;
	}
	if (min_x >= max_x)
	{
        configrationError += "*The maximum value of X must be greater than the minimum value of x.\n";
        error_found = true;
	}
	if (min_y >= max_y)
	{
        configrationError += "*The maximum value of Y must be greater than the minimum value of Y.\n";
        error_found = true;
	}
	if (step == 0)
	{
        configrationError += "*The Step must be greater than zero.\n";
        error_found = true;
	}
    if(configrationError.empty()==1)
	{
        configrationError = "none";
	}

    errorConfig = configrationError;

    return error_found;
}
bool Equation_Plotter::equationIsValid(void)
{
	errorType error;
    equationIsValidVar=false;
	error = Equation_Validator::equationValidatorChecker(equation);
	if (error == "none")
	{
		equationIsValidVar = true;
	}

    equationError = error;
	return equationIsValidVar;
}
void Equation_Plotter::insert_XandY_values(void)
{
	float x;
	float y;
    /*float test;
    int test_number = 0;*/

    Xvalues.clear();
    Yvalues.clear();

    if (equationIsValidVar && step>0)
	{
		for (x = min_x; x < max_x; x += step)
		{
			y = Equation_Parser::equation_result(equation, variable, to_string(x));

			/*
			* 
			*  *************  Testing *************
			* 
			test = 100 * pow(x, 3) + 5 * 2 + 2 * x - pow(30, 2) + 6 *pow(x, 4);
			test_number++;
			if (  (fabs(test - y)  < 0.01  )  )
			{
				cout << "#TestCase " << test_number <<endl;
				cout << "test result " << test << endl;
				cout << "out result " << y << endl;
				cout << "OK" << endl;
				cout << "*********************" << endl;
			}
			else
			{
				cout << "****Error***" << endl;
				cout << "test Number: " << test_number << endl;;
				cout << "X: " <<x<< endl;
				cout << "out result " << y << endl;
				cout << "test result " << test << endl;
				cout << "Difference " << fabs(test - y) << endl;
				while(1);
			}
			
			*********************End of Testing**************
			*/

			Xvalues.push_back(x);
			Yvalues.push_back(y);
		}
		
	}
}
