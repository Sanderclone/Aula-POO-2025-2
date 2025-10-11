#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int numVagas;

    srand(time(0));

    do
    {
        cout << "Digite o número de vagas (entre 5 e 15): ";
        cin >> numVagas;
    } while (numVagas < 5 || numVagas > 15);

    int *estacionamento = new int[numVagas];

    for (int i = 0; i < numVagas; ++i)
        estacionamento[i] = 0;

    for (int hora = 1; hora <= 24; ++hora)
    {
        cout << "\n--- Hora " << hora << " ---\n";

        for (int i = 0; i < numVagas; ++i)
        {
            if (estacionamento[i] > 0)
            {
                estacionamento[i]--;
            }
        }

        bool entrou = false;
        for (int i = 0; i < numVagas; ++i)
        {
            if (estacionamento[i] == 0)
            {
                int tempoPermanencia = rand() % 5 + 1;
                estacionamento[i] = tempoPermanencia;
                cout << "Novo carro entrou na vaga " << i << " com permanência de " << tempoPermanencia << " hora(s).\n";
                entrou = true;
                break;
            }
        }

        if (!entrou)
        {
            cout << "Estacionamento cheio! Carro não pôde entrar.\n";
        }

        cout << "Estado das vagas: [ ";
        for (int i = 0; i < numVagas; ++i)
        {
            cout << estacionamento[i] << " ";
        }
        cout << "]\n";
    }

    delete[] estacionamento;

    return 0;
}
