#include "Figurinha.h"

Figurinha::Figurinha(): id(0), nome(""), selecao("") {}
Figurinha::Figurinha(int id_, const std::string &nome_, const std::string &selecao_)
    : id(id_), nome(nome_), selecao(selecao_) {}