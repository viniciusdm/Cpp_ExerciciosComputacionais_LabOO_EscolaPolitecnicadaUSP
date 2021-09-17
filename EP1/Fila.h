#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>
using namespace std;

class Fila {
private:
    int size;
    Datagrama** datagramas;
    int quantidade;
    
public:
    Fila(int tamanho);
    bool enqueue(Datagrama* d); 
    Datagrama* dequeue(); 
    bool isEmpty(); 
    int getSize(); 
    void imprimir();
};

#endif