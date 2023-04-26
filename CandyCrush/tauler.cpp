#include "tauler.h"


void Tauler::setCandy(const Candy& candy, const int i, const int j)
{
	m_tauler[i][j] = candy;
	m_tauler[i][j].setPosicio(i, j);
}

void Tauler::actualitza()
{

}

void Tauler::intercanvia(Candy& c1, Candy& c2)
{
	Candy aux= m_tauler[c1.getPosicio().getFila()][c1.getPosicio().getColumna()];
	m_tauler[c1.getPosicio().getFila()][c1.getPosicio().getColumna()] = m_tauler[c2.getPosicio().getFila()][c2.getPosicio().getColumna()];
	m_tauler[c2.getPosicio().getFila()][c2.getPosicio().getColumna()] = aux;
}

bool Tauler::junts(const Posicio& p1, const Posicio& p2)
{
	return ((p1.getFila() == p2.getFila() && (p1.getColumna() - p2.getColumna() == 1 || p1.getColumna() - p2.getColumna() == -1)) || ((p1.getColumna() == p2.getColumna() && (p1.getFila() - p2.getFila() == 1 || p1.getFila() - p2.getFila() == -1))) );
}

ifstream& operator>>(ifstream& input, Tauler& t)
{
	Candy c;

	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			input >> c;
			t.setCandy(c, i, j);
		}
	}

	return input;

}

ofstream& operator<<(ofstream& output, const Tauler& t)
{
	Candy c;
	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			c = t.getCandy(i, j);
			output << c;
		}
		output << endl;
	}
	return output;
}