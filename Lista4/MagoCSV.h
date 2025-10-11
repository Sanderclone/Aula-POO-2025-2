#ifndef MAGO_CSV_H
#define MAGO_CSV_H

#include "Mago.h"
#include <string>
using namespace std;

class MagoCSV {
public:
    Mago* lerCSV(string nomeArquivo, int &quantidade);
    void salvarCSV(Mago* magos, int quantidade, string nomeArquivo);
};

#endif
