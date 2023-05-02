#include "tauler.h"


void Tauler::setCandy(const Candy& candy, const int i, const int j)
{
	Posicio pos;
	m_tauler[i][j].setColor(candy.getColor());
	m_tauler[i][j].setTipus(candy.getTipus());
	pos.set(i, j);
	m_tauler[i][j].setPosicio(pos);
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
	Posicio pos;
	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			pos.set(i, j);
			c = t.getCandy(pos);
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


	//Moviment Horitzontal=1 
	//Moviment Vertical=0
	int tipusMov;
	if (posicio1.getFila() == posicio2.getFila())
		tipusMov = 1;
	else
		tipusMov = 0;

	Posicio pos;

	int contador = 0;
	bool movValid = false;

	bool generadorTrobat = false;

	//Recorremos las filas
	for (int f = 0; f < MAX_FILES; f++)
	{
		contador = 0;
		for (int c = 0; c < MAX_COLUMNES; c++)
		{
			if (m_tauler[f][c].getColor() == m_tauler[f][c + 1].getColor())
			{
				contador++;
			}
			else
			{

				//Si se pude hacer el movimiento eliminamos los candys
				if (contador > 2)
				{
					for (int i = 0; i <= contador; i++)
					{
						if (((f == posicio1.getFila() && c - i == posicio1.getColumna()) || (f == posicio2.getFila() && c - i == posicio2.getColumna())) && (tipusMov == 1) )
						{
							candyRatllatH.setColor(m_tauler[f][c - i].getColor());
							setCandy(candyRatllatH, f, c - i);
							generadorTrobat = true;
						}
						else if (((f == posicio1.getFila() && c - i == posicio1.getColumna()) || (f == posicio2.getFila() && c - i == posicio2.getColumna())) && (tipusMov == 0))
						{
							candyRatllatV.setColor(m_tauler[f][c - i].getColor());
							setCandy(candyRatllatV, f, c - i);
							generadorTrobat = true;
						}
						else
						{
							setCandy(candyEliminat, f, c - i);
						}
					}
					movValid = true;
				}
				if (contador == 2)
				{
					for (int i = 0; i <= contador; i++)
					{
						pos.set(f, c - i);
						if (getCandy(pos).getTipus() == RATLLAT_HORIZONTAL)
						{
							for (int y = 0; y < MAX_COLUMNES; y++)
							{
								setCandy(candyEliminat, f, y);
							}
						}
						else if (getCandy(pos).getTipus() == RATLLAT_VERTICAL)
						{
							for (int x = 0; x < MAX_FILES; x++)
							{
								setCandy(candyEliminat, x, c - i);
							}
						}
						else
						{
							setCandy(candyEliminat, f, c - i);
						}
					}
					movValid = true;
				}
				contador = 0;
			}
		}
	}

	contador = 0;
	//Recorremos las columnas
	for (int c = 0; c < MAX_COLUMNES; c++)
	{
		contador = 0;
		for (int f = 0; f < MAX_FILES; f++)
		{
			if (m_tauler[f][c].getColor() == m_tauler[f + 1][c].getColor())
			{
				contador++;
			}
			else
			{
				//Si se pude hacer el movimiento eliminamos los candys
				if (contador > 2)
				{
					for (int i = 0; i <= contador; i++)
					{
						if (((f - i == posicio1.getFila() && c == posicio1.getColumna()) || (f - i == posicio2.getFila() && c == posicio2.getColumna())) && (tipusMov == 1) )
						{
							candyRatllatH.setColor(m_tauler[f - i][c].getColor());
							setCandy(candyRatllatH, f - i, c);
						}
						else if (((f - i == posicio1.getFila() && c == posicio1.getColumna()) || (f - i == posicio2.getFila() && c == posicio2.getColumna())) && (tipusMov == 0))
						{
							candyRatllatV.setColor(m_tauler[f - i][c].getColor());
							setCandy(candyRatllatV, f - i, c);
						}
						else
						{
							setCandy(candyEliminat, f - i, c);
						}
					}
					movValid = true;
				}
				if (contador == 2)
				{
					for (int i = 0; i <= contador; i++)
					{
						pos.set(f - i, c);
						if (getCandy(pos).getTipus() == RATLLAT_HORIZONTAL)
						{
							for (int y = 0; y < MAX_COLUMNES; y++)
							{
								setCandy(candyEliminat, f - i, y);
							}
						}
						else if (getCandy(pos).getTipus() == RATLLAT_VERTICAL)
						{
							for (int x = 0; x < MAX_FILES; x++)
							{
								setCandy(candyEliminat, x, c);
							}
						}
						else
						{
							setCandy(candyEliminat, f - i, c);
						}
					}
					movValid = true;
				}
				contador = 0;
			}
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

void Tauler::afegeixCaramels(int& count)
{
	//Ordre per afegir els caramels: R O Y B G P 
	//Ordre -> de baix a dalt i esquerra a dreta

	for (int f = MAX_FILES; f >= 0; f--)
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