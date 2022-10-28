/*
Name: Kevin Rocca
Class: CPSC 122, Project 8
10/27/22
This progam is an implementation of the functions in 8-MyStr.h
*/
#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

MyString::MyString(char const* strIn)
{
 length = strlen(strIn);  //strlen function
 str = new char[length + 1];
 strcpy(str, strIn); //strlen function

}

MyString::~MyString()
{
 delete []str; 
}

void MyString::myDisplay()
{
 cout << str << endl;
}

int MyString::myStrLen(char const* strIn)
{
 int idx = 0;
 while (strIn[idx] != '\0')
  idx++;
 return idx;
}

int MyString::myStrlen()
{
 return myStrLen(str);
}


void MyString::myStrcpy(char const* strIn){
    int idx = 0;
    while(strIn[idx] != '\0'){
        str[idx] = strIn[idx];
        idx++;
    }
    for(int i = idx; i < length; i++){
        str[i] = '\0';
    }
}


bool MyString::isEqual(char const* strIn){
    int idx = 0;
    while(strIn[idx] != '\0'){
        if(strIn[idx] != str[idx]){
            return false;
        }
        idx++;
    }
    return true;
}


int MyString::find(char const* strIn){
    int returnPos = -1;
    int idx = 0;

    while(idx < length){
        if(strIn[0] == str[idx]){
            if(isSub(strIn, idx)){
                returnPos = idx;
                break;
            }
        }
        idx++;
    }
    return returnPos;
}


bool MyString::isSub(char const* strIn, int idx){
    int cur = 0;
    for(int i = idx; i < length; i++){
        if(strIn[cur] == '\0'){
            break;
        }
        if(!(strIn[cur] == str[i])){
            return false;
        }
        cur++;
    }
    return true;
}


void MyString::concat(char const* strIn){
    int idx = 0;
    while(strIn[idx] != '\0'){
        str[length + idx] = strIn[idx];
        idx++;
    }
    str[length + idx + 1] = '\0';
}