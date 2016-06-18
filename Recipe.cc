/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Recipe.cc
 *   Purpose:   Function implementations for Entity class Recipe
 *              contains Recipe data
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Nov. 15, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Recipe.h"

Recipe::Recipe(string n, string ing, string instr, Category cat)
{
  name         = n;
  ingredients  = ing;
  instructions = instr;
  category		 = cat;
  makingTime   = 0;
  rating       = 0.0;

}

string    Recipe::getName()         { return name; }
string    Recipe::getIngredients()  { return ingredients; }
string    Recipe::getInstructions() { return instructions; }
Category  Recipe::getCategory()     { return category; }

/*
 * Overloaded output stream << operator
 */
ostream& operator<<(ostream &output,Recipe &recipe){

  output<< "Recipe Ingredients "      <<endl;
  output<< recipe.getIngredients()    <<endl;
  output<< "Instructions "            <<endl;
  output<< recipe.getInstructions()   <<endl;
  output<< "Category"                 <<endl;
  Category category=recipe.getCategory();

  switch(category){

  case MAIN_COURSE:
    output<<"  Main Course"  <<endl;
    break;
  case APPETIZER:
    output<<"  Appetizer"    <<endl;
    break;
  case DESSERT:
    output<<"  Dessert"      <<endl;
    break;
  case PASTA:
    output<<"  Pasta"        <<endl;
    break;
  case DRINK:
    output<<"  Drink"        <<endl;
    break;
  default:
    output<<"  No Category"  <<endl;
    break;
  }

  return output;

}
//Category enum is in defs.h

void Recipe::setName(string n){
  name = n;
}
Recipe::~Recipe(){
}

void Recipe::setIngerdients(string ing){
  ingredients = ing;

}
void Recipe::setInstructions(string inst){
  instructions = inst;

}
void Recipe::setCategory(Category cat){
  category = cat;
}



