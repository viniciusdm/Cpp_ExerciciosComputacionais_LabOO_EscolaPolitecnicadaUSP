#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"

#include <iostream>
#include <string>
using namespace std;

class Roteador;
class TabelaDeRepasse {
private:
    Roteador* padrao;
    int tamanho;

public:
    TabelaDeRepasse(int tamanho);
    ~TabelaDeRepasse();
    bool mapear(int endereco, Roteador* adjacente, int atraso);
    Roteador** getAdjacentes();
    int getQuantidadeDeAdjacentes();
    void setPadrao(Roteador* padrao, int atraso);
    Roteador* getProximoSalto(int endereco, int atraso);
    void imprimir();
};

#endif