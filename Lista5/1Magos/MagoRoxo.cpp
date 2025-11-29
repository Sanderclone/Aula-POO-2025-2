#include "MagoRoxo.h"
#include <iostream>
using std::cout;

MagoRoxo::MagoRoxo(string nome, int poder, int idade, int escola)
    : Mago(nome, poder, idade, escola) {}

void MagoRoxo::CriarIlusao() {
    cout << Nome << " cria uma poderosa ilusao!\n";
}
