#include "Mago.h"
#include <iostream>
using std::cout;

Mago::Mago(string nome, int poder, int idade, int escola)
    : Nome(nome), Poder(poder), Idade(idade), EscolaMagia(escola) {}

void Mago::Andar() {
    cout << Nome << " esta andando.\n";
}

void Mago::Falar() {
    cout << Nome << " diz: 'Saudacoes, viajante.'\n";
}

void Mago::InvocarMagia() {
    cout << Nome << " invoca uma magia geral!\n";
}
