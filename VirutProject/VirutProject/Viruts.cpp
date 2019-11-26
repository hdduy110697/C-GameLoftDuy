#include "Viruts.h"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

Viruts::Viruts()
{
	m_dna = new char[50]{ "" };
	m_resistance = 0; 
}

Viruts ::~Viruts()
{
	delete[] m_dna;
	m_resistance = NULL;
}
Viruts::Viruts(char* dna, int resistance)
{
	m_dna = dna;
	m_resistance = resistance;
}
// getter and setter
void Viruts::setDna(char* dna)
{
	m_dna = new char[100];
	int i = 0;
	while (dna[i] != NULL)
	{
		m_dna[i] = dna[i];
		i++;
	}
}
char* Viruts::getDna()
{
	return m_dna;
}
void Viruts::setResistance(int res)
{
	m_resistance = res;
}
int Viruts::getResistance()
{
	return m_resistance;
}
//copy contructor
Viruts::Viruts(const Viruts& viruts) {
	setDna(viruts.m_dna);
	m_resistance = viruts.m_resistance;
}
void Viruts:: LoadADNInformation()
{
	ifstream inFile;
	inFile.open("ATGX.bin");
	inFile.getline(m_dna, 255);
	inFile.close();
}
void Viruts::ReduceResistance(int medicine_resistance)
{
	if (m_resistance>=0)
	{
		m_resistance = m_resistance - medicine_resistance;
	}
	if(m_resistance<0)
	{
		m_resistance = 0;
		cout << "Virut die"<<endl;
	}
}

