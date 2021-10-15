#include "Agendador.h"

#include <string>
#include <iostream>
using namespace std;

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho){
    instanteInicialSimulacao = instanteInicial;
    redeSimulada = rede;
    quantidadeMaxEventosAgendador = tamanho;
    eventosAgendados = new Evento*[tamanho];
    quantidadeDeEventos = 0;

}

Agendador::~Agendador(){

}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d){
    if (quantidadeDeEventos >= quantidadeMaxEventos){
        return false;
    }
    eventosAgendados[quantidadeDeEventos++] = new Evento(instante, r, d);
    return true;
}

void Agendador::processar(){
    roteadores = redeASimular -> getRoteadores();
    quantidadeRoteadoresRede = -> redeASimular -> getQuantidade();
    for (int i = 0, i < quantidadeDeEventos, i++){
        if ((eventosAgendados[i] -> getInstante()) == instanteInicialSimulacao){
            destinoAPassaer = eventosAgendados[i] -> getDestino();
            datagramaAPassar = eveventosAgendados[i] -> getDatagrama();
            destinoAPassar -> receber(datagramaAPassar);
            delete eventosAgendados[i];
            for (int j = 0, j < quantidadeRoteadoresRede, j++){
                novoEvento = roteadores[j] -> processar(i);
                if (novoEvento != NULL){
                        eventosAgendados[i++] = novoEvento;
                }
            }
        }
    }
}

int Agendador::getInstante(){
}