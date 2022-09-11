#include <iostream>
#include <fstream>

using namespace std;

struct fractie
{
	int numitor, numarator;
};

fractie x[20];

void SolutieS2E1()
{
	int nMin = x[0].numitor, ct = 0;
	for(int i=1 ;i<20; i++)
	{
		if(nMin>x[i].numitor)
		{
			nMin = x[i].numitor;
			ct = 1;
		}
		else if (nMin == x[i].numitor)
		{
			ct++;
		}
	}

	cout << ct;
}


void SolutieS2E2()
{
	int m[5][5];

	for(int i=0; i<)
}

