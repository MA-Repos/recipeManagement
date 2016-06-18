/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      RecipeManager.cc
 *   Purpose:   Function implementations for Control class RecipeManager
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Nov. 15, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include "RecipeManager.h"

using namespace std;

RecipeManager::RecipeManager()
{
  recipeList = new Llist<Recipe>;
  view	     = new UImanager;
}

/*Destructor
 * deallcate's view and array
 */
RecipeManager::~RecipeManager()
{
  delete view;
  delete recipeList;

}

/*
 * launch(): to start
 * manages user input
 * return: void
 */
void RecipeManager::launch()
{
  int     choice;
  while (1) {
    choice = -1;
    view->mainMenu(&choice);

    if (choice == 0) {
      return;
    }
    else if (choice == 1) {
      addRecipesOption();
    }
    else if (choice == 2) {
      view->printRecipes(recipeList);

    }
    else if (choice == 3) {
      viewRecipesOption();
    }
    else if (choice == 4) {
      removeOption();
    }
    //Print by Category
    else if (choice == 5) {
      ratingOption();
    }

    view->pause();
  }
}

void RecipeManager::addRecipesOption(){
  int numOfRecipes = -1;
  view->getNumofRecipes(&numOfRecipes);
  if(numOfRecipes==1){


    Recipe *nR = view->getRecipeData();


    //overloaded += operator with parameter Recipe& is used
    *recipeList += *nR;
  }
  else if(numOfRecipes>1){

    int n=1;

    while(numOfRecipes>0){
      view->printNRecipes(&n);
      Recipe *nR = view->getRecipeData();

      //overloaded += operator with parameter Recipe& is used
      *recipeList += *nR;
      numOfRecipes--;
      n++;
    }
  }
}


void RecipeManager::viewRecipesOption(){
  bool found = false;
  string name;
  // get name for Recipe search
  view->getRecipeName(&name);
  for(int i=0; i< recipeList->getSize();++i){
    Recipe *rec=recipeList->getRecipe(i);
    if(rec->getName() == name){

      // overloaded << operator is used
      cout << *rec;
      found = true;
    }
  }
  if(!found)
    view->printNotFound(&name);
}

void RecipeManager::removeOption(){
  //Remove the Recipe from the Llist
  bool removed = false;
  string  name;
  int numOfRecipes= -1;
  view->getNumofRecipes(&numOfRecipes);

  if(numOfRecipes==1){
    view->getRecipeName(&name);
    for(int i=0; i< recipeList->getSize();++i){
      Recipe *rec=recipeList->getRecipe(i);
      if(rec->getName() == name){

        //overloaded -= operator with parameter Recipe& is used
        *recipeList -= *rec;
        removed = true;
      }
    }
    if(removed)
      view->printRemoveSuccessful(&name);
    else
      view->printNotFound(&name);
  }
  else if(numOfRecipes>1){
    int n=1;

    while(numOfRecipes>0){
      string name;
      view->printNRecipes(&n);
      view->getRecipeName(&name);
      for(int i=0; i< recipeList->getSize();++i){
        Recipe *rec=recipeList->getRecipe(i);
        if(rec->getName() == name){

          //overloaded -= operator with parameter Recipe& is used
          *recipeList -= *rec;
          removed = true;
        }
      }
      numOfRecipes--;
      n++;

    }
  }
}

/*
 * Rating of each recipe based on makingTime and 2 data members
 */
void RecipeManager::ratingOption(){

  for(int i=0; i< recipeList->getSize();++i){
    Recipe *rec=recipeList->getRecipe(i);
    rec->computeRating();
    float rate= (float)rec->getRating();
    view->printRating(rate,rec->getName());
  }
}
