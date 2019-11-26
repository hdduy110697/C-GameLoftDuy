#include "DengueVirus.h"
#include "FluVirus.h"
#include "Viruts.h"
#include <stdlib.h>
#include<iostream>
#include <list>
#include <string>
#include <cstring>
#include <list>
using namespace std;
#define NS3 1
#define NS5 2
#define E 3
DengueVirus::DengueVirus(const DengueVirus& dengueVirus) : Viruts(dengueVirus)
{

	setProtein(dengueVirus.m_protein);
}
DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();

}
void DengueVirus::setProtein(const char protein[])
{
	int i = 0;
	while (protein[i]!=NULL)
	{
		m_protein[i] = protein[i];
		i++;
	}
}

char* DengueVirus::getProtein()
{
	return this->m_protein;
}

void DengueVirus::InitResistance()
{
	string protein =m_protein;
	if (protein=="NS3")
	{
		int res = 1 + rand() % (10 + 1 - 1);// random 1-10
		setResistance(res);
	}
	if (protein == "NS5")
	{
		int res = 11 + rand() % (20 + 1 - 11);//random 11-20
		setResistance(res);
	}
	if (protein == "E")
	{
		int res = 21 + rand() % (30 + 1 - 21);//random 21-30
		setResistance(res);
	}
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	int r = 1 + rand() % (3 + 1 - 1);// random 1-3
	if (r == NS3)
	{
		string ns3 = "NS3";
		ns3.copy(m_protein, 4);
		
	}
	else if (r== NS5)
	{
		string ns5 = "NS5";
		ns5.copy(m_protein, 4);
	}
	else
	{
		string e = "E";
		e.copy(m_protein, 4);
	}


}

list<Viruts*> DengueVirus::DoClone()
{
	list<Viruts*> listResult;
	DengueVirus* dengueVirus1 = new DengueVirus(*this);
	DengueVirus* dengueVirus2 = new DengueVirus(*this);
	listResult.push_back(dengueVirus1);
	listResult.push_back(dengueVirus2);
	dengueVirus1 = NULL;
	dengueVirus2 = NULL;
	delete dengueVirus1;
	delete dengueVirus2;
	return listResult;
}

void DengueVirus::DoDie()
{
	delete this;
}

DengueVirus::~DengueVirus()
{
	delete[] m_protein;
}
