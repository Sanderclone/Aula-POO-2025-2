#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <string>

class Figurinha {
public:
    int id;
    std::string nome;
    std::string selecao;

    Figurinha();
    Figurinha(int id, const std::string &nome, const std::string &selecao);
};

#endif