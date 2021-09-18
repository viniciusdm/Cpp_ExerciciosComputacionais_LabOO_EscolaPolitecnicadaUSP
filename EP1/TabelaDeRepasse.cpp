#include "TabelaDeRepasse.h"

#include <string>
#include <iostream>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    this -> tamanho = tamanho;
    int enderecos[tamanho];
    int atrasos[tamanho];
    setPadrao(Roteador* padrao, int 0);
    int quantidade = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso){
    for (int j = 0; j < quantidade; j++){
        if (enderecos[j] == endereco || quantidade = tamanho){
            return false;
        }
    }
    enderecos[quantidade] = endereco;
    atrasos[quantidade] = atraso;
    roteadores[quantidade] = adjacente;
    quantidade += 1;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return roteadores;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return (sizeof(roteadores)/sizeof(*roteadores));
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso){
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int atraso){
}

void TabelaDeRepasse::imprimir(){
}