/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Drinks.cc
 *   Purpose:   Function implementations for entity class Drinks derived class of Recipe
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Drinks.h"

Drinks::Drinks(string n, string ing, string instr, Category cat, int alcohol, int fruit, int ctime)
:alcoholAmount(alcohol), fruitPercentage(fruit){
  name         = n;
  ingredients  = ing;
  instructions = instr;
  category     = cat;
  rating       = 0.0;
  makingTime   = 0;
}

/*
 * virtual destructor
 */

Drinks::~Drinks() {}

/*
 * virtual function
 */
void Drinks::computeRating(){
  int htRate,ptRate,mtRate;
  if(alcoholAmount < 10){
    htRate = 5;
  }
  else
    htRate = 4;

  if(fruitPercentage > 75)
    ptRate = 5;
  else
    ptRate = 3;


  if (makingTime <20 && makingTime >2) {
    mtRate = 5;
  }else
    mtRate = 4;

  float r=(htRate*252 + ptRate*124 + mtRate*40 + 4.9*29 + 2.3*33) / (252+124+40+29+33);

  rating = r;

}

float Drinks::getRating(){
  return rating;
}
