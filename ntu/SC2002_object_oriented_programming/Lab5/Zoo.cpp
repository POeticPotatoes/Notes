#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
#include "childAnimal.h"
using namespace std ;
int main() {
    vector<Animal*> zoo;
    int choice;
    do {
        std::cout << "Select the animal to send to Zoo:\n"
                  << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: zoo.push_back(new Dog()); break;
            case 2: zoo.push_back(new Cat()); break;
            case 3: zoo.push_back(new Lion()); break;
            case 4:
                for (auto *animal : zoo) {
                    animal->move();
                    animal->speak();
                    animal->eat();

                }
                break;

        }
    } while (choice != 5);

    for (auto *animal : zoo) {
        delete animal;
    }

    return 0;
}
