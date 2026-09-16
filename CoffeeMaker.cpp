#include "CoffeeMaker.h"
#include <iostream>

using namespace std;

void CoffeeMaker::makeDrink(CoffeeMachine &machine, int amount, int milkPerCup,
                            int coffeePerCup, const char *drinkName) {

  if (amount <= 0) {
    cout << "\nОшибка: количество чашек должно быть больше 0.\n";
    return;
  }

  if (machine.getPreparedCups() + amount > 10) {
    cout << "\nВнимание!\n";
    cout << "Текущий лимит: 10 чашек.\n";
    cout << "Сейчас приготовлено: " << machine.getPreparedCups() << " чашек.\n";
    cout << "Запрошено: " << amount << " чашек.\n";
    cout << "Лимит будет превышен.\n";

    machine.clean();
  }

  int requiredMilk = milkPerCup * amount;
  int requiredCoffee = coffeePerCup * amount;

  if (!machine.hasEnoughMilk(requiredMilk)) {
    cout << "\nОшибка: недостаточно молока.\n";
    cout << "Необходимо: " << requiredMilk << " мл.\n";
    return;
  }

  if (!machine.hasEnoughCoffee(requiredCoffee)) {
    cout << "\nОшибка: недостаточно кофе.\n";
    cout << "Необходимо: " << requiredCoffee << " г.\n";
    return;
  }

  machine.useMilk(requiredMilk);
  machine.useCoffee(requiredCoffee);

  machine.addPreparedCups(amount);

  cout << "\n==========================================\n";
  cout << drinkName << " готов!\n";
  cout << "Количество: " << amount << " чашек.\n";
  cout << "==========================================\n";

  cout << "Использовано молока: " << requiredMilk << " мл.\n";

  cout << "Использовано кофе: " << requiredCoffee << " г.\n";

  cout << "Осталось молока: "
       << "проверить через меню.\n";

  cout << "Приготовлено после очистки: " << machine.getPreparedCups()
       << "/10 чашек.\n";

  if (machine.getPreparedCups() == 10) {
    machine.clean();
  }
}

void CoffeeMaker::makeCappuccino(CoffeeMachine &machine, int amount) {

  makeDrink(machine, amount, 100, 50, "Капучино");
}

void CoffeeMaker::makeLatte(CoffeeMachine &machine, int amount) {

  makeDrink(machine, amount, 200, 100, "Латте");
}

void CoffeeMaker::makeAmericano(CoffeeMachine &machine, int amount) {

  makeDrink(machine, amount, 0, 100, "Американо");
}
