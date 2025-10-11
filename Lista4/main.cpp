#include <iostream>
#include "Mago.h"
#include "MagoCSV.h"
using namespace std;

int main() {
    MagoCSV arquivo;
    int quantidade = 0;

    Mago* magos = arquivo.lerCSV("magos.csv", quantidade);
    if (!magos) return 1;

    cout << "\n--- Magos lidos do arquivo ---" << endl;
    for (int i = 0; i < quantidade; i++) {
        magos[i].imprimir();
    }

    cout << "\n--- Adicione um novo mago ---" << endl;
    string nome, escola;
    int idade;

    cout << "Nome: ";
    getline(cin >> ws, nome);
    cout << "Idade: ";
    cin >> idade;
    cout << "Escola: ";
    getline(cin >> ws, escola);

    Mago* novosMagos = new Mago[quantidade + 1];
    for (int i = 0; i < quantidade; i++) {
        novosMagos[i] = magos[i];
    }
    novosMagos[quantidade] = Mago(nome, idade, escola);
    quantidade++;

    delete[] magos;

    cout << "\n--- Lista atualizada ---" << endl;
    for (int i = 0; i < quantidade; i++) {
        novosMagos[i].imprimir();
    }

    arquivo.salvarCSV(novosMagos, quantidade, "saida.csv");

    delete[] novosMagos;
    return 0;
}
