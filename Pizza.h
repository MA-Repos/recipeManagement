/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Pizza.h
 *   Purpose:   Class definitions of entity class Pizza (derived class of Recipe)
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PIZZA_H_
#define PIZZA_H_
#include "Recipe.h"


class Pizza: public Recipe {
  public:
    Pizza(string , string , string , Category ,int , int, int);
    virtual ~Pizza();
    virtual void computeRating();
    virtual float getRating();

  private:
    int     reheatTime;
    int     pizzaType;
};

#endif /* PIZZA_H_ */
