#ifndef LIST_H
#define LIST_H

//-----------------------------------------------------------
//  Purpose:    Header file for the List class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <time.h>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// List data node definition
//-----------------------------------------------------------
class LNode
{
public:
    string Value;
    LNode* Next;
    LNode* Prev;
};

//-----------------------------------------------------------
// Define the List class interface 
//-----------------------------------------------------------
class List
{
public:
    // Constructors
    List();
    List(const List& list);
    ~List();

    // Methods
    bool InsertHead(string value);
    bool InsertTail(string value);
    bool SortedInsert(string value);
    bool Search(string value);
    int Size();
    bool Delete(string value);
    void Print();
    bool IsEmpty();

private:
    LNode* Head;
    LNode* Tail;
};

#endif
