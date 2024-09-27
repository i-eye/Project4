//----------------------------------------------
// Purpose: Implement simple List class.
// Author:  John Gauch
//----------------------------------------------

#include "list6.h"

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List()
{
    Head = NULL;
    Tail = NULL;
}

//----------------------------------------------
// Constructor function. 
//----------------------------------------------
List::List(const List& list)
{
    // Create first node
    LNode* copy = new LNode();
    Head = copy;

    // Walk list to copy nodes
    LNode* ptr = list.Head;
    while (ptr != NULL)
    {
        copy->Next = new LNode();
        copy = copy->Next;
        copy->Value = ptr->Value;
        copy->Next = NULL;
        Tail = copy;
        ptr = ptr->Next;
    }
    // Tidy first node
    copy = Head;
    Head = copy->Next;
    delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
List::~List()
{
    // Walk list to delete nodes
    while (Head != NULL)
    {
        LNode* ptr = Head;
        Head = Head->Next;
        delete ptr;
    }
    Head = NULL;
    Tail = NULL;
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertHead(string value)
{
    // Create new node
    LNode* ptr = new LNode();
    ptr->Value = value;
    ptr->Next = Head;
    ptr->Prev = NULL;

    // Insert new node
    if (Head == NULL)
        Tail = ptr;
    else
        Head->Prev = ptr;
    Head = ptr;
    return true;
}

//----------------------------------------------
// Insert data into linked list. 
//----------------------------------------------
bool List::InsertTail(string value)
{
    // Create new node
    LNode* ptr = new LNode();
    ptr->Value = value;
    ptr->Next = NULL;
    ptr->Prev = Tail;

    // Insert new node
    if (Tail == NULL)
        Head = ptr;
    else
        Tail->Next = ptr;
    Tail = ptr;
    return true;
}

//----------------------------------------------
// Insert data into linked list. 
//----------------------------------------------
bool List::SortedInsert(string value)
{
    // see if value is already in the list
    // tested to be faster than checking while in the insert
    // not sure how this is the case because it would have to walk the list twice
    // but data doesn't lie
    if (Search(value)) {
        return false;
    }
    // Create new node
    LNode* ptr = new LNode();
    ptr->Value = value;
    ptr->Next = NULL;
    ptr->Prev = NULL;

    // Insert into empty list
    if (Head == NULL)
    {
        Head = ptr;
        Tail = ptr;
    }

    // Insert before head
    else if (value <= Head->Value)
    {
        ptr->Next = Head;
        Head->Prev = ptr;
        Head = ptr;
    }

    // Insert after tail
    else if (value >= Tail->Value)
    {
        ptr->Prev = Tail;
        Tail->Next = ptr;
        Tail = ptr;
    }

    // Insert in middle
    else
    {
        // Walk list to deletion point
        LNode* curr = Head;
        while ((curr != NULL) && (curr->Value < value))
            curr = curr->Next;

        // Connect node to list
        ptr->Next = curr;
        ptr->Prev = curr->Prev;
        curr->Prev->Next = ptr;
        curr->Prev = ptr;
    }
    return true;
}

//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool List::Search(string value)
{
    // Walk list to find node
    LNode* ptr = Tail;
    while ((ptr != NULL) && (ptr->Value != value))
        ptr = ptr->Prev;
    return (ptr != NULL);
}

int List::Size() 
{
    LNode* ptr = Head;
    int size = 0;
    while ((ptr != NULL)) {
        ptr = ptr->Next;
        //cout << "size++\n";
        size++;
    }
    return size;

}

//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool List::Delete(string value)
{
    // Walk list to deletion point
    LNode* curr = Head;
    while ((curr != NULL) && (curr->Value != value))
        curr = curr->Next;

    // Check if value was found
    if (curr == NULL)
        return false;

    // Connect previous node to next node
    if (curr == Head)
        Head = curr->Next;
    else
        curr->Prev->Next = curr->Next;

    // Connect next node to previous node
    if (curr == Tail)
        Tail = curr->Prev;
    else
        curr->Next->Prev = curr->Prev;

    // Delete node from list
    delete curr;
    return true;
}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void List::Print()
{
    LNode* ptr = Head;
    while (ptr != NULL)
    {
        cout << ptr->Value << endl;
        ptr = ptr->Next;
    }
}

//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool List::IsEmpty()
{
    return (Head == NULL);
}
