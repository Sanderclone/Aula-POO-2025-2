#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>
using namespace std;

class Mago {
private:
    string nome;
    int idade;
    string escola;

public:
    Mago();
    Mago(string n, int i, string e);

    string getNome();
    int getIdade();
    string getEscola();

    void setNome(string n);
    void setIdade(int i);
    void setEscola(string e);

    void imprimir();
};

#endif
