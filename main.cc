/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      main.cc
 *   Purpose:   Main function
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Sept. 21, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

using namespace std;

#include "RecipeManager.h"


int main()
{
  RecipeManager *manager=new RecipeManager;

  manager->launch();

  delete manager;

}

