#include "Mago.h"

int main()
{
    Mago mago;
    Mago hp("Harry Potter", 17, "Hogwarts", 100);
    hp.andar();
    hp.falar();
    hp.invocarMagia();
    hp.recarregarMagia();
    hp.contarMana();
    return 0;
}
