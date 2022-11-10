#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
 //Static list 
 ListT lst;
 ListT* lst1 = new ListT;

/*
 cout << "Test Display" < endl;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
*/

/*
 cout << "Test PutItemH & GetItemH & GetItemT" << endl;
 cout << "correct if tail and head are 1" << endl;
 lst.PutItemH(1);
 lst.Print();
 cout << lst.GetItemH() << endl;
 cout << lst.GetItemT() << endl;
*/

/*
 cout << "Test DeleteItemH && PutItemH" << endl;
 cout << "correct if list is empty (equals 0)" << endl;
 lst.PutItemH(1);
 lst.DeleteItemH();
 cout << lst.GetLength() << endl;
*/

/*
 cout << "Test IsEmpty" << endl;
 cout << "correct if it returns true (1)" << endl;
 cout << lst.IsEmpty() << endl; 
*/

/*
 cout << "Test PutItemT" << endl;
 cout << "Correct if head & tail both = 1 (special case)" << endl;
 lst.PutItemT(1);
 cout << lst.GetItemT() << endl;
 cout << lst.GetItemH() << endl;
 cout << endl;
 cout << "correct if head = 1 and tail = 2" << endl;
 lst.PutItemT(2);
 cout << lst.GetItemT() << endl;
 cout << lst.GetItemH() << endl;
*/

/*
 cout << "Test DeleteItemT" << endl;
 cout << "correct if tail points to the new tail and the old tail node is deleted" << endl;
 cout << "in this case it should print out 1" << endl;
 lst.PutItemH(2);
 lst.PutItemH(1);
 cout << "before" << endl;
 lst.Print();
 lst.DeleteItemT();
 cout << "after" << endl;
 lst.Print();

 cout << endl;
 cout << "special case, list has 1 node" << endl;
 cout << "correct if list is empty after call (len = 0)" << endl;
 lst.DeleteItemT();
 cout << lst.GetLength() << endl;
*/

/*
 cout << "Test DeleteItem" << endl;
 cout << "correct if it returns 5 after deleting 5 nodes" << endl;
 lst.PutItemH(1);
 lst.PutItemH(4);
 lst.PutItemH(1);
 lst.PutItemH(4);
 lst.PutItemH(1);
 cout << lst.DeleteItem(4) << endl;

 cout << "correct if it returns 4 after deleting 4 nodes" << endl;
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 lst1->PutItemH(1);
 lst1->PutItemH(4);
 lst1->PutItemH(4);
 cout << lst1->DeleteItem(4) << endl;
 delete lst1;
 ListT* lst2 = new ListT;
 
 cout << "correct if it returns 2 after deleting 2 nodes" << endl;
 lst2->PutItemH(1);
 lst2->PutItemH(4);
 lst2->PutItemH(1);
 lst2->PutItemH(4);
 lst2->PutItemH(1);
 cout << lst2->DeleteItem(4) << endl;
*/
 delete lst1;
 cout << endl;
 return 0;

}
