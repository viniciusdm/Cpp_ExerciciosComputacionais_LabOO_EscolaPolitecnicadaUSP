#include "Rede.h"

#include <string>
#include <iostream>
using namespace std;

Rede::Rede(int tamanho){
    tamanhoDaRede = tamanho;
    roteadoresDaRede = new Roteador*[tamanho];
    quantidadeDeRoteadores = 0;
}

Rede::~Rede(){
    for (int i = 0; i < quantidadeDeRoteadores; i++){
        delete roteadoresDaRede[i];
    }
    delete[] roteadoresDaRede;
}

bool Rede::adicionar(Roteador* r){
    for (int i = 0; i < quantidadeDeRoteadores; i++){
        if ((roteadoresDaRede[i] -> getEndereco()) == (r -> getEndereco())){
            return false;
        }
    }
    if (quantidadeDeRoteadores >= tamanhoDaRede){
        return false;
    }
    roteadoresDaRede[quantidadeDeRoteadores++] = r;
    return true;
}

Roteador* Rede::getRoteador(int endereco){
    for (int i = 0; i < quantidadeDeRoteadores; i++){
        if ((roteadoresDaRede[i] -> getEndereco()) == endereco){
            return roteadoresDaRede[i];
        }
    }
    return NULL;
}

Roteador** Rede::getRoteadores(){
    return roteadoresDaRede;
}

int Rede::getQuantidade(){
    return quantidadeDeRoteadores;
}

void Rede::imprimir(){
    cout << "A rede possui os seguintes roteadores: " << endl;
    for (int i = 0; i < quantidadeDeRoteadores; i++){
        cout << "Roteador com endereço: " << roteadoresDaRede[i] -> getEndereco() << endl;
    }
}
