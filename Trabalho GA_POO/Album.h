#ifndef ALBUM_H
#define ALBUM_H

#include "Figurinha.h"
#include "Usuario.h"
#include "Troca.h"
#include <vector>
#include <string>

class Album {
public:
    std::vector<Figurinha> catalogo;
    std::vector<Usuario> usuarios;
    std::vector<Troca> trocas;
    int proximaIdTroca;

    Album();

    void carregarDados();
    void salvarDados();

    void criarUsuario();
    Usuario* autenticar(const std::string &user, const std::string &pass);
    void menuPrincipal();
    void menuUsuario(Usuario &u);

private:
    void carregarFigurinhas();
    void carregarUsuarios();
    void carregarTrocas();

    void salvarFigurinhas();
    void salvarUsuarios();
    void salvarTrocas();

    void abrirPacote(Usuario &u);
    void verAlbum(Usuario &u);
    void gerenciarColecao(Usuario &u);
    void listarUsuariosComFigurasDisponiveis(const Usuario &u);
    Usuario* buscarUsuarioPorNome(const std::string &nome);
    void proporTroca(Usuario &u);
    void revisarTrocas(Usuario &u);
    int gerarIdTroca();
    const Figurinha* buscarFigurinhaPorId(int id) const;
};

#endif
