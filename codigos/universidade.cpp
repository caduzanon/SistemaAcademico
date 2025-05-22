#include "universidade.h"
#include <cstring>

Universidade::Universidade(const char* n) {
    strcpy(nome, n);  // copia o nome passado para o atributo
}

Universidade::~Universidade() {
    // destrutor vazio (não precisa liberar nada aqui)
}

void Universidade::setNome(const char* n) {
    strcpy(nome, n);  // atualiza o nome da universidade
}

const char* Universidade::getNome() {
    return nome;  // retorna o nome
}
