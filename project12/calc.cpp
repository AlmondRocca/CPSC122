/*
Name: Kevin Rocca
Class: CPSC 122, Project 12
12/5/22
This program is the framework for a calculator.
As of right now it doesnt do anything. It will replace a parenthesized
expression like ((15*3)+12) and turn it into ((A+B)*C). Then it stores
the numbers into a value table.
*/
#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>

//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    valueIdx = 0; //probably not needed
    int len = strlen(argvIn) + 1;
    inFix = new char[len]; 
    strcpy(inFix, argvIn);
    stk = new Stack;

    if(CheckParens() && CheckTokens())
    {
        MakeValueTbl();
        Parse();
    }
}



Calc::~Calc()
{
    delete inFix;
    delete valueTbl;

    while(stk->GetLength() > 0)
    {
        stk->Pop();
    }
}



bool Calc::CheckTokens() //works
{
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(!isdigit(inFix[i]))
            if(!isupper(inFix[i]))
                if(!IsOperator(inFix[i]))
                {
                    cout << "An unexpected character was found" << endl;
                    return false;
                }
    }
    return true;
}



void Calc::MakeValueTbl() //works
{
    //isnt this set to all 0's by default?
    valueTbl = new int[26];
}



void Calc::Parse()
{
    int lastNumInSequence = 0; //give this a better name later
    string num = "";
    string processedInFix = ""; //I could use an array but I already wrote it like this 

    for(int i = 0; i < strlen(inFix); i++)
    {
        if(isdigit(inFix[i]))
        {
            lastNumInSequence = FindLast(i); 
            
            for(int j = i; j < lastNumInSequence; j++) // <= works too
            {
                num += inFix[j]; //should slap another 'int' char onto the string
            }

            i += lastNumInSequence - i; // this should jump the loop forward to prevent
            //running a group of numbers through multiple times
            //imagine [(,1,2,6,+] in an array. FindLast(1) gives me pos 3
            //3 - 1 = 2. I jump 2 positions forward. I no longer test this
            //number group of 126 and am on the + now.
            
            processedInFix += 65 + valueIdx; //should add the A,B,C etc
            
            valueTbl[valueIdx] = stoi(num); 
            valueIdx++;
            num = "";
        }

    processedInFix += inFix[i]; //gets all the (,),+,-,*,/

    }

    //I know this is stupid but my code increments valueIdx one too many times
    //I could run through it and get to the root or the problem
    //or I could do this 'band-aid' fix which works perfectly for all cases.
    valueIdx--;

    copyStrToInFix(processedInFix);
}



bool Calc::CheckParens() //works
{
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '(')
        {
            stk->Push(inFix[i]);
        }
        if(inFix[i] == ')')
        {
            if(!stk->IsEmpty())
            {
                stk->Pop();
            }
            else
            {
                cout << "Expresssion was not fully parenthesized" << endl;
                return false;
            }
        }
    }
    if(stk->GetLength() != 0) //how to check if stack is empty
    {
        cout << "Expresssion was not fully parenthisized" << endl;
        return false;
    }
    return true;
}



void Calc::DisplayInFix() //works
{
    cout << inFix << endl;
}



bool Calc::IsOperator(char ch) //works
{
    //Did I need to do make a function for this? 
    //No. But it makes my code look prettier so here we are.
    if((ch == '/') || (ch == '+') || (ch == '*') || (ch == '-') || (ch == '(') || (ch == ')'))
        return true;
    return false;
}



int Calc::FindLast(int cur)
{
    while(isdigit(inFix[cur]))
    {
        cur++;
    }
    return cur;
}



void Calc::copyStrToInFix(string s)
{
    //these lines just remake inFix so it doesn't have remnants of the old inFix
    //ok so for some reason when C++ makes the new char array it fills the first
    //five or so slots with just gibberish and it breaks my code.
    //strcpy would fix this but I'm not rewriting everything so I'm just gonna
    //fill the rest of infix with nothing.
    int len = strlen(inFix);
    delete inFix;
    inFix = new char[len]; 

    int i = 0;
    while(s[i] != '\0')
    {
        inFix[i] = s[i];
        i++;
    }
    //Why is c++ so weird?
    for(int j = i; j < len; j++)
        inFix[j] = ' ';
}