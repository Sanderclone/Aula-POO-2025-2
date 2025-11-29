#include "Triangulo.h"

Triangulo::Triangulo(double base, double altura, double lado1, double lado2, double lado3)
    : FormaGeometrica("Triângulo"),
      Base(base), Altura(altura),
      Lado1(lado1), Lado2(lado2), Lado3(lado3) {}

double Triangulo::calcularArea() const {
    return (Base * Altura) / 2.0;
}

double Triangulo::calcularPerimetro() const {
    return Lado1 + Lado2 + Lado3;
}
