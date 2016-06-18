/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      UIManager.h
 *   Purpose:   Class definition for UI class UIManager;
 *              Get User input and prints the output
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Oct. 6, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Llist.h"
#include "Burger.h"
#include "Pasta.h"
#include "Pizza.h"
#include "Drinks.h"


#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    Recipe* getRecipeData();
    void printRecipes(Llist<Recipe>*);
    void pause();
    void getRecipeName(string*);
    void printByCategory(int*);
    void printNotFound(string*);
    void printRemoveSuccessful(string*);
    void getNumofRecipes(int*);
    void printNRecipes(int*);
    void printRating(float , string);

  private:
    int getInt();
    void getKindOfRecipe(int*);
};

#endif

