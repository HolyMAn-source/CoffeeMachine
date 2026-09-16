#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

class CoffeeMachine {
private:
  int milk;
  int coffee;
  int preparedCups;

  static const int MAX_CUPS = 10;

public:
  CoffeeMachine(int initialMilk, int initialCoffee);

  void showStatus() const;
  void clean();

  bool hasEnoughMilk(int requiredMilk) const;
  bool hasEnoughCoffee(int requiredCoffee) const;

  void useMilk(int amount);
  void useCoffee(int amount);

  void addPreparedCups(int amount);

  int getPreparedCups() const;
  int getRemainingCups() const;
};

#endif
