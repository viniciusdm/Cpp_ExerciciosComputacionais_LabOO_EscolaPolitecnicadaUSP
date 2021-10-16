#include "Roteador.h"

#include <string>
#include <iostream>
using namespace std;

Roteador::Roteador(int endereco){
    enderecoDoRoteador = endereco;
    tabelaDoRoteador = new TabelaDeRepasse(TAMANHO);
    filaDoRoteador = new Fila(TAMANHO);
}

Roteador::~Roteador(){
    delete tabelaDoRoteador;
    delete filaDoRoteador;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso){
    foiMapeado = tabelaDoRoteador -> mapear(endereco, adjacente, atraso);
    return foiMapeado;
}

void Roteador::setPadrao(Roteador* padrao, int atraso){
    tabelaDoRoteador -> setPadrao(padrao, atraso);
}

int Roteador::getEndereco(){
    return enderecoDoRoteador;
}

void Roteador::receber(Datagrama* d){
    if ((filaDoRoteador -> getSize()) >= TAMANHO){
        cout << "\tFila em " << enderecoDoRoteador << " estourou" << endl;
    }
    else {
    filaDoRoteador -> enqueue(d);
    }
}

Evento* Roteador::processar(int instante){
    if (filaDoRoteador -> isEmpty() == true){
        return NULL;
    }

    cout << "Roteador " << enderecoDoRoteador << endl;
    datagrama = filaDoRoteador -> dequeue();
    
    if ((datagrama -> getDestino()) == enderecoDoRoteador){
        
        cout << "\tRecebido: " << datagrama -> getDado() << endl; 

        delete datagrama;
        return NULL;
    }

    roteadorAPassar = tabelaDoRoteador -> getProximoSalto(datagrama -> getDestino(), atraso);
    if (roteadorAPassar == NULL){

        cout << "\tSem proximo: ";
        datagrama -> imprimir();

        delete datagrama;
        return NULL;
    }
    
    instanteComAtraso = instante + atraso;
    eventoDoRoteador = new Evento(instanteComAtraso, roteadorAPassar, datagrama);
    
    cout << "\tRepassado para " << roteadorAPassar -> getEndereco() << " (instante " << instanteComAtraso << "): ";
    datagrama -> imprimir();

    return eventoDoRoteador;
}

void Roteador::imprimir(){
    cout << "Roteador com endereço: " << enderecoDoRoteador << " com evento no instante: " << instanteComAtraso << endl;
}
