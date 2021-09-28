#include "Datagrama.h"

#include <string>
#include <iostream>
using namespace std;

Datagrama::Datagrama(int origem, int destino, string dado){
    origemDoDatagrama = origem;
    destinoDoDatagrama = destino;
    dadoDoDatagrama = dado;
}
Datagrama::~Datagrama(){
}

int Datagrama::getDestino(){
    return destinoDoDatagrama;
}

int Datagrama::getOrigem(){
    return origemDoDatagrama;
}

string Datagrama::getDado(){
    return dadoDoDatagrama;
}

void Datagrama::imprimir(){
    cout << "Datagrama com a mensagem: " << getDado() << endl;
}