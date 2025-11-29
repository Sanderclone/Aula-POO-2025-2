#include "FormaGeometrica.h"

FormaGeometrica::FormaGeometrica(const std::string& nome) : Nome(nome) {}

std::string FormaGeometrica::getNome() const {
    return Nome;
}
