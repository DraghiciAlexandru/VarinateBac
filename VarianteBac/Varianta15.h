#include <iostream>
#include <fstream>

using namespace std;

struct rezBac
{
	int mat, rom, inf;
	char rez;
}candidat;

void SolutieS2E1()
{
	if (candidat.rom >= 5 && candidat.mat >= 5 && candidat.inf >= 5)
		if ((candidat.mat + candidat.rom + candidat.inf) / 3 >= 6)
			candidat.rez = 'A';
		else
			candidat.rez = 'R';
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (i < j)
				m[i][j] = i;
			else
				m[i][j] = j;
			m[7 - i][j] = m[i][7 - j] = m[7 - j][7 - i] = m[i][j];
		}

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void compact(int& n, int v[])
{
	int i = 1;
	while (i < n)
	{
		if (v[i] == v[i + 1])
		{
			for (int j = i + 2; j <= n; j++)
				v[j - 1] = v[j];
			n--;
		}
		else
			i++;
	}
}



