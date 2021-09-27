#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO 10

#include "Datagrama.h"
#include "Evento.h"

#include <iostream>
#include <string>
using namespace std;

class TabelaDeRepasse; //Protótipo da Classe TabelaDeRepasse
class Evento; //Protótipo da Classe Evento

class Roteador {
private:

public:
    Roteador(int endereco);
    ~Roteador();
    bool mapear(int endereco, Roteador* adjacente, int atraso);
    void setPadrao(Roteador* padrao, int atraso);
    int getEndereco();
    void receber(Datagrama* d);
    Evento* processar(int instante);
    void imprimir();
};

#endif