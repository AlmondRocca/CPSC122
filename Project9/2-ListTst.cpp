#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 List lst;
 List* lst1 = new List;

/*
 cout << "Test Dynamic Insert and Print" << endl;
 cout << "Correct if out is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(i);
   lst1->Print();
*/

/*
 cout << "Test Find" << endl;
 cout << "Correct if it returns 1" << endl;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(i);
 cout << lst1->Find(2) << endl;
*/

 cout << "Test DeleteItem" << endl;
 cout << "Correct if out is 1" << endl;
 for(int i = 0; i < 5; i++)
   lst1->PutItemH(4);
 cout << lst1->DeleteItem(4) << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 return 0;
}
