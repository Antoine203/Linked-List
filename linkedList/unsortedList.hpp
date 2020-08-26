//
//  unsortedList.hpp
//  linkedList
//
//  Created by Antoine Smith on 9/10/19.
//  Copyright © 2019 Antoine Smith. All rights reserved.
//

#ifndef unsortedList_hpp
#define unsortedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <class ItemType>
struct node
{
    ItemType data;
    node<ItemType>* next;
};

template <class ItemType>
class unsortedList
{
private:
    node<ItemType>* listData;
    int length;
    node<ItemType>* currentPos;
    bool head = false;
public:
    unsortedList();
    void makeEmpty();
    bool isFull();
    int getLength();
    
    bool findItem(ItemType item);
    void putItem(ItemType item);
    void deleteItem(ItemType item);
    void resetList();
    ItemType getNextItem();
    void printList();
};

template <class ItemType>
unsortedList<ItemType>::unsortedList()
//Class constructor Initializes attributes
{
    length = 0;
    listData = NULL;
}

template <class ItemType>
bool unsortedList<ItemType>::isFull()
//Returns True if there is no room for another node
//Else Returns False
{
    node<ItemType> *location;
    try
    {
        location = new node<ItemType>;
        // Creating a new node to see if there is space, if then delete it because it is not needed
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
int unsortedList<ItemType>::getLength()
// Number of items in the list is returned.
{
    return length;
}

template <class ItemType>
void unsortedList<ItemType>::makeEmpty()
// Emptying your memory
{
    node<ItemType>* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData -> next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
void unsortedList<ItemType>:: putItem(ItemType item)
// Item added to the list and length incremented
{
    node<ItemType> * location; // Declare a pointer to a node
    location = new node<ItemType>; // Get a new node
    location->data = item; // Store the item in the node
    location->next = listData; // Store address of first node in the next field of the new node
    
    listData = location; // Store address of new node into the listData
    
    length++; // Increment the length of the list
}

template <class ItemType>
bool unsortedList<ItemType>:: findItem(ItemType item)
// You go through the list and if found return a copy otherwise item is returned.
{
    bool moreToSearch;
    node<ItemType>* location;
    location = listData;
    bool found = false;
    moreToSearch = (location != NULL);
    
    while(moreToSearch && !found)
    {
        if(item == location->data)
        {
            found = true;
            item = location ->data;
            break;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
    return found;
}

template <class ItemType>
void unsortedList<ItemType>:: deleteItem(ItemType item)
// An element in the list that has a key that matches
// is found and delete
{
    node<ItemType> * location;
    node<ItemType> * tempLocation;
    
    location = listData;
    bool foundItem = false;
    
    //Locate the node to be deleted
    if (item == location ->data)
    {
        foundItem = true;
        tempLocation = location;
        listData = listData -> next;
    }
    else
    {
        while( item != (location -> next -> data))
        {
            location = location -> next;
        }
        if (location != NULL) {
            foundItem = true;
        }
        tempLocation = location -> next;
        location -> next = (location -> next) ->next;
        
    }
    if(foundItem)
    {
        delete tempLocation;
        length--;
    }
}

template <class ItemType>
void unsortedList<ItemType>:: resetList()
// Current position is changed to the list data
{
    currentPos = listData;
}

template <class ItemType>
ItemType unsortedList<ItemType>::getNextItem()
// A copy of the next item in the list.
// When the end of the list is reached currentPos is reset to begin.
{
    if(currentPos == NULL){
         currentPos = listData;
    }
    else if(head == false){
        head = true;
    }
    else{
        currentPos = currentPos-> next;
    }
    return currentPos->data;
}

template <class ItemType>
void unsortedList<ItemType>:: printList()
// Prints the data of each item in the same order as in the list
{
    int len;
    ItemType item;
    resetList();
    len = getLength();
    
    for(int i = 0; i < len; i++)
    {
        item = getNextItem();
        cout << item <<" ";
    }
    cout<<endl;
}

#endif /* unsortedList_hpp */
