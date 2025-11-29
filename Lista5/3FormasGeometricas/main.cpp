#include <iostream>
#include <iomanip>
#include "Retangulo.h"
#include "Triangulo.h"
#include "Circulo.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Retangulo r(5.0, 3.0);
    Triangulo t(6.0, 4.0, 3.0, 4.0, 5.0);
    Circulo c(2.5);

    const FormaGeometrica* formas[] = { &r, &t, &c };

    for (const FormaGeometrica* f : formas) {
        std::cout << f->getNome()
                  << " - Área: " << f->calcularArea()
                  << " | Perímetro: " << f->calcularPerimetro()
                  << std::endl;
    }
    return 0;
}
