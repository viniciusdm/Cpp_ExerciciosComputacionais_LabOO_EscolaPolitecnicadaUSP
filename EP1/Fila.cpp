#include "Fila.h"

#include <string>
#include <iostream>
using namespace std;

Fila::Fila(int tamanho){
    tamanhoMaxDaFila = tamanho;
    datagramas = new Datagrama*[tamanho];
    copiaDatagrama = new Datagrama*[1];
    quantidadeDaFila = 0;
}

bool Fila::enqueue(Datagrama *d){
    if (quantidadeDaFila >= tamanhoMaxDaFila){
        return false;
    }
    datagramas[quantidadeDaFila++] = d;
    return true;
}

Datagrama* Fila::dequeue(){
    if (quantidadeDaFila != 0){
        copiaDatagrama[0] = datagramas[0];
        datagramas[0] = datagramas[1]; 
        datagramas[1] = datagramas[2]; 
        datagramas[2] = datagramas[3];
        datagramas[3] = NULL; 
        quantidadeDaFila -= 1;
        return copiaDatagrama[0];
    }
    return NULL;
}

bool Fila::isEmpty(){
    if (quantidadeDaFila == 0){
        return true;
    }
    return false;
}

int Fila::getSize(){
    return quantidadeDaFila;
}

void Fila::imprimir(){
    cout << "Fila com " << quantidadeDaFila << " Datagramas" << endl;
}
