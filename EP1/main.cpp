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
    int simulacoes = 0;
    int tamanho = 10;

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

    Agendador *agendador = new Agendador(1, redeSimulada, tamanho);

    menu0:
    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    cout << endl;

    if (opcao == 0){
        return 0;
    }

    if (opcao == 1){
        if (simulacoes < tamanho){
        
            cout << "Endereço do roteador de origem: ";
            cin >> enderecoOrigem;
            cout << "Instante: ";
            cin >> instante;
            cout << "Endereço de destino: ";
            cin >> enderecoDestino;
            cout << "Mensagem: ";
            cin >> msg;
            cout << endl;

            if (enderecoOrigem == 1 || enderecoOrigem == 2 || enderecoOrigem == 3 || enderecoOrigem == 4 || enderecoOrigem == 5 || enderecoOrigem == 6){

                Datagrama *datagrama = new Datagrama(enderecoOrigem, enderecoDestino, msg);

                if (enderecoOrigem == 1){
                    r1 -> receber(datagrama);
                    
                }

                if (enderecoOrigem == 2){
                    r2 -> receber(datagrama);
                }

                if (enderecoOrigem == 3){
                    r3 -> receber(datagrama);
                }

                if (enderecoOrigem == 4){
                    r4 -> receber(datagrama);
                }

                if (enderecoOrigem == 5){
                    r5 -> receber(datagrama);
                }  

                if (enderecoOrigem == 6){
                    r6 -> receber(datagrama);
                }                

                if (enderecoDestino == 1){
                agendador -> agendar(instante, r1, datagrama); 
                }

                if (enderecoDestino == 2){
                agendador -> agendar(instante, r2, datagrama); 
                }

                if (enderecoDestino == 3){
                agendador -> agendar(instante, r3, datagrama); 
                }

                if (enderecoDestino == 4){
                agendador -> agendar(instante, r4, datagrama); 
                }

                if (enderecoDestino == 5){
                agendador -> agendar(instante, r5, datagrama); 
                }

                if (enderecoDestino == 6){
                agendador -> agendar(instante, r6, datagrama); 
                }

                simulacoes += 1;
                goto menu0;
            }
            else {
                cout << "Erro: Origem desconhecida" << endl;
                goto menu0;
            }
        }
        else {
            cout << "Erro: Sem espaco para agendar o evento" << endl;
            goto menu0;
        }
    }

    if (opcao == 2){
        cout << "Quantidade de tempo: ";
        cin >> tempo;
        cout << endl;
        for (int k = 1; k <= tempo; k++){
            cout << "Instante " << k << endl;
            cout << "---" << endl;
            agendador -> processar();
            cout << endl;
        }
        goto menu0;
    }
}
