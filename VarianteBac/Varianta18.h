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
	int v[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i == 0)
			{
				v[i][j] = 2;
			}
			else if (j == 0)
			{
				v[i][j] = 2;
			}
			else
				v[i][j] = v[i][j - 1] + v[i - 1][j];
		}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}


int perechi(int n, int v[])
{
	int nr = 0, ogl, c;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			c = v[j];
			ogl = 0;
			while (c)
			{
				ogl = ogl * 10 + c % 10;
				c = c / 10;
			}
			if (v[i] == ogl)
				nr++;
		}
	}
	return nr;
}

ifstream fin("Bac18.txt");

int f[10];

void SolutieS3E3()
{
	int n, c, nrCif = 0, s = 0;
	while(fin>>n)
	{
		while(n)
		{
			f[n % 10]++;
			n = n / 10;
		}
	}

	for(int i=9; i>=2; i--)
	{
		if(f[i]!=0&&f[i-2]!=0)
		{
			s = f[i] + f[i - 2];
			if(s>nrCif)
			{
				nrCif = s;
				c = i;
			}
		}
	}
	if (s == 0)
		cout << "Nu exista";
	else
	{
		for (int i = 0; i < f[c]; i++)
			cout << c;
		for (int i = 0; i < f[c-2]; i++)
			cout << c-2;
	}
}