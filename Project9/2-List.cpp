#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{       
 length = 0;
 head = NULL;
}

List::~List(){
    for(int i = 0; i < length; i++){
        List::DeleteItemH();
    }
    head = NULL;
    length = 0;
}

//Tested, works
void List::PutItemH(const itemType itemIn){
    node* temp = new node;
    temp->item = itemIn;
    temp->next = head;
    head = temp;
    length++;
    temp = NULL;
}

//no way i did this wrong
itemType List::GetItemH() const{
    return head->item;
}

//untested
void List::DeleteItemH(){
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    length--;
}

//untested
bool List::IsEmpty() const{
    if(head == NULL){
        return true;
    }
    return false;
}

//No way I could mess this up
int List::GetLength() const{
    return length;
}

//Tested, works but idk if im couting it right
void List::Print() const{
    node* traverse = head;
    for(int i = 0; i < length; i++){
        cout << traverse->item << " ";
        traverse = traverse->next;
    }
    cout << endl;
    traverse = NULL;
}

//Tested, works
int List::Find(const itemType target) const{
    node* traverse = head;
    int foundCount = 0;
    for(int i = 0; i < length; i++){
        if(traverse->item == target){
            foundCount++;
        }
        traverse = traverse->next;
    }
    traverse = NULL;
    return foundCount;
}

//untested
//what if we keep deleting thing past head
//somethings fucked
int List::DeleteItem(const itemType target){
    node* lagTraverse = head;
    node* leadTraverse = head->next;
    node* temp;
    int delCount = 0;
    for(int i = 0; i < length - 1; i++)
    {
        //case deleting inbetween head and tail
        if((leadTraverse->item == target) && (leadTraverse->next != NULL))
        {
            temp = leadTraverse;
            leadTraverse = leadTraverse->next;
            delete temp;
            temp = NULL;
            lagTraverse->next = leadTraverse;
            length--;
            delCount++;
        }
        //case deleting the tail
        else if((leadTraverse->item == target) && (leadTraverse->next == NULL))
        {
            delete leadTraverse;
            leadTraverse = NULL;
            lagTraverse-> next = NULL;
            delCount++;
            length--;
        }
        //case deleting the head
        else if(lagTraverse->item == target)
        {
            DeleteItemH();
            delCount++;
            length--;
            lagTraverse = leadTraverse;
            leadTraverse = leadTraverse->next;
        }
        //traverse the list
        else
        {
            lagTraverse = leadTraverse;
            leadTraverse = leadTraverse->next;
        }
        
    }
    lagTraverse = NULL;
    leadTraverse = NULL;
    temp = NULL;
    return delCount;
}