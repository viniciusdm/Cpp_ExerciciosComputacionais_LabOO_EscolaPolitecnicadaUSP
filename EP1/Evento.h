#ifndef EVENTO_H
#define EVENTO_H

#include "Roteador.h"
#include "Datagrama.h"

#include <iostream>
#include <string>
using namespace std;

class Roteador; //Protótipo da Classe Roteador

class Evento {
private:
    int instanteDoEvento;
    Roteador* destinoDoEvento;
    Datagrama* datagramaDoEvento;

public:
    Evento(int instante, Roteador* destino, Datagrama* d);
    ~Evento();
    int getInstante();
    Roteador* getDestino();
    Datagrama* getDatagrama();
    void imprimir();
};

#endif