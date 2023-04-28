#include "tauler.h"


void Tauler::setCandy(const Candy& candy, const int i, const int j)
{
	m_tauler[i][j] = candy;
	m_tauler[i][j].setPosicio(i, j);
}

void Tauler::intercanvia(const Posicio& p1, const Posicio& p2)
{
	Candy aux = m_tauler[p1.getFila()][p1.getColumna()];
	m_tauler[p1.getFila()][p1.getColumna()] = m_tauler[p2.getFila()][p2.getColumna()];
	m_tauler[p2.getFila()][p2.getColumna()] = aux;
}	

bool Tauler::junts(const Posicio& p1, const Posicio& p2)
{
	return ((p1.getFila() == p2.getFila() && (p1.getColumna() - p2.getColumna() == 1 || p1.getColumna() - p2.getColumna() == -1)) || ((p1.getColumna() == p2.getColumna() && (p1.getFila() - p2.getFila() == 1 || p1.getFila() - p2.getFila() == -1))));
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
			output << c << " ";
		}
		output << endl;
	}
	return output;
}

bool Tauler::elimina(const Posicio& posicio1, const Posicio& posicio2)
{
	Candy candyEliminat, candyRatllatH, candyRatllatV;
	candyEliminat.setColor(NO_COLOR);
	candyEliminat.setTipus(NO_TIPUS);
	candyRatllatH.setTipus(RATLLAT_HORIZONTAL);
	candyRatllatV.setTipus(RATLLAT_VERTICAL);

	int contador = 0;
	bool movValid = false;

	//Recorremos por columnas
	for (int f = 0; f < MAX_FILES; f++)
		for (int c = 0; c < MAX_COLUMNES; c++)
		{
			if (m_tauler[f][c].getColor() == m_tauler[f][c + 1].getColor())
			{
				contador++;
			}
			else
			{
				//Si se pude hacer el movimiento eliminamos los candys
				if (contador >= 2)
				{
					if (contador == 2)
					{
						for (int i = 0; i < contador; i++)
						{
							setCandy(candyEliminat, f, c - i);
						}
					}
					else
					{
						for (int i = 0; i < contador; i++)
						{
							if (f == posicio1.getFila() && c - i == posicio1.getColumna())
							{
								candyRatllatH.setColor(m_tauler[f][c - i].getColor());
								setCandy(candyRatllatH, f, c - i);
							}
							if (f == posicio2.getFila() && c - i == posicio2.getColumna())
							{
								candyRatllatH.setColor(m_tauler[f][c - i].getColor());
								setCandy(candyRatllatH, f, c - i);
							}
						}
					}
					movValid = true;
				}
				contador = 0;
			}
		}

	//Recorremos pot filas
	for (int c = 0; c < MAX_COLUMNES; c++)
		for (int f = 0; f < MAX_FILES; f++)
		{
			if (m_tauler[f][c].getColor() == m_tauler[f + 1][c].getColor())
			{
				contador++;
			}
			else
			{
				//Si se pude hacer el movimiento eliminamos los candys
				if (contador >= 3)
				{
					if (contador == 3)
					{
						for (int i = 0; i < contador; i++)
						{
							setCandy(candyEliminat, f - i, c);
						}
					}
					else
					{
						for (int i = 0; i < contador; i++)
						{
							if (f - i == posicio1.getFila() && c == posicio1.getColumna())
							{
								candyRatllatV.setColor(m_tauler[f - i][c].getColor());
								setCandy(candyRatllatV, f - i, c);
							}
							if (f - i == posicio2.getFila() && c == posicio2.getColumna())
							{
								candyRatllatV.setColor(m_tauler[f - i][c].getColor());
								setCandy(candyRatllatV, f - i, c);
							}
						}
					}
					movValid = true;
				}
				contador = 0;
			}
		}

	return movValid;

}

void Tauler::desplacament()
{
	for (int f = MAX_FILES; f > 0; f--)
	{
		for (int c = 0; c < MAX_COLUMNES; c++)
		{
			if ((m_tauler[f][c].getColor() == NO_COLOR) && (m_tauler[f][c].getTipus() == NO_TIPUS))
			{
				bool trobat = false;
				int fila2 = f;
				while ((fila2 >= 0) && (!trobat))
				{
					if ((m_tauler[fila2][c].getColor() != NO_COLOR) && (m_tauler[fila2][c].getTipus() != NO_TIPUS))
					{
						trobat = true;
					}
					else
					{
						fila2--;
					}
				}
				if (trobat)
				{
					m_tauler[f][c].setColor(m_tauler[fila2][c].getColor());
					m_tauler[f][c].setTipus(m_tauler[fila2][c].getTipus());
					m_tauler[fila2][c].setColor(NO_COLOR);
					m_tauler[fila2][c].setTipus(NO_TIPUS);
				}
			}
		}
	}
}

void Tauler::afegirCaramels()
{
	//Añadimos caramelos en el orden R O Y B G P 
	//Con prioridad de abajo a arriba y de izquierda a derecha
	int count = 0;

	for (int f = MAX_FILES; f < 0; f--)
	{
		for (int c = 0; c < MAX_COLUMNES; c++)
		{
			if ((m_tauler[f][c].getColor() == NO_COLOR) && (m_tauler[f][c].getTipus() == NO_TIPUS))
			{
				switch (count)
				{
				case 0:
					m_tauler[f][c].setColor(VERMELL);
					m_tauler[f][c].setTipus(NORMAL);
					count++;
					break;
				case 1:
					m_tauler[f][c].setColor(TARONJA);
					m_tauler[f][c].setTipus(NORMAL);
					count++;
					break;
				case 2:
					m_tauler[f][c].setColor(GROC);
					m_tauler[f][c].setTipus(NORMAL);
					count++;
					break;
				case 3:
					m_tauler[f][c].setColor(BLAU);
					m_tauler[f][c].setTipus(NORMAL);
					count++;
					break;
				case 4:
					m_tauler[f][c].setColor(VERD);
					m_tauler[f][c].setTipus(NORMAL);
					count++;
					break;
				case 5:
					m_tauler[f][c].setColor(LILA);
					m_tauler[f][c].setTipus(NORMAL);
					count = 0;
					break;
				}

			}
		}
	}
}
