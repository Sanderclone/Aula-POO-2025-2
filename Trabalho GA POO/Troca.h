#ifndef TROCA_H
#define TROCA_H

#include <string>

class Troca {
public:
    int id;
    std::string remetente;
    std::string destinatario;
    int figDesejada;
    int figOfertada;
    int status; 

    Troca();
    Troca(int id, const std::string &r, const std::string &d, int desejada, int ofertada, int status);
};

#endif
