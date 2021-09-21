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

int main() {

    cout << "poi" << endl;

    Datagrama *d1 = new Datagrama(1, 2, "um");
    Datagrama *d2 = new Datagrama(1, 2, "dois");
    Datagrama *d3 = new Datagrama(1, 2, "três");
    Datagrama *d4 = new Datagrama(1, 2, "quatro");
    Datagrama *d5 = new Datagrama(1, 2, "cinco");
    Datagrama *d6 = new Datagrama(1, 2, "seis");
    Datagrama *d7 = new Datagrama(1, 2, "sete");
    Datagrama *d8 = new Datagrama(1, 2, "oito");
    Datagrama *d9 = new Datagrama(1, 2, "nove");
    Datagrama *d10 = new Datagrama(1, 2, "dez");
    Datagrama *d11 = new Datagrama(1, 2, "onze");
     Datagrama *d12 = new Datagrama(1, 2, "doze");

    Fila *f1 = new Fila(4);

    f1 -> enqueue(d1);
    f1 -> enqueue(d2);
    f1 -> imprimir();
    f1 -> enqueue(d3);
    f1 -> imprimir();
    f1 -> dequeue();
    f1 -> dequeue();
    f1 -> dequeue();
    f1 -> imprimir();
    f1 -> dequeue();
    f1 -> imprimir();
    f1 -> dequeue();
    f1 -> enqueue(d4);
    f1 -> enqueue(d5);
    f1 -> enqueue(d6);
    f1 -> enqueue(d7);
    f1 -> imprimir();
    f1 -> dequeue();
    f1 -> dequeue();
    f1 -> enqueue(d8);
    f1 -> enqueue(d9);
    f1 -> enqueue(d10);
    f1 -> imprimir();
    f1 -> dequeue();
    f1 -> dequeue();
    f1 -> enqueue(d11);
    f1 -> enqueue(d12);
    f1 -> imprimir();

    
    cout << endl;
    cout << "teste total - LEGAL" << endl;
    cout << endl;
}