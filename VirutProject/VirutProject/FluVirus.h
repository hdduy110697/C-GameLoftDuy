#pragma once
#include "Viruts.h"
#include "FluVirus.h"
#include <list>
using namespace std;
class FluVirus :public Viruts
{
public:
	void setColor(int dna);
	int getColor();
	FluVirus(FluVirus &fluViruts);
	FluVirus();
	void DoBorn();
	list<Viruts*> DoClone();
	void DoDie();
	void InitResistance();
private:
	int m_color;
};

