#ifndef CANDY_H
#define CANDY_H

#include "posicio.h"
#include "definicions.h"


using namespace std;

class Candy
{
public:
	void setColor(const ColorCandy& color);
	void setTipus(const TipusCandy& tipo);
	ColorCandy getColor() const { return m_color; };
	TipusCandy getTipus() const { return m_tipus; };
	void StringToCandy(const string& codi);
	string CandyToString();
private:
	ColorCandy m_color;
	TipusCandy m_tipus;
	Posicio posicioCandy;
};

ifstream& operator>>(ifstream& input, Candy& c);
  
#endif
