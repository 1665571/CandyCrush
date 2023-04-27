#include "partida.h"

void Partida::inicialitza(const string& nomFitxer)
{
	string colorCandy;
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

	Candy c;
	c.setTipus(NORMAL);
	c.StringToCandy(colorCandy);
	m_candyObjectiu = c.getColor();
}

void Partida::fesMoviment(const Posicio& pos1, const Posicio& pos2)
{
	int caramelsIguals = 0;

	Candy c1 = m_tauler.getCandy(pos1.getFila(), pos1.getColumna());
	Candy c2 = m_tauler.getCandy(pos2.getFila(), pos2.getColumna());

	if (m_tauler.junts(pos1, pos2))
	{
		m_tauler.intercanvia(c1, c2);

		if (!m_tauler.elimina(pos1,pos2))
		{
			m_tauler.intercanvia(c1, c2);
		}
		else
		{
			m_tauler.desplacament();
			m_tauler.afegirCaramels();
		}
	}
}

void Partida::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
		fitxer << m_tauler;

	fitxer.close();

}