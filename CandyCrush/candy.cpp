#include "candy.h"

void Candy::setColor(const ColorCandy& color)
{
	m_color = color;
}
void Candy::setTipus(const TipusCandy& tipo)
{
	m_tipus = tipo;
}
void Candy::StringToCandy(const string& codi)
{
	
	//Codificacio Tipus: NORMAL (N) RATLLAT-HORITZONTAL (RH) RATLLAT-VERTICAL (RV) NO_TIPUS (X)
	//Codificacio Color: VERMELL (R) TARONJA (O) GROC (Y) BLAU (B) VERD (G) LILA (P) NO_COLOR (-)
	//Ordre codificacio: Color Tipus --- per exemple RN (Vermell normal)
	
	//Color
	if (codi[0] == 'R')
		m_color = VERMELL;
	if (codi[0] == 'O')
		m_color = TARONJA;
	if (codi[0] == 'Y')
		m_color = GROC;
	if (codi[0] == 'B')
		m_color = BLAU;
	if (codi[0] == 'G')
		m_color = VERD;
	if (codi[0] == 'P')
		m_color = LILA;
	if (codi[0] == '-')
		m_color = NO_COLOR;

	//Tipus
	if (codi[1] == 'N')
		m_tipus = NORMAL;
	if (codi[1] == 'R' && codi[2] == 'H')
		m_tipus = RATLLAT_HORIZONTAL;
	if (codi[1] == 'R' && codi[2] == 'V')
		m_tipus = RATLLAT_VERTICAL;
	if (codi[1] == 'X')
		m_tipus = NO_TIPUS;


}
string Candy::CandyToString()
{
	string codi;

	//Color
	if (m_color == VERMELL)
		codi[0] = 'R';
	if (m_color == TARONJA)
		codi[0] = 'O';
	if (m_color == GROC)
		codi[0] = 'Y';
	if (m_color == BLAU)
		codi[0] = 'B';
	if (m_color == VERD)
		codi[0] = 'G';
	if (m_color == LILA)
		codi[0] = 'P';
	if (m_color == NO_COLOR)
		codi[0] = '-';

	//Tipus
	if (m_tipus == NORMAL)
		codi[1] = 'N';
	if (m_tipus == RATLLAT_HORIZONTAL)
	{
		codi[1] = 'R';
		codi[2] = 'H';
	}
	if (m_tipus == RATLLAT_VERTICAL)
	{
		codi[1] = 'R';
		codi[2] = 'V';
	}
	if (m_tipus == NO_TIPUS)
		codi[1] = 'X';

	return codi;
}

ifstream& operator>>(ifstream& input, Candy& c)
{
	char color;
	input >> color;

	if (color == 'R')
		c.setColor(VERMELL);
	if (color == 'O')
		c.setColor(TARONJA);
	if (color == 'Y')
		c.setColor(GROC);
	if (color == 'B')
		c.setColor(BLAU);
	if (color == 'G')
		c.setColor(VERD);
	if (color == 'P')
		c.setColor(LILA);

	return input;

}