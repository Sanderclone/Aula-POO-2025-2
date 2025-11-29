#include "Retangulo.h"

Retangulo::Retangulo(double base, double altura)
    : FormaGeometrica("Retângulo"), Base(base), Altura(altura) {}

double Retangulo::calcularArea() const {
    return Base * Altura;
}

double Retangulo::calcularPerimetro() const {
    return 2 * (Base + Altura);
}
