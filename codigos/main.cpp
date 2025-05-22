#include <iostream>
#include "main.h"

using namespace std;

principal::principal() {
    diaAtual = 21;
    mesAtual = 5;
    anoAtual = 2025;
    UTFPR.setNome("UTFPR"); // configura o nome da universidade
    Cambridge.setNome("Cambridge");
    Princeton.setNome("Princeton");

    Luiza = Pessoa(15, 7, 1998, "Luiza Ribeiro");   // cria pessoa Luiza
    Luiza.setUnifiliado(&UTFPR);    // associa a pessoa à universidade, passando o endereço de UTFPR

    Einstein.inicializa(14, 3, 1879, "Albert Einstein");
    Einstein.setUnifiliado(&Cambridge);

    Newton.inicializa(4, 1, 1643, "Isaac Newton");
    Newton.setUnifiliado(&Princeton);

}

void principal::executar() {
    Luiza.calcula_imprime_idade(diaAtual, mesAtual, anoAtual);
    Luiza.OndeTrabalho();

    Einstein.calcula_imprime_idade(diaAtual, mesAtual, anoAtual);
    Einstein.OndeTrabalho();

    Newton.calcula_imprime_idade(diaAtual, mesAtual, anoAtual);
    Newton.OndeTrabalho();
}

int main() {
    principal p;
    p.executar();
    return 0;
}
