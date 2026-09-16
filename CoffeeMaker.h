#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "CoffeeMachine.h"

class CoffeeMaker {
private:
  void makeDrink(CoffeeMachine &machine, int amount, int milkPerCup,
                 int coffeePerCup, const char *drinkName);

public:
  void makeCappuccino(CoffeeMachine &machine, int amount);
  void makeLatte(CoffeeMachine &machine, int amount);
  void makeAmericano(CoffeeMachine &machine, int amount);
};

#endif
