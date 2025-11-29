#include <iostream>
#include "Gato.h"
#include "Cachorro.h"
#include "Galinha.h"

int main() {
    Gato g("Osvaldo");
    Cachorro c("Duque");
    Galinha h("Garnize");

    g.fazerSom();
    c.fazerSom();
    h.fazerSom();
}
