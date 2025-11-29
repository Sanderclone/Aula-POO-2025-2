#include "MagoBranco.h"
#include <iostream>
using std::cout;

MagoBranco::MagoBranco(string nome, int poder, int idade, int escola)
    : Mago(nome, poder, idade, escola) {}

void MagoBranco::LancarCura() {
    cout << Nome << " lança uma magia de cura!\n";
}
