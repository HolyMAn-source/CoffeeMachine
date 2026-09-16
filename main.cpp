#include <iostream>

#include "CoffeeMachine.h"
#include "CoffeeMaker.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  CoffeeMachine machine(2000, 1500);

  CoffeeMaker coffeeMaker;

  int choice;

  cout << "==========================================\n";
  cout << "        ДОБРО ПОЖАЛОВАТЬ!\n";
  cout << "           КОФЕМАШИНА\n";
  cout << "==========================================\n";

  while (true) {
    cout << "\n";
    cout << "--------------- МЕНЮ --------------------\n";
    cout << "1. Приготовить капучино\n";
    cout << "2. Приготовить латте\n";
    cout << "3. Приготовить американо\n";
    cout << "4. Проверить состояние машины\n";
    cout << "0. Выход\n";
    cout << "------------------------------------------\n";

    cout << "Выберите действие: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int amount;

      cout << "\nСколько чашек капучино приготовить? ";
      cin >> amount;

      coffeeMaker.makeCappuccino(machine, amount);
      break;
    }

    case 2: {
      int amount;

      cout << "\nСколько чашек латте приготовить? ";
      cin >> amount;

      coffeeMaker.makeLatte(machine, amount);
      break;
    }

    case 3: {
      int amount;

      cout << "\nСколько чашек американо приготовить? ";
      cin >> amount;

      coffeeMaker.makeAmericano(machine, amount);
      break;
    }

    case 4:
      machine.showStatus();
      break;

    case 0:
      cout << "\nКофемашина выключена.\n";
      return 0;

    default:
      cout << "\nОшибка: такого пункта меню нет.\n";
      break;
    }
  }

  return 0;
}
