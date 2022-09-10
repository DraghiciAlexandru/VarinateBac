#include <iostream>
#include <fstream>

using namespace std;

struct Produs
{
	int cod;
	struct { int luna, an; }data_expirarii;
	float pret_furnizor[5];
}P[100];

void SolutieS2E3()
{
	char m[50][50];
	int n = 5;
	for (int i = 0; i <=6; i++)
		for (int j = 0; j <= 6; j++)
		{
			if (j == 0 || j == 6)
				m[i][j] = '*';
			else
				if (i <= 3 && (j + i == 6 || i == j))
					m[i][j] = '*';
				else
					m[i][j] = '-';
		}

	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

//////
///
///1
///
///
///


int regulat(int n)
{
	int aux;
	for (int i = n - 1; i > 0; i--)
	{
		aux = i;
		while (aux % 2 == 0)
		{
			aux = aux / 2;
		}
		while (aux % 3 == 0)
		{
			aux = aux / 3;
		}
		while (aux % 5 == 0)
		{
			aux = aux / 5;
		}
		if (aux == 1)
			return i;
	}
	return 0;
}

ifstream fin("Bac14.txt");

int x, k, fr[100];

void SolutieS3E3()
{
	fin >> k;
	while(fin>>x)
	{
		fr[x]++;
	}

	int s = 0;
	for(int i=99; i>=0; i--)
	{
		s += fr[i];
		if(s>=k)
		{
			cout << i;
			break;
		}
	}
}

