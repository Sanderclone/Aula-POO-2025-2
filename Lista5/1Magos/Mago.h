#ifndef MAGO_H
#define MAGO_H

#include <string>
using std::string;

class Mago {
protected:
    string Nome;
    int Poder;
    int Idade;
    int EscolaMagia;

public:
    Mago(string nome, int poder, int idade, int escola);

    void Andar();
    void Falar();
    void InvocarMagia();
};

#endif
