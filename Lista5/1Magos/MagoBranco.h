#ifndef MAGOBRANCO_H
#define MAGOBRANCO_H

#include "Mago.h"

class MagoBranco : public Mago {
public:
    MagoBranco(string nome, int poder, int idade, int escola);

    void LancarCura();
};

#endif
