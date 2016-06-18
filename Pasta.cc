/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Pasta.cc
 *   Purpose:   Function implementations for entity class Pasta derived class of Recipe
 *   Author:    Mir Abbas
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Pasta.h"

Pasta::Pasta(string n, string ing, string instr, Category cat, int sp, int htg, int ctime)
:spiceAmount(sp),here_Or_Togo(htg){

  name         = n;
  ingredients  = ing;
  instructions = instr;
  category      = cat;
  makingTime = ctime;
  rating = 0.0;
}

/*
 * virtual destructor
 */
Pasta::~Pasta() {}

/*
 * virtual function
 */
void Pasta::computeRating(){
  int htRate,ptRate,mtRate;
  if(spiceAmount < 15){
    htRate = 5;
  }
  else
    htRate = 3;

  if(here_Or_Togo==0)
    ptRate = 5;
  else
    ptRate = 3;


  if (makingTime <20 && makingTime >2) {
    mtRate = 5;
  }else
    mtRate = 4;

  float r=(htRate*252 + ptRate*124 + mtRate*40 + 2.9*29 + 1.3*33) / (252+124+40+29+33);

  rating = r;
}

float Pasta::getRating(){
  return rating;
}
