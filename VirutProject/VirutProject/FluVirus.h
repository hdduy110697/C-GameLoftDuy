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
	FluVirus(const FluVirus &fluViruts);
	FluVirus();
	void DoBorn();
	list<Viruts*> DoClone();
	void DoDie();
	void InitResistance();
	~FluVirus();
private:
	int m_color;

};

