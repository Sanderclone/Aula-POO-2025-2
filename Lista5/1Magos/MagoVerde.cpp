#include "MagoVerde.h"
#include <iostream>
using std::cout;

MagoVerde::MagoVerde(string nome, int poder, int idade, int escola)
    : Mago(nome, poder, idade, escola) {}

void MagoVerde::FalarComAnimais() {
    cout << Nome << " conversa com os animais da floresta.\n";
}
