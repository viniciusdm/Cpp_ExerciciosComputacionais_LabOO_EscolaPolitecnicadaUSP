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
    for (int i = 0; i < quantidadeDeEventos; i++){
        delete eventosAgendados[i];
    }
    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d){
    if (quantidadeDeEventos >= quantidadeMaxEventosAgendador){
        return false;
    }
    eventosAgendados[quantidadeDeEventos++] = new Evento(instante, r, d);
    return true;
}

void Agendador::processar(){
    roteadores = redeSimulada -> getRoteadores();
    quantidadeRoteadoresRede = redeSimulada -> getQuantidade();
    for (int i = 0; i < quantidadeDeEventos; i++){
        if ((eventosAgendados[i] -> getInstante()) == instanteInicialSimulacao){
            destinoAPassar = eventosAgendados[i] -> getDestino();
            datagramaAPassar = eventosAgendados[i] -> getDatagrama();
            destinoAPassar -> receber(datagramaAPassar);
            delete eventosAgendados[i];
            quantidadeDeEventos -= 1;
            for (int j = 0; j < quantidadeRoteadoresRede; j++){
                novoEvento = roteadores[j] -> processar(i);
                if (novoEvento != NULL){
                        eventosAgendados[i++] = novoEvento;
                        quantidadeDeEventos += 1;
                }
            }
        }
    instanteInicialSimulacao += 1;   
    }
}

int Agendador::getInstante(){
    return instanteInicialSimulacao;
}