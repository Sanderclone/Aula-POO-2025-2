#ifndef ANAMNESE_H
#define ANAMNESE_H
#include <iostream>
#include <string>
using namespace std;

class Anamnese
{
private:
    string nome;
    int idade;
    float pesoKg;
    float alturaM;
    string alergias;
    string doencasPreExistentes;
    string medicamentosEmUso;
public:
    Anamnese();
    Anamnese(string nome, int idade, float pesoKg, float alturaM,string alergias, string doencasPreExistentes, string medicamentosEmUso);
    string getNome();
    int getIdade();
    float getPesoKg();
    float getAlturaM();
    string getAlergias();
    string getDoencasPreExistentes();
    string getMedicamentosEmUso();
    void setNome(string nome);
    void setIdade(int idade);
    void setPesoKg(float pesoKg);
    void setAlturaM(float alturaM);
    void setAlergias(string alergias);
    void setDoencasPreExistentes(string doencasPreExistentes);
    void setMedicamentosEmUso(string medicamentosEmUso);
    float calcularIMC();
    void gerarResumo();
};

#endif
