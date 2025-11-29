#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "FormaGeometrica.h"

class Triangulo : public FormaGeometrica {
private:
    double Base;
    double Altura;
    double Lado1;
    double Lado2;
    double Lado3;
public:
    Triangulo(double base, double altura, double lado1, double lado2, double lado3);

    double calcularArea() const override;
    double calcularPerimetro() const override;
};

#endif
