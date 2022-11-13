/*
Name: Kevin Rocca
Class: CPSC 122
Date Submitted: 11/13/22
Assignment: Project 9 
Description: This file is a tester for all the functions in 2-list.cpp
*/
#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 List lst;
 List* lst1 = new List;

/*
 cout << "Test GetItemH & PutItemH" << endl;
 cout << "Correct if it returns the item at the head, 1 in this case" << endl;
 lst.PutItemH(1);
 cout << "Item at the head is " << lst.GetItemH();
*/

/*
 cout << "Test IsEmpty" << endl;
 cout << "Correct if it deletes the item at the head, display should give 2 3" << endl;
 lst1->PutItemH(3);
 lst1->PutItemH(2);
 lst1->PutItemH(1);
 cout << "List before ";
 lst1->Print();
 lst1->DeleteItemH();
 cout << "List after ";
 lst1->Print();
*/

/*
 cout << "Test IsEmpty" << endl;
 cout << "Correct if it returns true (1) in this case" << endl;
 cout << lst.IsEmpty();
*/

/*
 cout << "Test GetLength" << endl;
 cout << "Correct if it returns the length of the list, 0 this time" << endl;
 cout << lst.GetLength();
*/

/*
 cout << "Test Dynamic Insert and Print" << endl;
 cout << "Correct if out is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(i);
   lst1->Print();
*/

/*
 cout << "Test Find" << endl;
 cout << "Correct if it returns the number of targets in the list" << endl;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(i);
 cout << "Found " << lst1->Find(4) << " instances of target" << endl;
*/

/*
 cout << "Test DeleteItem" << endl;
 const int LOOKFOR = 4;
 cout << "Correct if it returns " << lst1->Find(LOOKFOR) << endl;
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 cout << "List before: ";
 lst1->Print();
 cout << "Deleted " << lst1->DeleteItem(LOOKFOR) << " items" << endl;
 cout << "list after: ";
 if(lst1->GetLength() != 0){
  lst1->Print();
 }
 else{
  cout << "Your List is too short to print out post deletion, sorry" << endl;
 }
*/

 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 return 0;
}
