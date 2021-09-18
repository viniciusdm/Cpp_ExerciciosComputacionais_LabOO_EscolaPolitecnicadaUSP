#include "Datagrama.h"

#include <string>
#include <iostream>
using namespace std;

Datagrama::Datagrama(int origem, int destino, string dado){
    this -> origem = origem;
    this -> destino = destino;
    this -> dado = dado;
}
Datagrama::~Datagrama(){
}

int Datagrama::getDestino(){
    return destino;
}

int Datagrama::getOrigem(){
    return origem;
}

string Datagrama::getDado(){
    return dado;
}

void Datagrama::imprimir(){
    cout << "Datagrama com a mensagem: " << getDado() << endl;
}