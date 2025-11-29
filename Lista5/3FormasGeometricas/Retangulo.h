#ifndef RETANGULO_H
#define RETANGULO_H
#include "FormaGeometrica.h"

class Retangulo : public FormaGeometrica {
private:
    double Base;
    double Altura;
public:
    Retangulo(double base, double altura);

    double calcularArea() const override;
    double calcularPerimetro() const override;
};

#endif
