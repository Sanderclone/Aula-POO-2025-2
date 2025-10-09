#include "Usuario.h"
#include <sstream>

Usuario::Usuario(): username(""), password("") {}
Usuario::Usuario(const std::string &u, const std::string &p) : username(u), password(p) {}

bool Usuario::possui(int id) const {
    return colecao.find(id) != colecao.end();
}

int Usuario::status(int id) const {
    auto it = colecao.find(id);
    if (it == colecao.end()) return -1;
    return it->second;
}

void Usuario::adicionar(int id, int status_) {
    colecao[id] = status_;
}

void Usuario::remover(int id) {
    colecao.erase(id);
}

void Usuario::colar(int id) {
    if (possui(id)) colecao[id] = 1;
}

void Usuario::disponibilizarParaTroca(int id) {
    if (possui(id) && colecao[id] != 1) colecao[id] = 2;
}

std::string Usuario::colecaoToString() const {
    std::ostringstream oss;
    bool first = true;
    for (auto &p : colecao) {
        if (!first) oss << ",";
        oss << p.first << ":" << p.second;
        first = false;
    }
    return oss.str();
}

void Usuario::carregarColecaoFromString(const std::string &s) {
    colecao.clear();
    if (s.empty()) return;
    std::istringstream iss(s);
    std::string token;
    while (std::getline(iss, token, ',')) {
        size_t pos = token.find(':');
        if (pos == std::string::npos) continue;
        int id = std::stoi(token.substr(0,pos));
        int st = std::stoi(token.substr(pos+1));
        colecao[id] = st;
    }
}
