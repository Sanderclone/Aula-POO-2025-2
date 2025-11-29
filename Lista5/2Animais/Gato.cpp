#include "Gato.h"
#include <iostream>
using std::cout;

Gato::Gato(string nome) : Animal(nome, "Miau") {}

void Gato::fazerSom() {
    cout << Nome << " faz: " << Som_bicho << "\n";
}
