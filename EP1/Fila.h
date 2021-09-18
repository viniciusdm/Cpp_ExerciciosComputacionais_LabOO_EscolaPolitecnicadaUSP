#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

#include <iostream>
#include <string>
using namespace std;
class Fila {
private:
    int size;
    int quantidade;
    Datagrama** datagramas;
    Datagrama** copiaDatagrama;
    
public:
    Fila(int tamanho);
    bool enqueue(Datagrama* d); 
    Datagrama* dequeue(); 
    bool isEmpty(); 
    int getSize(); 
    void imprimir();
};

#endif