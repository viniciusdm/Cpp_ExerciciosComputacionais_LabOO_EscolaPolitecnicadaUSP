#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Rede.h"
#include "Roteador.h"
#include "Datagrama.h"

#include <iostream>
#include <string>
using namespace std;

class Agendador {
private:
    int instanteInicialSimulacao;
    Rede* redeSimulada;
    int quantidadeMaxEventosAgendador;
    Evento** eventosAgendados;
    int quantidadeDeEventos;
    Roteador** roteadores;
    Datagrama* datagramaAPassar;
    int quantidadeRoteadoresRede;
    Evento* novoEvento;
    Roteador* roteadorAPassar;

public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    ~Agendador();
    bool agendar(int instante, Roteador* r, Datagrama* d);
    void processar();
    int getInstante();
};

#endif