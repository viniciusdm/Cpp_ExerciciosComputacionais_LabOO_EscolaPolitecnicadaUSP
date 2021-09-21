#include "TabelaDeRepasse.h"

#include <string>
#include <iostream>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    this -> tamanho = tamanho;
    enderecos = new int[tamanho];
    atrasos = new int[tamanho];
    roteadores = new Roteador*[tamanho];
    setPadrao(Roteador* padrao, int 0);
    int quantidade = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] enderecos;
    delete[] enderecos;
    delete[] roteadores;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso){
    for (int j = 0; j < quantidade; j++){
        if (enderecos[j] == endereco){
            return false;
        }
    }
    if (quantidade >= tamanho){
        return false;
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

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    this -> roteadorPadrao = padrao;
    roteadorPadrao = NULL;
    atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int atraso){
}

void TabelaDeRepasse::imprimir(){
    cout << "A tabela de Repasse contém os seguintes roteadores:" << endl;
    for (int i = 0; i < quantidade; i++){
        cout << "Roteador: " << roteadores[i] << " - com Endereço: " << enderecos[i] << " e Atraso: " << atrasos[i] << endl;
    }
}