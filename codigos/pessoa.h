#ifndef _PESSOA_H
#define _PESSOA_H

#include "universidade.h"

class Pessoa {
private:
    int diaP, mesP, anoP, idadeP;
    char nomeP[30];

    // Ponteiro para universidade associada
    Universidade* pUniFiliado;

public:
    // Construtor com parâmetros (nome como const char*)
    Pessoa(int diaNa, int mesNa, int anoNa, const char* nome = "");

    // Construtor padrão
    Pessoa();

    // Inicializa manualmente (nome também como const char*)
    void inicializa(int diaNa, int mesNa, int anoNa, const char* nome = "");

    void calcula_imprime_idade(int diaAT, int mesAT, int ano_atualAT);

    void imprime_idade();

    void calc_idade(int diaAT, int mesAT, int ano_atualAT);

    int informaIdade();

    // Associa uma universidade à pessoa
    void setUnifiliado(Universidade* pu);

    void OndeTrabalho();
};

#endif
