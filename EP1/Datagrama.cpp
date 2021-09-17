#include "Datagrama.h"

#include <string>
#include <iostream>
using namespace std;

Datagrama::Dtagrama(int origem, int destino, string dado){
    this -> origem = origem;
    this -> destino = destino;
    this -> dado = dado;
}
Datagrama::~Datagrama(){
}

int Datagrama::getDestino() const {
    return destino;
}

int Datagrama::getOrigem() const {
    return origem;
}

string Datagrama::getDado() const {
    return dado;
}

void Artista::imprimir() {
    cout << "Datagrama com a mensagem: " << getDado() << endl;
}