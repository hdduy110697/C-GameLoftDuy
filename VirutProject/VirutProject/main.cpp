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

using namespace std;
int main() {
	//// random alway
	srand(time(NULL));
	patient* p = new patient();
	int t = 0;
	while (p->GetState() == 1)
	{
		cout << "Take Medicine(0 = NO, 1 = YES" << endl;
		cin >> t;
		if (t == 1)
		{
			p->TakeMedicine();
		}
	}
	return 0;
}