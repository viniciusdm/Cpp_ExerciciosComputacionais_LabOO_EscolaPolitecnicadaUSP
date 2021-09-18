#include "Fila.h"

#include <string>
#include <iostream>
using namespace std;

Fila::Fila(int tamanho){
    datagramas = new Datagrama*[tamanho];
    copiaDatagrama = new Datagrama*[1];
    quantidade = 0;
}

bool Fila::enqueue(Datagrama *d){
    if (quantidade >= size){
        return false;
    }
    datagramas[quantidade++] = d;
    return true;
}

Datagrama* Fila::dequeue(){
    if (quantidade != 0){
        copiaDatagrama[0] = datagramas[0];
        datagramas[0] = datagramas[1]; 
        datagramas[1] = datagramas[2]; 
        datagramas[2] = datagramas[3];
        datagramas[3] = NULL; 
        quantidade -= 1;
        return copiaDatagrama[0];
    }
    return NULL;
}

bool Fila::isEmpty(){
    if (quantidade == 0){
        return true;
    }
    return false;
}

int Fila::getSize(){
    return quantidade;
}

void Fila::imprimir(){
    cout << "Fila com " << quantidade << " Datagramas" << endl;
}
