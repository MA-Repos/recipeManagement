/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Drinks.h
 *   Purpose:   Class definitions of entity class Drinks (derived class of Recipe)
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef DRINKS_H_
#define DRINKS_H_
#include "Recipe.h"


class Drinks:public Recipe {
  public:
    Drinks(string , string , string , Category,int, int,int );
    virtual ~Drinks();
    virtual void computeRating();
    virtual float getRating();

  private:
    int alcoholAmount;
    int fruitPercentage;
};

#endif /* DRINKS_H_ */
