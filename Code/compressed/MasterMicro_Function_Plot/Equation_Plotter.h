#pragma once
#include <string>
#include <vector>
#include "Equation_Validator.h"
#include "Equation_Parser.h"
using namespace std;

class Equation_Plotter
{
private:
	string XaxisLabel;
	string YaxisLabel;
	string equation;
	string variable;
    errorType equationError;
    errorType errorConfig;

	float max_x;
	float min_x;
	float max_y;
	float min_y;
	float step;

	vector<double> Xvalues;
	vector<double> Yvalues;

	static bool equationIsValidVar;

public:

    Equation_Plotter();
    Equation_Plotter(string equation, string variable, float max_x, float min_x, float max_y, float min_y, float step);


    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: checkConfigErrors
      * Input: None
      * Return: bool
      * Description: This function check for some errors in the members variables values of an object of this
      * class entered be the user, these errors are:
      *                                             - 'equation' member variable is empty.
      *                                             - 'min_x is greater than of equal 'max_x'.
      *                                             - 'min_y is greater than of equal 'max_y'.
      *                                             - 'step' equal zero.
      *
      * If one or more of these errors are existed, the function will update 'errorConfig' member variables with
      * the error type as a string and return true, otherwise it will update 'errorConfig' to be empty and return
      * false.
    ----------------------------------------------------------------------------------------------------------------*/
    bool checkConfigErrors(void);



    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: equationIsValid
      * Input: None
      * Return: bool
      * Description: This function call the (equationValidatorChecker) function in the Equation_Validator class
      * and store the error in the 'equationError' member variable.
      *
      *It returns true if there is an error, false otherwise.

    ----------------------------------------------------------------------------------------------------------------*/
    bool equationIsValid(void);




    /*----------------------------------------------------------------------------------------------------------------
      * Function Name: insert_XandY_values
      * Input: None
      * Return: None
      *
      * This Function will loop in some values between 'max_x' and 'min_x' member variables be substracting
      * the 'step' member variable from the max_x member variable and store the result in a local variable 'x'
      * till it be less the 'min_x'
      * in each loop the function will call the (equation_result) Function of the Equation_Parser Class given
      * it the 'equation' member variable and the 'variable' member variable and the local variable 'x' after
      * converting it to a string. and store the result of the function after converting it to a float in
      *  'yValues' member function and store 'x' in 'xValues member function.
      *
      * This function is used to fill 'xValues' and Yvalues with data which each value in 'yValues' represent the
      * output of an equation(x) which x is the corresponding value in 'xValues'.
    ----------------------------------------------------------------------------------------------------------------*/
    void insert_XandY_values(void);



    void setXaxisLabel(string x);
	void setYaxisLabel(string y);
	void setEquation(string equation);
	/*void setVariable(string variable);*/

    void   setMax_x(float max_x);
    void   setMin_x(float min_x);
    void   setMax_y(float max_y);
    void   setMin_y(float min_y);
    void   setStep(float step);

    float   getMax_x(void);
    float   getMin_x(void);
    float   getMax_y(void);
    float   getMin_y(void);
    float   getStep(void);

    string    getEquation(void);
    errorType getEquationError(void);
    errorType getErrorConfig(void);

    string    getXaxisLabel(void);
    string    getYaxisLabel(void);


	vector<double> getXvalues(void);
	vector<double> getYvalues(void);


};

