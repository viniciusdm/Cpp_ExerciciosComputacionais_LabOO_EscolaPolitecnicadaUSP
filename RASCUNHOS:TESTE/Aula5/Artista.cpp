#include "Artista.h"

#include <string>
#include <iostream>
using namespace std;

Artista::Artista(int quantidadeMaxima, string nome){
    this -> quantidadeMaxima = quantidadeMaxima;
    this -> nome = nome;
    quantidade = 0;
    musicas = new Musica*[quantidadeMaxima];
}

Artista::~Artista(){
    cout << "Artista com " << quantidade << " musica(s) destruido" << endl;
    for (int i = 0; i < quantidade; i++)
        delete musicas[i];
    delete[] musicas;
}

Musica** Artista::getMusicas() const {
    return musicas;
}

int Artista::getQuantidadeMusicas() const {
    return quantidade;
}

int Artista::getQuantidadeMaximaMusicas() const {
    return quantidadeMaxima;
}

string Artista::getNome() const {
    return nome;
}

bool Artista::adicionarMusica(Musica* musica) {
    if (quantidade >= quantidadeMaxima)
        return false;
    musicas[quantidade++] = musica;
    return true;
}

void Artista::imprimir() {
    cout << getNome() << endl;
}
