#include "Evento.h"

#include <string>
#include <iostream>
using namespace std;

Evento::Evento(int instante, Roteador* destino, Datagrama* d){
    this -> instante = instante;
    this -> destino = destino;
    this -> d = d;

}

Evento::~Evento(){
    delete destino;
}

int Evento::getInstante(){
    return instante;
}

Roteador* Evento::getDestino(){
    return destino;
}

Datagrama* Evento::getDatagrama(){
    return d;
}

void Evento::imprimir(){
    cout << "Informaçöes do Evento: " << endl;
    cout << endl;
    cout << "Instante do evento: " << instante << endl;
    cout << "Roteador destino: " << destino << endl;
    cout << "Datagrama: " << d << endl;
}
