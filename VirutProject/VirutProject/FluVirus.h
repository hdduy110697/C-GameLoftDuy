#pragma once
#include "Viruts.h"
#include <list>
using namespace std;
class FluVirus :public Viruts
{
	void setColor(int dna);
	int getColor();

	void DoBorn();
	list<Viruts*> DoClone();
	void DoDie();
	void InitResistance();
private:
	int m_color;
};

