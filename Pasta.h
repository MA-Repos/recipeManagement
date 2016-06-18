/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Pasta.h
 *   Purpose:   Class definitions of entity class Pasta (derived class of Recipe)
 *   Author:    Mir Abbas, Harth Majeed
 *   Date:      Nov. 15, 2015
 *   (c) 2015 Mir Abbas
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PASTA_H_
#define PASTA_H_

#include "Recipe.h"

class Pasta: public Recipe{
  public:
    Pasta(string="", string="", string="", Category=MAIN_COURSE, int=0, int=0,int=0);
    virtual ~Pasta();
    virtual void computeRating();
    virtual float getRating();

  private:
    int     spiceAmount;
    int  here_Or_Togo;
};

#endif /* PASTA_H_ */
