#include <iostream>
#include <fstream>

using namespace std;

struct punct
{
	int x;
	int y;
};

struct poligon
{
	int nr_vf;
	punct vf[20];
}p;

void citireS2E2()
{
	cout << "Nr varfuri:";
	cin >> p.nr_vf;
	for(int i=0; i<p.nr_vf; i++)
	{
		cout << "Varf " << i << " x:";
		cin >> p.vf[i].x;
		cout << "Varf " << i << " y:";
		cin >> p.vf[i].y;
	}
}

void SolutieS2E3()
{
	int m[6][6];
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
		{
			if (i + j < 6)
				m[i][j] = 1;
			else if (i + j > 6)
				m[i][j] = 2;
			else
				m[i][j] = 3;
		}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}


int nrDiv(int nr)
{
	int x = 1;
	for (int i = 2; i <= nr; i++)
		if (nr % i == 0)
			x++;
	return x;
}

void SolutieS3E2(int a, int b)
{
	int nr = 0;
	for (int i = a; i <= b; i++)
		if (nrDiv(i) == 3)
			nr++;
	cout << nr;
}

ifstream fin("Bac2.txt");

int frA[100], frB[100];

void SolutieS3E3()
{
	int a, b, x, y;

	fin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		fin >> x;
		frA[x]++;
	}
	for (int i = 0; i < b; i++)
	{
		fin >> y;
		frB[y]++;
	}
	
	int comun = INT_MAX;

	for(int i=0; i<100; i++)
	{
		if (frA[i] != 0 && frB[i] != 0)
		{
			if (frA[i] / frB[i] < comun)
				comun = frA[i] / frB[i];
		}
	}

	cout << comun;
}

