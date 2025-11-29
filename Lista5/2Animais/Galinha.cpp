#include "Galinha.h"
#include <iostream>
using std::cout;

Galinha::Galinha(string nome) : Animal(nome, "cocorico") {}

void Galinha::fazerSom() {
    cout << Nome << " faz: " << Som_bicho << "\n";
}
