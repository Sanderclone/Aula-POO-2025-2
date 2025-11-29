#ifndef FORMA_GEOMETRICA_H
#define FORMA_GEOMETRICA_H
#include <string>

class FormaGeometrica {
protected:
    std::string Nome;
public:
    FormaGeometrica(const std::string& nome);
    virtual ~FormaGeometrica() = default;

    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;

    std::string getNome() const;
};

#endif
