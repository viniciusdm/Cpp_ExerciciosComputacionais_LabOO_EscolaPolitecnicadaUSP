#include "Fila.h"

#include <string>
#include <iostream>
using namespace std;

Fila::Fila(int size){
    this -> size = size;
    datagramas = new Datagrama*[size];
    quantidade = 0;
}

Fila::~Fila(){    
}

int Fila::getSize() const {
    return size;
}

