/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      RecipeManager.h
 *   Purpose:   Class definition for control class RecipeManager;
 *              contains UI ,Recipe array
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Oct. 6, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include "defs.h"
#include "UImanager.h"
#include "Llist.h"

class RecipeManager {
  public:
    RecipeManager();
    ~RecipeManager();
    void launch();


  private:
    void addRecipesOption();
    void viewRecipesOption();
    void removeOption();
    void ratingOption();
    UImanager     *view;
    Llist<Recipe>   *recipeList;


};

#endif

