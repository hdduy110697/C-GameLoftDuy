#include <iostream>
#include "Viruts.h"
#include "FluVirus.h"
#include <stdlib.h>
#include <list>
#include <time.h>
#include "DengueVirus.h"
#include <string>
#include <cstring>

using namespace std;
int main() {
	// random alway
	srand(time(NULL));
	Viruts* viruts = new DengueVirus();
	viruts->DoBorn();
	viruts->InitResistance();
	cout << "hiádasdasd  :";
	return 0;
}