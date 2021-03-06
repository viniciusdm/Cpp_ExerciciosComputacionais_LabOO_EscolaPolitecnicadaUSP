#include "Agendador.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Fila.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

#include <string>
#include <iostream>
using namespace std;

int main(){

    int opcaoDeMenu;
    
    int enderecoOrigem;
    int enderecoDestino;
    int instante;
    string msg;
    int maxEventosAgendador = 10;
    int instanteInicial = 1;
    int tempo;

    Rede *redeSimulada = new Rede(6);

    Roteador *r1 = new Roteador(1);
    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);
    Roteador *r5 = new Roteador(5);
    Roteador *r6 = new Roteador(6);

    redeSimulada -> adicionar(r1);
    redeSimulada -> adicionar(r2);
    redeSimulada -> adicionar(r3);
    redeSimulada -> adicionar(r4);
    redeSimulada -> adicionar(r5);
    redeSimulada -> adicionar(r6);

    r1 -> mapear(2, r2, 2);
    r1 -> setPadrao(r3, 1);

    r2 -> mapear(1, r1, 2);
    r2 -> setPadrao(r4, 1);

    r3 -> mapear(1, r1, 1);
    r3 -> mapear(5, r5, 2);
    r3 -> setPadrao(r4, 1);

    r4 -> mapear(2, r2, 1);
    r4 -> mapear(6, r6, 1);
    r4 -> setPadrao(r3, 1);

    r5 -> mapear(6, r6, 2);
    r5 -> setPadrao(r3, 2);

    r6 -> mapear(5, r5, 2);
    r6 -> setPadrao(r4, 1);

    Agendador *agendador = new Agendador(instanteInicial, redeSimulada, maxEventosAgendador);

    menu1:
    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcaoDeMenu;
    cout << endl;

    switch(opcaoDeMenu){

    case 0:
        return 0;

    case 1:
        cout << "Endereço do roteador de origem: ";
        cin >> enderecoOrigem;

        if (enderecoOrigem == 1 || enderecoOrigem == 2 || enderecoOrigem == 3 || enderecoOrigem == 4 || enderecoOrigem == 5 || enderecoOrigem == 6){

            cout << "Instante: ";
            cin >> instante;
            cout << "Endereço de destino: ";
            cin >> enderecoDestino;
            cout << "Mensagem: ";
            cin >> msg;

            Datagrama *datagrama = new Datagrama(enderecoOrigem, enderecoDestino, msg);
            
            if (enderecoOrigem == 1){
                if (agendador -> agendar(instante, r1, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            if (enderecoOrigem == 2){
                if (agendador -> agendar(instante, r2, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            if (enderecoOrigem == 3){
                if (agendador -> agendar(instante, r3, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            if (enderecoOrigem == 4){
                if (agendador -> agendar(instante, r4, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            if (enderecoOrigem == 5){
                if (agendador -> agendar(instante, r5, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            if (enderecoOrigem == 6){
                if (agendador -> agendar(instante, r6, datagrama) == false){ 
                    cout << endl;
                    cout << "Erro: Sem espaco para agendar o evento" << endl;
                    cout << endl;
                    goto menu1;
                } 
            }

            cout << endl;
            goto menu1;
        }
        else {
            cout << endl;
            cout << "Erro: Origem desconhecida" << endl;
            cout << endl;
            goto menu1;
        }

    case 2:
        cout << "Quantidade de tempo: ";
        cin >> tempo;
        cout << endl;
        for (int k = 0; k < tempo; k++){
            cout << "Instante " << agendador -> getInstante() << endl;
            cout << "---" << endl;
            agendador -> processar();
            cout << endl;
        }
        goto menu1;
    }
}