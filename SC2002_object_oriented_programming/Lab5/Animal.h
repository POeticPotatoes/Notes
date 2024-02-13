

#ifndef LAB5_ANIMAL_H
#define LAB5_ANIMAL_H
#include <string>
using namespace std ;
enum COLOR {Green, Blue, White, Black, Brown};
class Animal {
public:
    Animal();
    Animal(string n, COLOR c);
    string color2string(COLOR color) const;
    ~Animal();
    virtual void speak() const=0;
    virtual void move() const=0;
    void eat();

private:
    string _name;
    COLOR _color ;
};
class Mammal : public Animal {
public:
    Mammal();
    Mammal(string n, COLOR c);
    ~Mammal();
    void eat() const;
    void move() const;
};

#endif //LAB5_ANIMAL_H
