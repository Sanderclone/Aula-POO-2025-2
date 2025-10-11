#include "Mago.h"

Mago::Mago()
    : nomeMago(""), idade(0), escolaDeMagia(""), qntdadeMana(0)
{
    cout << "Mago criado como construtor padrao." << endl;
}

Mago::Mago(string nomeMago, int idade, string escolaDeMagia, int qntdadeMana)
    : nomeMago(nomeMago), idade(idade), escolaDeMagia(escolaDeMagia), qntdadeMana(qntdadeMana)
{
    cout << "Mago " << this->nomeMago << " foi criado!" << endl;
}

void Mago::andar()
{
    cout << "Estou andando." << endl;
}

void Mago::falar()
{
    cout << "Olá! Meu nome é " << nomeMago << endl;
}

void Mago::invocarMagia()
{
    cout << "Invocando Magia." << endl;
}

void Mago::recarregarMagia()
{
    cout << "Estou recarregando minha magia." << endl;
}

void Mago::contarMana()
{
    cout << "Tenho " << qntdadeMana << " de mana restante." << endl;
}

Mago::~Mago()
{
    cout << "Deixou de existir." << endl;
}