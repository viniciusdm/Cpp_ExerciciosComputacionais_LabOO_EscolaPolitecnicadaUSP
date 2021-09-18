#include "Roteador.h"

#include <string>
#include <iostream>
using namespace std;

Roteador::Roteador(int endereco){
}

Roteador::~Roteador(){
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso){
}

void Roteador::setPadrao(Roteador* padrao, int atraso){
}

int Roteador::getEndereco(){
}
void Roteador::receber(Datagrama* d){
}

Evento* Roteador::processar(int instante){
}

void Roteador::imprimir(){
}
