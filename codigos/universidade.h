#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

class Universidade {
private:
    char nome[30];  // atributo privado que guarda o nome da universidade

public:
    Universidade(const char* n = "");  // construtor com parâmetro default (nome vazio)
    ~Universidade();                   // destrutor

    void setNome(const char* n);      // método para definir o nome
    const char* getNome();             // método para retornar o nome (como const char*)
};

#endif
