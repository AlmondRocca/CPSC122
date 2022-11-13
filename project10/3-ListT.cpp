/*
Name: Kevin Rocca
Class: CPSC 122, Section 1
Date Submitted: 11/13/22
Assignment: Project 10
Description: Program implements a linked list both head and tail pointers
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

ListT::~ListT()
{
    for(int i = 0; i < length; i++){
        ListT::DeleteItemH();
    }
    head = NULL;
    tail = NULL;
    length = 0;
}

void ListT::PutItemH(itemType item)
{
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;

 head = tmp; 
 if (length == 0)
  tail = tmp;  
 length++;
}

void ListT::Print() const
{
 node* cur = head;
 while(cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

void ListT::DeleteItemH()
{
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    length--;
    if(length == 0)
        tail = NULL;
}

bool ListT::IsEmpty() const
{
    if(head == NULL)
        return true;
    return false;
}

int ListT::GetLength() const
{
    return length;
}

itemType ListT::GetItemH() const
{
    return head->item;
}

void ListT::PutItemT(const itemType itemIn)
{
    node* temp = new node;
    temp->item = itemIn;
    temp->next = NULL;
    if(length == 0)
    {
        head = temp;
        tail = temp;
        length++;
    }
    else{
    tail->next = temp;
    tail = temp;
    temp = NULL;
    length++;
    }
}

itemType ListT::GetItemT() const
{
    return tail->item;
}

void ListT::DeleteItemT()
{
    if(length >= 2)
    {
        node* temp;
        temp = ListT::PtrTo();
        temp->next = NULL;
        delete tail;
        tail = temp;
        temp = NULL;
        length--;
    }
    else //this is the case where the length is 1
    {
        delete tail;
        tail = NULL;
        head = NULL;
        length--;
    }
}

int ListT::FindItem(const itemType target) const
{
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

    if(traverse->item == target)
    {
        foundCount++;
    }
    traverse = NULL;
    return foundCount;
}

int ListT::DeleteItem(const itemType target)
{
    node* cur = head;
    int delCount = 0;
    while(cur->next != NULL)
    {
        //delete head nodes
        if(head->item == target)
        {
            ListT::DeleteItemH();
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
            //if we delete the tail node, it should point to the node before
            //the end
            tail = cur;
        }
        else
        {
            cur = cur->next;
        }
    }
    //special case, keep deleting head. exits prematurely
    if(head->item == target)
    {
        DeleteItemH();
        delCount++;
        //tail should be null because the list is empty
        tail = NULL;
    }
    cur = NULL;
    return delCount;
}

node* ListT::PtrTo()
{
    node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    return temp;
}

