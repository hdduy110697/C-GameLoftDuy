#include <iostream>
#include "Viruts.h"
#include "FluVirus.h"
#include <stdlib.h>
#include <list>
#include <time.h>
#include "DengueVirus.h"
#include <string>
#include <cstring>
#include "patient.h"
#include "vld.h"

using namespace std;

int main() {
	//// random alway
	srand(time(NULL));
	patient p;
	int t = 0;
	while (p.GetState() == 1)
	{
		cout << "Take Medicine(0 = NO, 1 = YES" << endl;
		cin >> t;
		cout << "number virut" << p.GetSizeListViruts() << endl;
			if (t == 1)
		{
			p.TakeMedicine();
		}
		cout << "number virut after" << p.GetSizeListViruts() << endl;
		if ((p.GetSizeListViruts()) == 0)
		{
			cout << "all viruts is dead";
			break;
		}
	}
	return 0;
}