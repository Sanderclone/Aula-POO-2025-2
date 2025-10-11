#include "MagoCSV.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Mago* MagoCSV::lerCSV(string nomeArquivo, int &quantidade) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return nullptr;
    }

    string linha;
    getline(arquivo, linha);
    quantidade = 0;
    while (getline(arquivo, linha)) {
        quantidade++;
    }

    arquivo.clear();
    arquivo.seekg(0);
    getline(arquivo, linha);

    Mago* magos = new Mago[quantidade];
    int i = 0;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, idadeStr, escola;
        getline(ss, nome, ',');
        getline(ss, idadeStr, ',');
        getline(ss, escola, ',');
        int idade = stoi(idadeStr);
        magos[i] = Mago(nome, idade, escola);
        i++;
    }

    arquivo.close();
    return magos;
}

void MagoCSV::salvarCSV(Mago* magos, int quantidade, string nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo para salvar!" << endl;
        return;
    }

    arquivo << "Nome,Idade,Escola\n";
    for (int i = 0; i < quantidade; i++) {
        arquivo << magos[i].getNome() << ","
                << magos[i].getIdade() << ","
                << magos[i].getEscola() << "\n";
    }

    arquivo.close();
    cout << "Arquivo '" << nomeArquivo << "' salvo com sucesso!" << endl;
}
