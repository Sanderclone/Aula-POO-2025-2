#include <iostream>
#include <cstdio>
using namespace std;

struct Ponto
{
    float x;
    float y;
};

int main()
{
    Ponto P1, P2;
    int n;

    cout << "Digite as coordenadas de P1 (x1 y1): ";
    cin >> P1.x >> P1.y;

    cout << "Digite as coordenadas de P2 (x2 y2): ";
    cin >> P2.x >> P2.y;

    cout << "Digite o numero de pontos a gerar (incluindo P1 e P2): ";
    cin >> n;

    if (n < 2)
    {
        cout << "Eh necessario pelo menos 2 pontos." << endl;
        return 1;
    }

    Ponto *pontos = new Ponto[n];

    float dt = 1.0f / (n - 1);

    for (int i = 0; i < n; ++i)
    {
        float t = dt * i;
        pontos[i].x = P1.x + t * (P2.x - P1.x);
        pontos[i].y = P1.y + t * (P2.y - P1.y);
    }

    cout << "\nPontos gerados:\n";
    for (int i = 0; i < n; ++i)
    {
        printf("Ponto %d: (%.2f, %.2f)\n", i + 1, pontos[i].x, pontos[i].y);
    }

    delete[] pontos;

    return 0;
}
