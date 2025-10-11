#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Ponto
{
    double x;
    double y;
};

int main()
{
    int n;
    double r;

    cout << "Digite o numero de pontos (n): ";
    cin >> n;

    cout << "Digite o raio do circulo (0.0 < r <= 10.0): ";
    cin >> r;

    if (r <= 0.0 || r > 10.0)
    {
        cout << "Raio invalido. Deve estar no intervalo (0.0, 10.0]." << endl;
        return 1;
    }

    Ponto *pontos = new Ponto[n];

    for (int i = 0; i < n; i++)
    {
        double theta = (2 * M_PI * i) / n;
        pontos[i].x = r * cos(theta);
        pontos[i].y = r * sin(theta);
    }

    cout << fixed << setprecision(2);
    cout << "\nPontos na circunferencia:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Ponto " << i + 1 << ": (" << pontos[i].x << ", " << pontos[i].y << ")" << endl;
    }

    delete[] pontos;

    return 0;
}
