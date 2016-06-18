/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Pizza.cc
 *   Purpose:   Function implementations for entity class Pizza derived class of Recipe
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Pizza.h"

Pizza::Pizza(string n, string ing, string instr, Category cat, int rht,int ptype, int ctime)
:reheatTime(rht),pizzaType(ptype){
  name         = n;
  ingredients  = ing;
  instructions = instr;
  category      = cat;
  rating = 0.0;
  makingTime= ctime;
}

/*
 * virtual destructor
 */
Pizza::~Pizza() {}

/*
 * virtual function
 */
void Pizza::computeRating(){

  int htRate,ptRate,mtRate;
  if(reheatTime < 15){
    htRate = 5;
  }
  else
    htRate = 4;

  if(pizzaType==0)
    ptRate = 5;
  else
    ptRate = 4;


  if (makingTime <20 && makingTime >2) {
    mtRate = 5;
  }else
    mtRate = 4;

  float r=(htRate*252 + ptRate*124 + mtRate*40 + 4.5*29 + 1.8*33) / (252+124+40+29+33);

  rating = r;

}

float Pizza::getRating(){
  return rating;
}

