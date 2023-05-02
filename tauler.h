#ifndef TAULER_H
#define TAULER_H
#include "candy.h"
#include "posicio.h"
using namespace std;

class Tauler
{
public:
	void setCandy(const Candy& candy, const int i, const int j);
	Candy getCandy(const Posicio& pos) const { return m_tauler[pos.getFila()][pos.getColumna()]; };
	bool junts(const Posicio& p1, const Posicio& p2);
	void intercanvia(const Posicio& p1, const Posicio& p2);
	void afegeixCaramels(int& count);
	void desplacament();
	bool elimina(const Posicio& posicio1, const Posicio& posicio2);
private:
	Candy m_tauler[MAX_FILES][MAX_COLUMNES];
};


ifstream& operator>>(ifstream& input, Tauler& t);
ofstream& operator<<(ofstream& input, const Tauler& t);

#endif