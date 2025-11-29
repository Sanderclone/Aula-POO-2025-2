#ifndef CIRCULO_H
#define CIRCULO_H
#include "FormaGeometrica.h"

class Circulo : public FormaGeometrica {
private:
    double Raio;
public:
    Circulo(double raio);

    double calcularArea() const override;
    double calcularPerimetro() const override;
};

#endif
