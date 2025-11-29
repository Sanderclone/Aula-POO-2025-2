#ifndef MAGOCINZA_H
#define MAGOCINZA_H

#include "Mago.h"

class MagoCinza : public Mago {
public:
    MagoCinza(string nome, int poder, int idade, int escola);

    void PrepararPocao();
};

#endif
