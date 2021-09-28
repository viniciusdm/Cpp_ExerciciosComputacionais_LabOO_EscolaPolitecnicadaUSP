#include "TabelaDeRepasse.h"

#include <string>
#include <iostream>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    tamanhoDaTabela = tamanho;
    enderecosDaTabela = new int[tamanho];
    atrasosDaTabela = new int[tamanho];
    roteadoresDaTabela = new Roteador*[tamanho];
    roteadorPadrao = NULL;
    atrasoPadrao = 0;
    quantidadeDaTabela = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] enderecosDaTabela;
    delete[] enderecosDaTabela;
    delete[] roteadoresDaTabela;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso){
    for (int j = 0; j < quantidadeDaTabela; j++){
        if (enderecosDaTabela[j] == endereco){
            return false;
        }
    }
    if (quantidadeDaTabela >= tamanhoDaTabela){
        return false;
    }
    enderecosDaTabela[quantidadeDaTabela] = endereco;
    atrasosDaTabela[quantidadeDaTabela] = atraso;
    roteadoresDaTabela[quantidadeDaTabela] = adjacente;
    quantidadeDaTabela = quantidadeDaTabela + 1;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return roteadoresDaTabela;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidadeDaTabela;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    roteadorPadrao = padrao;
    atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < quantidadeDaTabela; i++){
        if (endereco == enderecosDaTabela[i]){
            atraso = atrasosDaTabela[i];
            return roteadoresDaTabela[i];
        }
    } 
    atraso = atrasoPadrao;
    return roteadorPadrao;
}

void TabelaDeRepasse::imprimir(){
    cout << "Tabela de Repasse referente ao Roteador de endereço: " << << endl;
}
