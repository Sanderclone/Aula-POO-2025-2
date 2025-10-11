#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>

class Usuario {
public:
    std::string username;
    std::string password;
    std::map<int,int> colecao;

    Usuario();
    Usuario(const std::string &u, const std::string &p);

    bool possui(int id) const;
    int status(int id) const;
    void adicionar(int id, int status);
    void remover(int id);
    void colar(int id);
    void disponibilizarParaTroca(int id);
    std::string colecaoToString() const;
    void carregarColecaoFromString(const std::string &s);
};

#endif
