/*
Name: Kevin Rocca
Class: CPSC 122
Date Submitted: 11/13/22
Assignment: Project 9 
Description: Program implements the linked list functions in 2-List.h
*/
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


void List::PutItemH(const itemType itemIn){
    node* temp = new node;
    temp->item = itemIn;
    temp->next = head;
    head = temp;
    length++;
    temp = NULL;
}


itemType List::GetItemH() const{
    return head->item;
}


void List::DeleteItemH(){
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    length--;
}


bool List::IsEmpty() const{
    if(head == NULL){
        return true;
    }
    return false;
}


int List::GetLength() const{
    return length;
}


void List::Print() const{
    node* traverse = head;
    while(traverse->next != NULL)
    {
        cout << traverse->item << " ";
        traverse = traverse->next;
    }
    cout << traverse->item << endl;
    traverse = NULL;
}


int List::Find(const itemType target) const{
    node* traverse = head;
    int foundCount = 0;
    while(traverse->next != NULL)
    {
        if(traverse->item == target)
        {
            foundCount++;
        }
        traverse = traverse->next;
    }
    //Similar issue to DeleteItem loop. It skips the last item 
    //Due to traverse->next equaling NULL before everything can be checked.
    //if statement fixes this
    if(traverse->item == target)
    {
        foundCount++;
    }
    traverse = NULL;
    return foundCount;
}


int List::DeleteItem(const itemType target){
    node* cur = head;
    int delCount = 0;
    while(cur->next != NULL)
    {
        //delete head nodes
        if(head->item == target)
        {
            DeleteItemH();
            cur = head;
            delCount++;
        }
        //delete middle nodes
        else if((cur->next->item == target) && (cur->next->next != NULL)){
            node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            temp = NULL;
            delCount++;
            length--;
        }
        //delete tail node
        else if((cur->next->item == target) && (cur->next->next == NULL))
        {
            delete cur->next;
            cur->next = NULL;
            delCount++;
            length--;
        }
        else
        {
            cur = cur->next;
        }
    }
    /*
    This deletes the head node in a case where the list is filled
    with only the target value. My code would keep calling the head
    node case which would set cur to point to the last node. This is
    would make cur->next = NULL which would prematurely exit the while
    loop. I tried to come with elegant ways to fix this but I couldn't.
    This extra if statement fixes that special case.
    */
    if(head->item == target)
    {
        DeleteItemH();
        delCount++;
    }
    cur = NULL;
    return delCount;
}
