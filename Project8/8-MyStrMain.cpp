/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

/*
 //Test of myDisplay
 cout << "*****Test myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 //End Test of myDisplay
*/

/*
 //Test of isEqual
 cout << "*****Test isEqual*****" << endl;
 cout << "static test" << endl;
 char const* test = "hi there";
 bool test2 = str1.isEqual(test);
 if(test2 == 0){
  cout << "false" << endl;
 }
 else{
    cout << "true" << endl;
 }
 //End Test of isEqual
*/

/*
 //Test of myStrcpy
 cout << "*****Test myStrcpy*****" << endl;
 cout << "static test" << endl;
 cout << "output should be whatever is in test below" << endl;
 char const* test = "replaced?";
 str1.myDisplay();         
 str1.myStrcpy(test);
 str1.myDisplay();
 //End Test of myStrcpy
*/

/*
 //Test of myStrlen
 cout << "*****Test myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be length of command line input" << endl;
 cout << str2->myStrlen() << endl;
 cout << endl;
 //End Test of myStrlen
*/

/*
 //Test of find and isSub since they work together.
 cout << "*****Test find and isSub*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the starting position of the substring" << endl;
 cout << "finding 'low' in 'swallow' should return 4" << endl;
 cout << str1.find("low") << endl;
 //End Test of find and isSub
*/


 //Test of concat
 cout << "*****Test concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be command input and whatever is in here" << endl;
 str2->myDisplay();
 str2->concat("added on");
 str2->myDisplay();
 //End Test of concat


 delete str2;
 return 0;  
}
   
  
