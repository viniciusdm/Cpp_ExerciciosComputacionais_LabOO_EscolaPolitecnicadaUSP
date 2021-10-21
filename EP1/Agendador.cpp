#include "Agendador.h"

#include <string>
#include <iostream>
using namespace std;

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho){
    instanteSimulacao = instanteInicial;
    redeSimulada = rede;
    quantidadeMaxEventosAgendador = tamanho;
    eventosAgendados = new Evento*[tamanho];
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
        int reverifica = 0;
        if (eventosAgendados[i] != NULL){
            if ((eventosAgendados[i] -> getInstante()) == instanteSimulacao){
                
                roteadorAPassar = eventosAgendados[i] -> getDestino();
                datagramaAPassar = eventosAgendados[i] -> getDatagrama();
                roteadorAPassar -> receber(datagramaAPassar);

                for(int k = i; k < quantidadeDeEventos-1; k++){
                    eventosAgendados[k] = eventosAgendados[k+1];
                }

                eventosAgendados[quantidadeDeEventos-1] = NULL;
                quantidadeDeEventos -= 1;
                reverifica = 1;
            }
        }
        if (reverifica == 0){
            i = i + 1;
        }
    }

    for (int j = 0; j < quantidadeRoteadoresRede; j++){
        novoEvento = roteadores[j] -> processar(instanteSimulacao);
            if (novoEvento != NULL && quantidadeDeEventos < quantidadeMaxEventosAgendador){
                eventosAgendados[quantidadeDeEventos++] = novoEvento;
            }
    }
    instanteSimulacao += 1;   
}

int Agendador::getInstante(){
    return instanteSimulacao;
}