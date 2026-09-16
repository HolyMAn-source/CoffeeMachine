#include "CoffeeMachine.h"
#include <iostream>

using namespace std;

CoffeeMachine::CoffeeMachine(int initialMilk, int initialCoffee) {
  milk = initialMilk;
  coffee = initialCoffee;
  preparedCups = 0;
}

void CoffeeMachine::showStatus() const {
  cout << "\n========== Состояние кофемашины ==========\n";
  cout << "Молоко: " << milk << " мл\n";
  cout << "Кофе: " << coffee << " г\n";
  cout << "Приготовлено чашек: " << preparedCups << "/" << MAX_CUPS << "\n";
  cout << "До очистки можно приготовить: " << getRemainingCups() << " чашек\n";
  cout << "==========================================\n";
}

void CoffeeMachine::clean() {
  cout << "\n------------------------------------------\n";
  cout << "Лимит приготовления достигнут.\n";
  cout << "Выполняется очистка кофемашины...\n";

  preparedCups = 0;

  cout << "Кофемашина очищена.\n";
  cout << "Счётчик приготовленных чашек сброшен.\n";
  cout << "------------------------------------------\n";
}

bool CoffeeMachine::hasEnoughMilk(int requiredMilk) const {
  return milk >= requiredMilk;
}

bool CoffeeMachine::hasEnoughCoffee(int requiredCoffee) const {
  return coffee >= requiredCoffee;
}

void CoffeeMachine::useMilk(int amount) { milk -= amount; }

void CoffeeMachine::useCoffee(int amount) { coffee -= amount; }

void CoffeeMachine::addPreparedCups(int amount) { preparedCups += amount; }

int CoffeeMachine::getPreparedCups() const { return preparedCups; }

int CoffeeMachine::getRemainingCups() const { return MAX_CUPS - preparedCups; }
