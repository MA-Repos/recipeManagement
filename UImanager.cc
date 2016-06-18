/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      UImanager.cc
 *   Purpose:   Function implementations for UI class UImanager
 *   Author:    Christine Laurendeau, Mir Abbas, Harth Majeed
 *   Date:      Jul. 21, 2015, Nov. 15, 2015
 *   (c) 2015 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UImanager.h"

using namespace std;

/*
 * mainMenu: show's user some options and takes user input
 * return: void but as a parameter returns choice
 */
void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << "( 1 )  Add recipe"         << endl;
  cout << "( 2 )  List all recipes"   << endl;
  cout << "( 3 )  View Recipe"        << endl;
  cout << "( 4 )  Remove Recipe"      << endl;
  cout << "( 5 )  Recipe Rating (new feature)"      << endl;
  cout << "( 0 )  Exit"               << endl;

  while (*choice < 0 || *choice > 5) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::getRecipeName(string *userName)
{
  do{
    cout <<"Enter recipe name:  ";
    getline(cin, *userName);
  }while(userName->length()==0);
}

/*
 * getRecipeData: takes user input for Recipe data
 */
Recipe* UImanager::getRecipeData()
{
  string    str;
  string    name;
  string    ingredients;
  string    instructions;
  Category	cat;

  int       cal, pro, spice, reheat, alcohol, fruit,ptype,hereOrTogo;
  int		    temp;


  getRecipeName(&name);

  cout << endl << "Enter ingredients (terminate with -1):   " << endl;
  getline(cin, str);
  while (str != "-1") {
    ingredients += "  ";
    ingredients += str += "\n";
    getline(cin, str);
  }

  cout << endl << "Enter instructions (terminate with -1):   " << endl;
  getline(cin, str);
  while (str != "-1") {
    instructions += "  ";
    instructions += str += "\n";
    getline(cin, str);
  }
  cout << endl << "Enter Making Time of this Recipe (in minutes):  " << endl;
  int cTime = getInt();
  cout << "Add Category to this Recipe:   " << endl;

  printByCategory(&temp);
  cat = (Category)temp;

  cout<< "What kind of Recipe is this ?"<<endl;
  int type;
  getKindOfRecipe(&type);
  Recipe *tmpRecipe=0;
  //  Recipe *tmpRecipe;

  //Recipe kind initialization according to user input
  switch(type){
  case 1:
    cout<< "How many calories(in numbers)? ";
    cal = getInt();
    cout<< "Amount of Protein(grams (in numbers)? ";
    pro = getInt();
    tmpRecipe= new Burger(name, ingredients, instructions, cat,pro ,cal, cTime);
    return tmpRecipe;
    //    recipe.setName(name);
    break;

  case 2:

    cout<< "How much spice (in numbers)? ";
    spice = getInt();
    cout<< "Pasta is for (1)here or (2)togo? ";
    hereOrTogo = getInt();

    tmpRecipe = new Pasta(name, ingredients, instructions, cat, spice, hereOrTogo,cTime );
    return tmpRecipe;
    break;

  case 3:
    cout<< "What is Reheat time(in numbers)? ";
    reheat = getInt();
    cout<< "What type of pizza it is? "<<endl;
    cout<< "(1) Vegetarian"<<endl;
    cout<< "(2) Non Vegertarian"<< endl;
    ptype = getInt();

    tmpRecipe = new Pizza(name, ingredients, instructions, cat, reheat, ptype,cTime);
    return tmpRecipe;
    break;

  case 4:

    cout<<"Amount of alcohol(in numbers)? ";
    alcohol = getInt();
    cout<<"Amount of Fruit(percentage (in numbers))? ";
    fruit = getInt();

    tmpRecipe = new Drinks(name, ingredients, instructions, cat, alcohol, fruit,cTime);
    return tmpRecipe;
    break;

  default:
    break;
  }


  return 0;

}

/*
 * printRecipes: Prints a all Recipes
 * return: void
 */
void UImanager::printRecipes(Llist<Recipe> *arr)
{
  cout << endl << endl << "LIST OF RECIPES:" << endl << endl;

  for (int i=0; i<arr->getSize(); ++i) {
    Recipe* rec = arr->getRecipe(i);
    if(rec != 0)
      cout << "Name: " << rec->getName() << endl;
  }

}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue..."<<endl;
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;
  //  cin.clear();
  //  cin.ignore();
  while (true) {

    getline(cin, str);
    // This code converts from string to number safely.
    stringstream ss(str);
    if (ss >> num)
      break;
    cout << "Invalid number, please try again" << endl;
  }

  return num;
}
void UImanager::printByCategory(int* ch)
{
  string str;
  *ch= -1;

  cout<<"Enter from following Categories:"  <<endl;
  cout<<"(1) Main Course"                   <<endl;
  cout<<"(2) Appetizer"                     <<endl;
  cout<<"(3) Dessert"                       <<endl;
  cout<<"(4) Pasta"                         <<endl;
  cout<<"(5) Drink"                         <<endl;

  while(*ch<1 || *ch>5 ){
    cout << "Enter your selection:  "<<endl;
    *ch = getInt();
  }
  *ch = *ch-1;
}

void UImanager::printNotFound(string* name)
{
  cout << "--"<< *name << "-- Recipe not found"  <<endl;
}

void UImanager::printRemoveSuccessful(string* name)
{
  cout << *name <<" was removed Successfully!!"<<endl;
}

void UImanager::getNumofRecipes(int *num){
  cout<<"Enter the Number of Recipe"<<endl;
  cout<<"(1) individual recipe"<<endl;
  cout<<"(2) or more for number of Recipes you want to add"<<endl;
  *num =getInt();
}

void UImanager::printNRecipes(int* n){
  cout<<"Recipe # "<<*n<<" :"<<endl;
}

void UImanager::getKindOfRecipe(int* ch){

  *ch= -1;

  cout<<"Enter from following Kind of Recipes:" <<endl;
  cout<<"(1) Burger"                            <<endl;
  cout<<"(2) Pasta"                             <<endl;
  cout<<"(3) Pizza"                             <<endl;
  cout<<"(4) Drinks"                            <<endl;

  while(*ch<1 || *ch>4 ){
    cout << "Enter your selection:  "<<endl;
    *ch = getInt();
  }
}

void UImanager::printRating(float rate , string name){
  cout << setprecision(2) << fixed;
  cout<< name << "(Recipe) has Rating "<< rate << " stars out of 5"<<endl;

}
