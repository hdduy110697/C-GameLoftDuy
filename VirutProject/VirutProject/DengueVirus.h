#pragma once
#include "Viruts.h"
#include <list>
using namespace std;
class DengueVirus :public Viruts
{
public:
	DengueVirus(const DengueVirus& fluViruts);
	DengueVirus();
	void setProtein(const char[] );
	char* getProtein();
	void InitResistance();
	void DoBorn();
	list<Viruts*> DoClone();
	void DoDie();
	~DengueVirus();
private:
	char m_protein[4]; // protein in virus represent the type of Dengue
};

