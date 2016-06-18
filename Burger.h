/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Burger.h
 *   Purpose:   Class definitions of entity class Burger (derived class of Recipe)
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BURGER_H_
#define BURGER_H_
#include "Recipe.h"

class Burger: public Recipe{
  public:
    Burger(string="", string="", string="", Category=MAIN_COURSE, int=0, int=0, int=0);
    virtual ~Burger();
    virtual void computeRating();
    virtual float getRating();

  private:
    int proteinAmount;
    int calories;

};

#endif /* BURGER_H_ */
