#ifndef FICHALEITURA_H
#define FICHALEITURA_H
#include <iostream>
#include <string>
using namespace std;

class FichaLeitura
{
private:
    string titulo;
    string autor;
    int anoPublicacao;
    int numPaginas;
    int paginaAtual;
    bool lido;
    float nota0a5;

public:
    FichaLeitura();
    FichaLeitura(string titulo, string autor, int anoPublicacao, int numPaginas);
    string getTitulo();
    string getAutor();
    int getAnoPublicacao();
    int getNumPaginas();
    int getPaginaAtual();
    bool getLido();
    float getNota0a5();
    void setTitulo(string titulo);
    void setAutor(string autor);
    void setAnoPublicacao(int anoPublicacao);
    void setNumPaginas(int numPaginas);
    void setPaginaAtual(int paginaAtual);
    void setLido(bool lido);
    void setNota0a5(float nota0a5);
    void iniciarLeitura();
    void marcarLido();
    void avancarPaginas(int qtd);
    void avaliar(float nota);
    float percentualLido();
    void resumo();
};

#endif
