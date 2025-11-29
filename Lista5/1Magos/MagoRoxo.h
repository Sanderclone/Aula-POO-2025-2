#ifndef MAGOROXO_H
#define MAGOROXO_H

#include "Mago.h"

class MagoRoxo : public Mago {
public:
    MagoRoxo(string nome, int poder, int idade, int escola);

    void CriarIlusao();
};

#endif
