#pragma once
#include "Viruts.h"
#include <list>
using namespace std;
class DengueVirus :public Viruts
{
public:
	DengueVirus(DengueVirus& fluViruts);
	DengueVirus();
	void setProtein(char protein);
	char getProtein();
	void InitResistance();
	void DoBorn();
	list<Viruts*> DoClone();
	void DoDie();
	
private:
	char m_protein[4]; // protein in virus represent the type of Dengue
};

