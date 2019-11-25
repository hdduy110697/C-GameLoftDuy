#pragma once
#include <list>
#include "Viruts.h"
#include <iostream>
using namespace std;
class patient
{
public:
	void InitResistance();
	void DoStart();
	void TakeMedicine();
	void DoDie();
	int GetState();
	int GetSizeListViruts();
	void DeadTotalVirusResistance();
	patient();
	~patient();
private:
	int m_resistance;
	// the virus resistance ability(10 – 30)
	list<Viruts*> m_virusList;
	int m_state;// 0 – DIE, 1 - ALIVE
};

