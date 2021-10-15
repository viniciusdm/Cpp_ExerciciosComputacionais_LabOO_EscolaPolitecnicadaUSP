#include "Fila.h"

#include <string>
#include <iostream>
using namespace std;

Fila::Fila(int tamanho){
    tamanhoMaxDaFila = tamanho;
    filaDeDatagramas = new Datagrama*[tamanho];
    copiaDatagrama = new Datagrama*[1];
    quantidadeDaFila = 0;
}

Fila::~Fila(){
    for (int i = 0, i < quantidadeDaFila, i++){
        delete filaDeDatagramas[i];
    }
    delete[] filaDeDatagramas;
}


bool Fila::enqueue(Datagrama *d){
    if (quantidadeDaFila >= tamanhoMaxDaFila){
        return false;
    }
    filaDeDatagramas[quantidadeDaFila++] = d;
    return true;
}

Datagrama* Fila::dequeue(){
    if (quantidadeDaFila != 0){
        copiaDatagrama[0] = filaDeDatagramas[0];
        filaDeDatagramas[0] = filaDeDatagramas[1]; 
        filaDeDatagramas[1] = filaDeDatagramas[2]; 
        filaDeDatagramas[2] = filaDeDatagramas[3];
        filaDeDatagramas[3] = NULL; 
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
