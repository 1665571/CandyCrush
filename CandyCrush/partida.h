#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <fstream>
#include "tauler.h"

using namespace std;

class Partida
{
public:
    Partida() { m_nMoviments = 0; m_puntuacio = 0; m_nCandies = 0; };
    void inicialitza(const string& nomFitxer);
    void fesMoviment(const Posicio& pos1, const Posicio& pos2);
    void escriuTauler(const string& nomFitxer);
private:
    Tauler m_tauler;
    int m_nMoviments;
    int m_maxMoviments;
    int m_puntuacio;
    int m_nCandies;
    ColorCandy m_candyObjectiu;
    int m_nCandiesObjectiu;
};


#endif