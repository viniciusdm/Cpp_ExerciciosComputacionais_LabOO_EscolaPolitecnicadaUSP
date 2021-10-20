#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"

#include <iostream>
#include <string>
using namespace std;

class Roteador; //Protótipo da Classe Roteador

class TabelaDeRepasse {
private:
    Roteador* roteadorPadrao;
    Roteador** roteadoresDaTabela;
    int* enderecosDaTabela;
    int* atrasosDaTabela;
    int tamanhoDaTabela;
    int atrasoPadrao = 0;
    int quantidadeDaTabela = 0;
    
public:
    TabelaDeRepasse(int tamanho);
    ~TabelaDeRepasse();
    bool mapear(int endereco, Roteador* adjacente, int atraso);
    Roteador** getAdjacentes();
    int getQuantidadeDeAdjacentes();
    void setPadrao(Roteador* padrao, int atraso);
    Roteador* getProximoSalto(int endereco, int& atraso);
    void imprimir();
};

#endif