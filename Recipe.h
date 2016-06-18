/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Recipe.h
 *   Purpose:   Class definition for Recipe;
 *              contains Recipe data
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Oct. 6, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include <ostream>

using namespace std;

#include "defs.h"

class Recipe {
    friend ostream& operator<<(ostream&, Recipe&);
  public:

    Recipe(string="", string="", string="", Category=MAIN_COURSE);
    virtual ~Recipe();
    string  getName();
    void setName(string);
    string  getIngredients();
    string  getInstructions();
    Category getCategory();
    void setIngerdients(string);
    void setInstructions(string);
    void setCategory(Category);

//pure virtual functions will make this class abstract
    virtual void computeRating()=0;
    virtual float getRating()=0;

  protected:
    string    name;
    string    ingredients;
    string    instructions;
    Category  category; //Category enum is in defs.h
    float     rating;
    int       makingTime;
};

#endif

