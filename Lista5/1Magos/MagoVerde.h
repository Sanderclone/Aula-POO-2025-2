#ifndef MAGOVERDE_H
#define MAGOVERDE_H

#include "Mago.h"

class MagoVerde : public Mago {
public:
    MagoVerde(string nome, int poder, int idade, int escola);

    void FalarComAnimais();
};

#endif
