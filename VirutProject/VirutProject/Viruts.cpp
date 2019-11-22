#include "Viruts.h"
#include <iostream>
#include <fstream>
using namespace std;

Viruts::Viruts()
{
	m_dna = new char[50]{ "" };
	m_resistance = 0; 
}

Viruts ::~Viruts()
{
	delete[] m_dna;
}
Viruts::Viruts(char* dna, int resistance)
{
	m_dna = dna;
	m_resistance = resistance;
}
// getter and setter
void Viruts::setDna(char* dna)
{
	m_dna = dna;
}
char* Viruts::getDna()
{
	return m_dna;
}
void Viruts::setResistance(int dna)
{
	m_resistance = dna;
}
int Viruts::getResistance()
{
	return m_resistance;
}
//copy contructor
Viruts::Viruts(Viruts& viruts) {
	m_dna = viruts.m_dna;
	m_resistance = viruts.m_resistance;
}
void Viruts:: LoadADNInformation()
{
	ifstream inFile;
	inFile.open("ATGX.bin");
	inFile.getline(m_dna, 255);
}
void Viruts::ReduceResistance(int medicine_resistance)
{
	if (m_resistance>=0)
	{
		m_resistance = m_resistance - medicine_resistance;
	}
	else
	{
		m_resistance = 0;
		cout << "Virut die"<<endl;
	}
	

}

