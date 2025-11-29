#include "MagoCinza.h"
#include <iostream>
using std::cout;

MagoCinza::MagoCinza(string nome, int poder, int idade, int escola)
    : Mago(nome, poder, idade, escola) {}

void MagoCinza::PrepararPocao() {
    cout << Nome << " prepara uma pocao misteriosa.\n";
}
