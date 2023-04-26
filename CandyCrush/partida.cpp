#include "partida.h"

void Partida::inicialitza(const string& nomFitxer)
{
	char colorCandy;
	ifstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> colorCandy;
		fitxer >> m_nCandiesObjectiu;
		fitxer >> m_maxMoviments;
		fitxer >> m_tauler;
	}
	fitxer.close();
}

void Partida::fesMoviment(const Posicio& pos1, const Posicio& pos2)
{
	
}

void Partida::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
		fitxer << m_tauler;
	
	fitxer.close();

}


