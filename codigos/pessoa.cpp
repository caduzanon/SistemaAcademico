#include "pessoa.h"
#include <iostream>
using namespace std;
#include <string.h>
                                                
Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, const char* nome){ //construtor da classe, inicializa as variaveis
    pUniFiliado = nullptr;
    inicializa(diaNa, mesNa, anoNa, nome);
}

Pessoa::Pessoa(){
    pUniFiliado = nullptr;
    inicializa(0,0,0,""); //inicializar com "" por ser char
}

void Pessoa::inicializa(int diaNa, int mesNa, int anoNa, const char* nome){
    diaP = diaNa;
    mesP = mesNa;   //as variaveis dentro de uma classe são chamadas de atributos
    anoP= anoNa;
    strcpy(nomeP, nome); //strcpy copia o nome do main para o atributo nomeP, é sempre o oposto do que se espera, o primeiro argumento é o destino e o segundo é a origem
    idadeP = -1;
}
void Pessoa::calc_idade(int diaAT, int mesAT, int ano_atualAT){ //funções dentro de uma classe são chamadas de métodos  
    idadeP = ano_atualAT - anoP;                            
    if(mesAT < mesP){
            idadeP -= 1; //se a pessoa não fez aniversário, é -1 ano;
        }else{
            if(mesP == mesAT){
                if(diaP > diaAT){
                    idadeP -= 1;
                }
            }
    }
}

void Pessoa::imprime_idade(){
    //printf("A idade de %s seria de %d \n", nomeP, idadeP); 
    cout<<"A idade de "<<nomeP<<" seria de "<<idadeP<<endl;//trabalha orientado a fluxo
}
void Pessoa::calcula_imprime_idade(int diaAT, int mesAT, int ano_atualAT){
    calc_idade(diaAT, mesAT, ano_atualAT);
    imprime_idade();
}
int Pessoa::informaIdade(){
    return idadeP;
}

void Pessoa::setUnifiliado(Universidade *pu){ //recebo o endereço de pu e armazeno no pUnifiliado
    pUniFiliado = pu; //guardo o endereço que está em pu dentro de pUniFiliado.
}
void Pessoa::OndeTrabalho(){
    //um método da referência UniFiliado é chamado
    cout << nomeP << " trabalha para a " << pUniFiliado->getNome() << "."<<endl;

    //só usa o * para acessar o conteúdo apontado pelo ponteiro, por exemplo: pUniFiliado->getNome().

    /* 
    Objeto direto:
        Universidade u;
        u.setNome("UTFPR");      // usa ponto
        
    Ponteiro para objeto:

        Universidade* pu = &u;
        pu->setNome("UTFPR");    // usa seta
    
        Porque quando você usa pu->setNome(), o compilador entende como:

        (*pu).setNome();

        Ou seja:

        *pu desreferencia o ponteiro (acessa o objeto que ele aponta),

        e então .setNome() chama o método.

        */
}