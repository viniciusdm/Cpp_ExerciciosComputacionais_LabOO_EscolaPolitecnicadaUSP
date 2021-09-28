#ifndef REDE_H
#define REDE_H

#include "Roteador.h"

#include <iostream>
#include <string>
using namespace std;

class Rede {
private:
    int tamanhoDaRede;
    Roteador** roteadoresDaRede;
    int quantidadeDeRoteadores; 

public:
    Rede(int tamanho);
    ~Rede();
    bool adicionar(Roteador* r);
    Roteador* getRoteador(int endereco);
    Roteador** getRoteadores();
    int getQuantidade();
    void imprimir();
};

#endif