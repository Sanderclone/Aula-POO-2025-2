#include "Circulo.h"
#include <cmath>

constexpr double PI = std::acos(-1.0);

Circulo::Circulo(double raio)
    : FormaGeometrica("Círculo"), Raio(raio) {}

double Circulo::calcularArea() const {
    return PI * Raio * Raio;
}

double Circulo::calcularPerimetro() const {
    return 2 * PI * Raio;
}
