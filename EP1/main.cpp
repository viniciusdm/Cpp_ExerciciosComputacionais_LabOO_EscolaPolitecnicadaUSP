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

    int opcao;
    int tempo;
    int enderecoOrigem;
    int instante;
    int enderecoDestino;
    string msg;
    int tamanho = 10;
    int simulacoes = 0;
    int instanteInicial = 1;
    int instanteMostrado = 0;

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

    Agendador *agendador = new Agendador(instanteInicial, redeSimulada, tamanho);

    menu1:
    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    cout << endl;

    switch(opcao){

    case 0:
        return 0;

    case 1:
        if (simulacoes < tamanho){
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
                agendador -> agendar(instante, r1, datagrama); 
                }

                if (enderecoOrigem == 2){
                agendador -> agendar(instante, r2, datagrama); 
                }

                if (enderecoOrigem == 3){
                agendador -> agendar(instante, r3, datagrama); 
                }

                if (enderecoOrigem == 4){
                agendador -> agendar(instante, r4, datagrama); 
                }

                if (enderecoOrigem == 5){
                agendador -> agendar(instante, r5, datagrama); 
                }

                if (enderecoOrigem == 6){
                agendador -> agendar(instante, r6, datagrama); 
                }

                simulacoes += 1;
                cout << endl;
                goto menu1;
            }
            else {
                cout << endl;
                cout << "Erro: Origem desconhecida" << endl;
                cout << endl;
                goto menu1;
            }
        }
        else {
            cout << endl;
            cout << "Erro: Sem espaco para agendar o evento" << endl;
            cout << endl;
            goto menu1;
        }

    case 2:
        cout << "Quantidade de tempo: ";
        cin >> tempo;
        cout << endl;
        for (int k = 0; k < tempo; k++){
            instanteMostrado += 1;
            simulacoes -= 1;
            cout << "Instante " << instanteMostrado << endl;
            cout << "---" << endl;
            agendador -> processar();
            cout << endl;
        }
        goto menu1;
    }
}