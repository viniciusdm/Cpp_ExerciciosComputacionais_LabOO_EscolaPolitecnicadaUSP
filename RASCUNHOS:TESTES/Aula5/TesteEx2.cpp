#include "Musica.h"
#include "Artista.h"

#include <string>
#include <iostream>
using namespace std;


void teste() {

    Musica *m1 = new Musica(162, "Tiro ao alvaro");
    Musica *m2 = new Musica(162, "Triste");
    Musica *m3 = new Musica(214, "Aguas de marco");
    Musica *m4 = new Musica(228, "Bala com bala");

    Artista *Elis = new Artista(23, "Elis Regina");
    Elis -> adicionarMusica(m1);
    Elis -> adicionarMusica(m2);
    Elis -> adicionarMusica(m3);
    Elis -> adicionarMusica(m4);

    delete Elis;

}

int main() {
    cout << endl;
    teste();
    cout << endl;
    return 0;
}
