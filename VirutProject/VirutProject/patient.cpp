#include "patient.h"
#include <iostream>
#include <fstream>
#include "Viruts.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <list>
// state virus
#define DIE 0 
#define  ALIVE 1 
// type virus
#define FlUVIRUS 1
#define DENGUEVIRUS 2
using namespace std;
void patient::InitResistance()
{
	int res = 1000 + rand() % (9000 + 1 - 1000);// random 1000-9000
	m_resistance = res;
}

void patient::DoStart()
{
	int numVirus=  10 + rand() % (20 + 1 - 10);// random 10-20;
	int typeVirus;
	for (int i = 0; i < numVirus; i++)
	{
		typeVirus= 1+ rand() % (2 + 1 - 1);//random 1-2
		if (typeVirus==FlUVIRUS)
		{
			Viruts* fluVirus = new FluVirus();
			fluVirus->DoBorn();
			m_virusList.push_back(fluVirus);
		}
		if (typeVirus == DENGUEVIRUS)
		{
			Viruts* dengueVirus = new DengueVirus();
			dengueVirus->DoBorn();
			m_virusList.push_back(dengueVirus);
		}
	}
}

void patient::TakeMedicine()
{
	list<Viruts*>::iterator itLocation;
	list<Viruts*>::iterator it;
	for (it = m_virusList.begin(); it != m_virusList.end(); it++) {
		int medicine_resistance=  1 + rand() % (60 + 1 - 1);//random 1-60
		(*it)->ReduceResistance(medicine_resistance);
		if (((*it)->getResistance())==0)
		{

			m_virusList.remove((*it));
			it = m_virusList.begin();

		}
		else
		{
			list<Viruts*> listClone;
			listClone =(*it)->DoClone();
			itLocation = m_virusList.end();
			m_virusList.splice(itLocation, listClone);
		}
 	}
}

void patient::DoDie()
{
	
	m_virusList.clear();
	m_state = DIE;
}

int patient::GetState()
{
	return m_state;
}

void patient::DeadTotalVirusResistance()
{
	int totalVirusResistance=0;
	list<Viruts*>::iterator it;
	for (it = m_virusList.begin(); it != m_virusList.end(); it++) {
		totalVirusResistance += (*it)->getResistance();
	}
	if (m_resistance < totalVirusResistance)
	{
		DoDie();
	}
}

patient::patient()
{
	InitResistance();
	DoStart();
	m_state = ALIVE;
}

patient::~patient()
{
}
