#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

class Animal {
protected:
    string Nome;
    string Som_bicho;

public:
    Animal(string nome, string som);
    virtual void fazerSom() = 0;
};

#endif
