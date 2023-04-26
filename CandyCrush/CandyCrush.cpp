#include "partida.h"
#include <iostream>
using namespace std;

int main() {
    Partida p;
    p.inicialitza("TextoLectura.txt");
    p.escriuTauler("TextoEscritura.txt");
}  