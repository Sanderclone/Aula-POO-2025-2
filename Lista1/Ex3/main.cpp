#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    Data hoje(9, 10, 2025);

    cout << "Data normal: ";
    hoje.imprimirData();

    cout << "Data por extenso: ";
    hoje.imprimirDataPorExtenso("Sao Leopoldo");

    return 0;
}
