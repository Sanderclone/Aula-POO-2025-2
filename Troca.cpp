#include "Troca.h"

Troca::Troca(): id(0), remetente(""), destinatario(""), figDesejada(0), figOfertada(0), status(0) {}
Troca::Troca(int id_, const std::string &r, const std::string &d, int desejada, int ofertada, int status_)
    : id(id_), remetente(r), destinatario(d), figDesejada(desejada), figOfertada(ofertada), status(status_) {}
