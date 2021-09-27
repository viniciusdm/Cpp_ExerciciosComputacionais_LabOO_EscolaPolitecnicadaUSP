#include "Roteador.h"

#include <string>
#include <iostream>
using namespace std;

Roteador::Roteador(int endereco){
    this -> endereco = endereco;
    tabelaDoRoteador = new TabelaDeRepasse(10);
    filaDoRoteador = new Fila(10);
    quantidade = 0;

}

Roteador::~Roteador(){
    delete tabelaDoRoteador;
    delete filaDoRoteador;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso){
    enderecosDaTabela = tabelaDoRoteador -> getEnderecos();
    for (int i = 0; i < quantidade; i++){
        if (enderecosDaTabela[i] == endereco){
            return false;
        }
    }
    if (quantidade >= TAMANHO){
        return false;
    }
    tabelaDoRoteador -> mapear(endereco, adjacente, atraso);
    quantidade = quantidade + 1;
    return true;
}

void Roteador::setPadrao(Roteador* padrao, int atraso){
    this -> padraoDaTabela = padrao;
    this -> atrasoDoPadraoDaTabela = atraso;
}

int Roteador::getEndereco(){
    return endereco;
}
void Roteador::receber(Datagrama* d){
    if ((filaDoRoteador -> getSize()) >= TAMANHO){
        cout << "\tFila em " << endereco << " estourou" << endl;
    }
    filaDoRoteador -> enqueue(d);
}

Evento* Roteador::processar(int instante){
    if (filaDoRoteador == NULL){
        return NULL;
    }
    datagrama = filaDoRoteador -> dequeue();
    if ((datagrama -> getDestino()) == endereco){
        delete datagrama;
        return NULL;
    }
    enderecoAPassar = tabelaDoRoteador -> getProximoSalto();
    if (enderecoAPassar == NULL){
        delete datagrama;
        return NULL;
    }
    

}

void Roteador::imprimir(){
}
