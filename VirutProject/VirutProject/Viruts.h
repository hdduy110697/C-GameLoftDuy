#pragma once
class Viruts
{
public:
	Viruts();
	~Viruts();
	// getter setter
	void setDna(char* dna);
	char* getDna();
	void setResistance(int dna);
	int getResistance();

	//Contructor
	Viruts(char* dna, int resistance);
	// copy contructor
	Viruts(Viruts& viruts);
	void LoadADNInformation();//Load DNA information from a ATGX.bin and store it in m_dna.
	void ReduceResistance(int medicine_resistance); // medicine_resistance will reduce the resistance of virus.
private:
	char* m_dna;
	// the virus resistance ability(10 – 30)
	int m_resistance;
	
};

