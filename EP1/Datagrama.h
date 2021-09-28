#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include <iostream>
#include <string>
using namespace std;

class Datagrama {
private:
    int origemDoDatagrama;
    int destinoDoDatagrama;
    string dadoDoDatagrama;

public:
    Datagrama(int origem, int destino, string dado);
    ~Datagrama(); 
    int getOrigem(); 
    int getDestino(); 
    string getDado(); 
    void imprimir();
};

#endif