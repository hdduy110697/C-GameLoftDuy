#include <iostream>
#include "Viruts.h"
#include "FluVirus.h"
#include <stdlib.h>
#include <list>
#include <time.h>

using namespace std;
int main() {
	// random alway
	srand(time(NULL));
	Viruts* viruts = new FluVirus();
	viruts->DoBorn();
	viruts->InitResistance();
	cout << "hi�dasdasd  :";
	return 0;
}