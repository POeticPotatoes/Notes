#include "Animal.h"
#include <iostream>
#include <string>
using namespace std ;

Animal::Animal() : _name("unknown") {
    cout << "constructing Animal object "<< _name << endl ;
}
Animal::Animal(string n, COLOR c) : _name(n), _color(c) {
    cout << "constructing Animal object "<< _name <<" with color "<< color2string(c) << endl ;
}
Animal::~Animal() {
    cout << "destructing Animal object "<< _name << endl ;
}

void Animal::eat() {
    cout << "Animal eats "<< endl ;
}
string Animal::color2string(COLOR color) const {
    switch (color) {
        case Green: return "Green";
        case Blue: return "Blue";
        case White: return "White";
        case Black: return "Black";
        case Brown: return "Brown";
        default: return "Unknown";
    }
}
Mammal::Mammal() : Animal() {
    cout << "constructing Mammal object "<< endl ;
}
Mammal::Mammal(string n, COLOR c) : Animal(n, c) {
    cout << "constructing Mammal object "<< n <<" with color "<< color2string(c) << endl ;
}
Mammal::~Mammal() {
    cout << "destructing Mammal object "<< endl ;
}
void Mammal::eat() const {
    cout << "Mammal eats "<< endl ;
}
void Mammal::move() const {
    cout << "Mammal moves "<< endl ;
}