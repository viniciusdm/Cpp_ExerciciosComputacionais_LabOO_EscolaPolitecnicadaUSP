#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

#include <iostream>
#include <string>

using namespace std;
class Fila {
private:
    int tamanhoMaxDaFila;
    int quantidadeDaFila = 0;
    Datagrama** filaDeDatagramas;
    Datagrama** copiaDatagrama;
    
public:
    Fila(int tamanho);
    ~Fila();
    bool enqueue(Datagrama* d); 
    Datagrama* dequeue(); 
    bool isEmpty(); 
    int getSize(); 
    void imprimir();
};

#endif