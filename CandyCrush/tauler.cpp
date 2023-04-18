#include "tauler.h"


void Tauler::setCandy(const Candy& candy, const int i, const int j)
{
	m_tauler[i][j] = candy;
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