#include "Roteador.h"

#include <string>
#include <iostream>
using namespace std;

Roteador::Roteador(int endereco){
    enderecoDoRoteador = endereco;
    tabelaDoRoteador = new TabelaDeRepasse(10);
    filaDoRoteador = new Fila(10);
    quantidadeDoRoteador = 0;

}

Roteador::~Roteador(){
    delete tabelaDoRoteador;
    delete filaDoRoteador;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso){
    roteadoresDaTabela = tabelaDoRoteador -> getAdjacentes();
    for (int i = 0; i < quantidadeDoRoteador; i++){
        if ((roteadoresDaTabela[i] -> getEndereco()) == endereco){
            return false;
        }
    }
    if (quantidadeDoRoteador >= TAMANHO){
        return false;
    }
    tabelaDoRoteador -> mapear(endereco, adjacente, atraso);
    quantidadeDoRoteador = quantidadeDoRoteador + 1;
    return true;
}

void Roteador::setPadrao(Roteador* padrao, int atraso){
    padraoDaTabela = padrao;
    atrasoDoPadraoDaTabela = atraso;
}

int Roteador::getEndereco(){
    return enderecoDoRoteador;
}
void Roteador::receber(Datagrama* d){
    if ((filaDoRoteador -> getSize()) >= TAMANHO){
        cout << "\tFila em " << enderecoDoRoteador << " estourou" << endl;
    }
    filaDoRoteador -> enqueue(d);
}

Evento* Roteador::processar(int instante){
    if (filaDoRoteador == NULL){
        return NULL;
    }

    cout << "Roteador " << enderecoDoRoteador << endl;

    datagrama = filaDoRoteador -> dequeue();
    if ((datagrama -> getDestino()) == enderecoDoRoteador){
        
        cout << "\tRecebido: " << datagrama -> getDado() << endl; 

        delete datagrama;
        return NULL;
    }

    roteadorAPassar = tabelaDoRoteador -> getProximoSalto();
    if (roteadorAPassar == NULL){

        cout << "\tSem proximo: " << "Origem: " << datagrama -> getOrigem() << ", Destino: " << datagrama -> getDestino() << ", " << datagrama -> getDado() << endl; 

        delete datagrama;
        return NULL;
    }

    instanteComAtraso = instante + atraso;
    eventoDoRoteador = new Evento(instanteComAtraso, roteadorAPassar, datagrama);
    
    cout << "\tRepassado para " << roteadorAPassar -> getEndereco() << " (instante " << instanteComAtraso << " ): " << "Origem: " << datagrama -> getOrigem() << ", Destino: " << datagrama -> getDestino() << ", " << datagrama -> getDado() << endl; 

    return eventoDoRoteador;
}

void Roteador::imprimir(){
    cout << "Roteador com endereço: " << enderecoDoRoteador << " com evento no instante: " << instanteComAtraso << endl;
}
