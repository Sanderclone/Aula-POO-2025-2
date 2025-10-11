
#include <iostream>
#include <string>

#ifndef MAGO_H
#define MAGO_H

using namespace std;

class Mago
{
private:
    string nomeMago;
    int idade;
    string escolaDeMagia;
    /*NOVOS ATRIBUTOS*/
    string magia;
    int qntdadeMana;

public:
    Mago();
    Mago(string nomeMago, int idade, string escolaDeMagia, int qntdadeMana);
    void andar();
    void falar();
    void invocarMagia();
    /*NOVOS METODOS*/
    void recarregarMagia();
    void contarMana();
    ~Mago();
};


#endif


