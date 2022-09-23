#include <iostream>
#include <fstream>

using namespace std;

void SolutieS2E2()
{
	int v[5][5];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				v[i][j] = 1;
			else if (i + j == 3)
				v[i][j] = 7;
			else
				v[i][j] = j + 1;
		}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

int produs(int n, int x[])
{
	int prodmax = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; i < n; j++)
			if (x[i] * x[j] > prodmax)
				prodmax = x[i] * x[j];
	return prodmax;
}

ifstream fin("Bac20.txt");

int f[1000];

void SolutieS3E3()
{
	int x, uc, p, nr;
	while (fin >> x)
	{
		p = 1;
		nr = 0;
		uc = x % 10;
		x = x / 10;
		while (x > 9)
		{
			nr = nr + (x % 10) * p;
			p *= 10;
			x /= 10;
		}

		if (uc == x)
			f[nr]++;
	}
	p = 0;
	for (int x = 999; x >= 0; x--)
		if (f[x] != 0)
		{
			cout << x << " ";
			p = 1;
		}
	if (p == 0)
		cout << "Nu exista";
}

