#include <iostream>
#include "Data.h"
using namespace std;

Data::Data(int d, int m, int a)
{
    dia = d;
    mes = m;
    ano = a;
}

void Data::imprimirData()
{
    cout << dia << "/" << mes << "/" << ano << endl;
}

void Data::imprimirDataPorExtenso(string cidade)
{
    string nomeMes;

    switch (mes)
    {
    case 1: nomeMes = "janeiro"; break;
    case 2: nomeMes = "fevereiro"; break;
    case 3: nomeMes = "março"; break;
    case 4: nomeMes = "abril"; break;
    case 5: nomeMes = "maio"; break;
    case 6: nomeMes = "junho"; break;
    case 7: nomeMes = "julho"; break;
    case 8: nomeMes = "agosto"; break;
    case 9: nomeMes = "setembro"; break;
    case 10: nomeMes = "outubro"; break;
    case 11: nomeMes = "novembro"; break;
    case 12: nomeMes = "dezembro"; break;
    default: nomeMes = "mês inválido"; break;
    }

    cout << cidade << ", " << dia << " de " << nomeMes << " de " << ano << endl;
}
