#include "Cachorro.h"
#include <iostream>
using std::cout;

Cachorro::Cachorro(string nome) : Animal(nome, "Au au") {}

void Cachorro::fazerSom() {
    cout << Nome << " faz: " << Som_bicho << "\n";
}
