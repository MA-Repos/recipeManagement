/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Llist.h
 *   Purpose:   Class definition of Collection class -Linked list containing Recipe data
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Oct. 7, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LLIST_H_
#define LLIST_H_
#include "Recipe.h"
#include <cstdlib>
#include <stdio.h>

template <class T>
class Llist{

    class Node{
        friend class Llist;
      private:
        T* 	data;
        Node*   next;
        Node*		prev;
    };

  public:
    Llist();
    ~Llist();
    int getSize();
    int add(T*);
    bool remove(T*);
    T* getRecipe(int);
    Llist& operator+=(T&);
    Llist& operator-=(T&);
    Llist& operator+=(Llist& recipes);
    Llist& operator-=(Llist& recipes);


  private:
    Node* head;
    Node* tail;
    int size;

};

template <class T>
Llist<T>::Llist():size(0)
{
    head=0;
    tail=0;
}

/*
 * copy constructor
 */

/*Destructor
 * deallcate's whole Linked list
 */
template <class T>
Llist<T>::~Llist()
{
    Node* currNode = head;
    Node* nextNode;

    while (currNode != 0) {
      //Deallocate data and then the Node for the whole list
      if(currNode->data !=0)
        delete currNode->data;
      nextNode = currNode->next;
      delete currNode;
      currNode = nextNode;
    }
}
template <class T>
int Llist<T>::getSize(){
    return size;
}

/*
 * add(): add's a recipe to node and then Node to linked list
 * input: Recipe*
 * return: int (Indicate's if add was successful or not)
 */
template <class T>
int Llist<T>::add(T* recipe)
{
    Node* newNode= new Node;
    newNode->data =recipe;
    newNode->prev = 0;
    newNode->next = 0;
    Node* tmpPrevNode;//Temporary Previous Node

    Node* currNode;
    bool found;
    currNode= head;

    // if list is empty
    if(head == 0){
      head = newNode;
      tail = head;
      size++;
      return C_OK;
    }

    currNode = head;
    found = false;
    //find position alphabetically
    while (currNode != 0 && !found){
      if (currNode->data->getName() >= recipe->getName()){
        found = true;
      }
      else{
        tmpPrevNode = currNode;
        currNode = currNode->next;
      }
    }
    //If position is supposed to first (alphabetically)
    if (currNode == head){

      head->prev = newNode;
      newNode->next = head;
      head = newNode;
      size++;
    }
    else{
      if(currNode != 0){
        tmpPrevNode->next = newNode;
        newNode->prev = tmpPrevNode;
        newNode->next = currNode;
        currNode->prev = newNode;

      }else{
        tmpPrevNode->next = newNode;
        newNode->prev =tmpPrevNode;
        tail = newNode;
      }
      size++;
    }

    return C_OK;
}

/*
 * remove(): remove's the corresponding recipe and Node containing recipe from linked list
 * input: Recipe*
 * return: bool (Indicate's if add was successful or not)
 */
template <class T>
bool Llist<T>::remove(T* recipe)
{
    Node *currNode;
    Node *tmpPrevNode;

    bool found;
    //If list is empty
    if (head == 0)
      return false;

    //if head recipe is the one we are looking for
    if (head->data->getName() == recipe->getName()){
      currNode = head;
      head = head->next;
      if (head != 0)
        head->prev = 0;
      else
        tail = 0;

      size--;
      if(currNode->data !=0)
        delete currNode->data;
      delete currNode;
    }
    else{
      found = false;
      currNode = head;

      while (currNode != 0 && !found){
        if (currNode->data->getName() >= recipe->getName())
          found = true;
        else
          currNode = currNode->next;
      }
      if (currNode == 0)
        return false;

      //If the recipe we are looking for is currNode
      if (currNode->data->getName() == recipe->getName()){
        tmpPrevNode = currNode->prev;
        tmpPrevNode->next = currNode->next;

        if (currNode->next != 0)
          currNode->next->prev = tmpPrevNode;

        if (currNode == tail)
          tail = tmpPrevNode;

        size--;

        //delete the data and then the node
        if(currNode->data !=0)
          delete currNode->data;

        delete currNode;
      }
      else
        return false;
    }
    return true;
}

/*
 * getRecipe(): Search linked list by index
 * input: int (index)
 * return: Recipe*
 */
template <class T>
T* Llist<T>::getRecipe(int index)
{
    int i=0;
    Node *currNode;
    currNode = head;
    while (currNode != 0){
      //Search the list and get the data by index
      if (index == i)
        return currNode->data;
      else{
        currNode = currNode->next;
        i++;
      }
    }
    return 0;
}

/*
 * operator+=: adds a recipe to list
 * input: Recipe&
 * return: Llist&
 */
template <class T>
Llist<T>& Llist<T>::operator+=(T& recipe){

    if(&recipe !=0)
      add(&recipe);

    return *this;
}
/*
 * operator-=: removes a recipe to list
 * input: Recipe&
 * return: Llist&
 */

template <class T>
Llist<T>& Llist<T>::operator-=(T& recipe){

    if(&recipe != 0)
      remove(&recipe);

    return *this;
}

/*
 * operator+=: adds a list of recipes to the list
 * input: Llist&
 * return: Llist&
 */
template <class T>
Llist<T>& Llist<T>::operator+=(Llist<T>& recipes){

    for(int i=0; i<recipes.getSize();i++){
      add(recipes.getRecipe(i));
    }

    return *this;
}

/*
 * operator-=: removes a list of recipes to the list
 * input: Llist&
 * return: Llist&
 */
template <class T>
Llist<T>& Llist<T>::operator-=(Llist<T>& recipes){
    bool success=false;

    if(&recipes != 0){
      for(int i=0; i<recipes.getSize();i++){
        T *rec=recipes.getRecipe(i);
        if(rec != 0)
          success = remove(rec);
        if(success)
          recipes.remove(rec);
      }
    }
    return *this;
}


#endif /* LLIST_H_ */
