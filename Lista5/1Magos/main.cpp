#include <iostream>
#include "MagoBranco.h"
#include "MagoVerde.h"
#include "MagoRoxo.h"
#include "MagoCinza.h"

int main() {
    MagoBranco mb("Althair", 80, 120, 1);
    MagoVerde  mv("Lorian", 60, 90, 2);
    MagoRoxo   mr("Velkan", 95, 150, 3);
    MagoCinza  mc("Norgrim", 70, 110, 4);

    mb.Falar();
    mv.Andar();
    mr.InvocarMagia();
    mc.Falar();

    std::cout << "\n--- Métodos Especializados ---\n";
    mb.LancarCura();
    mv.FalarComAnimais();
    mr.CriarIlusao();
    mc.PrepararPocao();

    return 0;
}
