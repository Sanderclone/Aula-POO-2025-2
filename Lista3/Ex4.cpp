#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dado
{
private:
    int faces;

public:
    Dado()
    {
        faces = 6;
    }

    Dado(int f)
    {
        faces = f;
    }

    void setFaces(int f)
    {
        faces = f;
    }

    int Rolar()
    {
        return rand() % faces + 1;
    }
};

int main()
{
    srand(time(0));

    Dado *dadoPtr = new Dado(6);
    int resultado = dadoPtr->Rolar();
    cout << "Dado de 6 faces rolado: " << resultado << endl;
    delete dadoPtr;

    Dado *dados = new Dado[3];

    dados[0].setFaces(6);
    dados[1].setFaces(8);
    dados[2].setFaces(12);

    for (int i = 0; i < 3; ++i)
    {
        cout << "\nDado " << i + 1 << " com " << (i == 0 ? 6 : (i == 1 ? 8 : 12)) << " faces:" << endl;
        for (int j = 0; j < 3; ++j)
        {
            cout << "  Rolagem " << j + 1 << ": " << dados[i].Rolar() << endl;
        }
    }

    delete[] dados;

    return 0;
}
