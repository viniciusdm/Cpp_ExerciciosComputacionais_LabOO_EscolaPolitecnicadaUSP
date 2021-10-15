#include "Evento.h"

#include <string>
#include <iostream>
using namespace std;

Evento::Evento(int instante, Roteador* destino, Datagrama* d){
    instanteDoEvento = instante;
    destinoDoEvento = destino;
    datagramaDoEvento = d;
}

Evento::~Evento(){
}

int Evento::getInstante(){
    return instanteDoEvento;
}

Roteador* Evento::getDestino(){
    return destinoDoEvento;
}

Datagrama* Evento::getDatagrama(){
    return datagramaDoEvento;
}

void Evento::imprimir(){
    cout << "Informaçöes do Evento: " << endl;
    cout << endl;
    cout << "Instante do evento: " << instanteDoEvento << endl;
    cout << "Roteador destino: " << destinoDoEvento << endl;
    cout << "Datagrama: " << datagramaDoEvento << endl;
}
