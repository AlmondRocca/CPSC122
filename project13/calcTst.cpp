/*
Name: Kevin Rocca
Class: CPSC 122, Project 12
12/6/22
This program is a calculator.
It replaces a parenthesized expression like ((15*3)+12) and turns it into 
((A+B)*C). Then it stores the numbers into a value table. After this
it turns the equation into a postfix form AB+C*. Then it evaluates
it and returns the result.
*/
#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argv[1]);
 C->DisplayInFix();
 C->DisplayPostFix();
 cout << C->Evaluate() << endl;

 delete C;
 return 0;
}
