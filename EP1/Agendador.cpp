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
    
    int i = 0;

    while (i < quantidadeDeEventos){
        reverifica:
        if (eventosAgendados[i] != NULL){
            if ((eventosAgendados[i] -> getInstante()) == instanteInicialSimulacao){
                destinoAPassar = eventosAgendados[i] -> getDestino();
                datagramaAPassar = eventosAgendados[i] -> getDatagrama();
                destinoAPassar -> receber(datagramaAPassar);
                
                for(int k = i; k < quantidadeDeEventos-1; k++){
                    eventosAgendados[k] = eventosAgendados[k+1];
                }

                eventosAgendados[quantidadeDeEventos-1] = NULL;
                quantidadeDeEventos -= 1;

                for (int h = 0; h < quantidadeDeEventos; h++){
                    eventosAgendados[h] -> imprimir();
                }
                goto reverifica;
            }
        }
        i = i + 1;
    }

    for (int j = 0; j < quantidadeRoteadoresRede; j++){
        novoEvento = roteadores[j] -> processar(instanteInicialSimulacao);
            if (novoEvento != NULL){
                eventosAgendados[quantidadeDeEventos++] = novoEvento;
            }
    }
    instanteInicialSimulacao += 1;   
}

int Agendador::getInstante(){
    return instanteInicialSimulacao;
}