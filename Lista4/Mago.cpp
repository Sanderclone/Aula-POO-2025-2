#include "Mago.h"
#include <iostream>
using namespace std;

Mago::Mago() {
    nome = "";
    idade = 0;
    escola = "";
}

Mago::Mago(string n, int i, string e) {
    nome = n;
    idade = i;
    escola = e;
}

string Mago::getNome() { return nome; }
int Mago::getIdade() { return idade; }
string Mago::getEscola() { return escola; }

void Mago::setNome(string n) { nome = n; }
void Mago::setIdade(int i) { idade = i; }
void Mago::setEscola(string e) { escola = e; }

void Mago::imprimir() {
    cout << nome << " (" << idade << " anos) - " << escola << endl;
}
