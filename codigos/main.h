#ifndef _MAIN_H_
#define _MAIN_H_

#include "pessoa.h"
#include "universidade.h"

class principal {
private:
    Pessoa Luiza;
    Pessoa Einstein;
    Pessoa Newton;

    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;
    int diaAtual;
    int mesAtual;
    int anoAtual;

public:
    principal();
    void executar();
};

#endif
