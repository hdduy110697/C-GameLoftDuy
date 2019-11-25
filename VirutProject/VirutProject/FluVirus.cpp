#include "FluVirus.h"
#include "Viruts.h"
#include <stdlib.h>
#include<iostream>
#include <list>
#define RED 0xff0000
#define BLUE 0x0000ff
using namespace std;

void FluVirus::setColor(int color)
{
	m_color = color;
}

int FluVirus::getColor()
{
	return m_color;
}
void FluVirus::InitResistance()
{
	if (m_color == RED)
	{
		int res = 10 + rand() % (20 + 1 - 10);// random 10-20
		setResistance(res);
	}
	if (m_color == BLUE)
	{
		int res = 10 + rand() % (15 + 1 - 10);//random 10-15
		setResistance(res);
	}
}



FluVirus::FluVirus(FluVirus& fluViruts)
{
	m_color = fluViruts.getColor();
	setDna(fluViruts.getDna());
	setResistance(fluViruts.getResistance());
}

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
	
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	int r = 0 + rand() % (1 + 1 - 0);// random 0-1
	if (r==0)
	{
		m_color = BLUE;//0 is blue
	}
	else
	{
		m_color = RED;//0 is red
	}
	InitResistance();
}

list<Viruts*> FluVirus::DoClone()
{
	list<Viruts*> listResult;
	FluVirus* fluVirus = new FluVirus(*this);
	listResult.push_back(fluVirus);
	return listResult;
}

void FluVirus::DoDie()
{
	delete this;
}





