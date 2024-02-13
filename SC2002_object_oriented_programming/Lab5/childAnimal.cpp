#include "childAnimal.h"
#include <iostream>
using namespace std ;

Dog::Dog() : Mammal() {
    cout << "constructing Dog object "<< endl ;
}
Dog::Dog(string n,COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "constructing Dog object "<< n <<" with color "<< color2string(c) << " and owner "<< _owner << endl ;
}
Dog::~Dog() {
    cout << "destructing Dog object "<< endl ;
}
void Dog::speak() const{
    cout << "Woof "<< endl ;
}
void Dog::move() const {
    cout << "Dog moves"<< endl ;
}

Cat::Cat() : Mammal() {
    cout << "constructing Cat object "<< endl ;
}
Cat::Cat(string n,COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "constructing Cat object "<< n <<" with color "<< color2string(c) << " and owner "<< _owner << endl ;
}
Cat::~Cat() {
    cout << "destructing Cat object "<< endl ;
}
void Cat::speak() const {
    cout << "Meow "<< endl ;
}
void Cat::move() const {
    cout << "Cat moves"<< endl ;
}

Lion::Lion() : Mammal() {
    cout << "constructing Lion object "<< endl ;
}
Lion::Lion(string n,COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "constructing Lion object "<< n <<" with color "<< color2string(c) << " and owner "<< _owner << endl ;
}
Lion::~Lion() {
    cout << "destructing Lion object "<< endl ;
}
void Lion::speak() const {
    cout << "Roar "<< endl ;
}
void Lion::move() const {
    cout << "Lion moves"<< endl ;
}
