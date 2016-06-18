OBJ = main.o RecipeManager.o UImanager.o Recipe.o Burger.o Drinks.o Pasta.o Pizza.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

RecipeManager.o:	RecipeManager.cc RecipeManager.h 
	g++ -c RecipeManager.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

Recipe.o:	Recipe.cc Recipe.h defs.h
	g++ -c Recipe.cc

Burger.o:	Burger.cc Burger.h
	g++ -c Burger.cc

Drinks.o:	Drinks.cc Drinks.h
	g++ -c Drinks.cc

Pasta.o:	Pasta.cc Pasta.h
	g++ -c Pasta.cc

Pizza.o:	Pizza.cc Pizza.h
	g++ -c Pizza.cc

clean:
	rm -f *.o a4

