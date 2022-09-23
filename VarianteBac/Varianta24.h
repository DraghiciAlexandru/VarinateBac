#include <iostream>
#include <fstream>

using namespace std;

void SolutieS2E2()
{
	int v[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 && j < 3)
				v[i][j] = j + 1;
			else if (j == 4)
				v[i][j] = -2;
			else
				v[i][j] = v[i - 1][j] + v[i - 1][j + 1];
		}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

int maxim(int n, int m, int T[30][30])
{
	int x, maxi = 0, impar = 0, par;
	for (int i = 0; i < n && impar == 0; i++)
	{
		if (T[i][0] % 2 == 1)
		{
			impar = 1;
			for (int j = 1; j < m; j++)
				if (T[i][j] % 2 == 0)
				{
					x = T[i][j];
					par = 1;
					while (x && par)
					{
						if (x % 10 % 2 == 1)
							par = 0;
						x /= 10;
					}
					if (par == 1 && T[i][j] > maxi)
						maxi = T[i][j];
				}
		}
	}
	if (impar == 0)
		return -1;
	return maxi;
}

ifstream fin("Bac24.txt");

void SolutieS3E3()
{
	int x, lgmax = 0, nrmax_secv = 0, pc, lg;
	fin >> x;
	pc = x / 100;
	lg = 1;

	while(fin>>x)
	{
		if(x/100==pc)
		{
			lg++;
		}
		else
		{
			if (lg > lgmax)
			{
				lgmax = lg;
				nrmax_secv = 1;
			}
			else if (lg == lgmax)
				nrmax_secv++;
			pc = x / 100;
			lg = 1;
		}
	}
	if (lg > lgmax)
	{
		lgmax = lg;
		nrmax_secv = 1;
	}
	else if (lg == lgmax)
		nrmax_secv++;
	cout << lgmax << " " << nrmax_secv;
}
