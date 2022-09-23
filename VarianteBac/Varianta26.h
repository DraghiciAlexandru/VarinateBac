#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void SolutieS3E2()
{
	int n, v[101], k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (k = 1; k <= n; k++)
	{
		int i = 1, j = n - k - 1;
		while (i <= k)
		{
			cout << v[i] << " ";
			i++;
		}
		while (j <= n)
		{
			cout << v[j] << " ";
			j++;
		}
		cout << endl;
	}
}

int x, nrp, nrpmax, prim;

ifstream fin("Bac26.txt");

void SolutieS3E3()
{
	while(fin>>x)
	{
		nrp = 0;
		do
		{
			prim = 1;
			for (int i = 2; i <= sqrt(x); i++)
				if (x % i == 0)
					prim = 0;
			if(prim==0)
			{
				nrp++;
				x++;
			}
		} while (prim == 0);
		if (nrp + 1 > nrpmax)
			nrpmax = nrp + 1;
	}
	cout << nrpmax;
}
