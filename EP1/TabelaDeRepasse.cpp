#include "TabelaDeRepasse.h"

#include <string>
#include <iostream>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    this -> tamanho = tamanho;
    enderecos = new int[tamanho];
    atrasos = new int[tamanho];
    roteadores = new Roteador*[tamanho];
    roteadorPadrao = NULL;
    atrasoPadrao = 0;
    quantidade = 0;
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
    quantidade = quantidade + 1;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return roteadores;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidade;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    this -> roteadorPadrao = padrao;
    atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < quantidade; i++){
        if (endereco == enderecos[i]){
            atraso = atrasos[i];
            return roteadores[i];
        }
    } 
    atraso = atrasoPadrao;
    return roteadorPadrao;
}

void TabelaDeRepasse::imprimir(){
    cout << "Tabela de Repasse referente ao Roteador de endereço: " << << endl;
}

int* TabelaDeRepasse::getEnderecos(){
    return enderecos;
}