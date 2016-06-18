/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Burger.cc
 *   Purpose:   Function implementations for entity class Burger derived class of Recipe
 *   Author:     Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Burger.h"

Burger::Burger(string n, string ing, string instr, Category cat, int p, int c, int ctime):proteinAmount(p),calories(c){
  name         = n;
  ingredients  = ing;
  instructions = instr;
  category     = cat;
  rating       = 0.0;
  makingTime   = ctime;

}

/*
 * virtual destructor
 */
Burger::~Burger() {
}

/*
 * virtual function
 */
void Burger::computeRating(){
  int htRate,ptRate,mtRate;
  if(proteinAmount < 15){
    htRate = 5;
  }
  else
    htRate = 3;

  if(calories < 400)
    ptRate = 5;
  else
    ptRate = 2;


  if (makingTime <20 && makingTime >2) {
    mtRate = 5;
  }else
    mtRate = 4;

  float r=(htRate*252 + ptRate*124 + mtRate*40 + 2.7*29 + 4.6*33) / (252+124+40+29+33);

  rating = r;
}

float Burger::getRating(){
  return rating;
}

