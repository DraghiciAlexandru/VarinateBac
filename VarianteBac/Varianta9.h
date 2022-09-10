#include <iostream>
#include <fstream>

using namespace std;

struct produs
{
	int cod;
	float cant, pret;
};

struct magazin
{
	produs P[100];
	int nrProduse;
}M;


void SolutieS2E2()
{
	for(int i=0; i<M.nrProduse;i++)
	{
		if (M.P[i].cant == 0)
			cout << M.P[i].cod << endl;
		else
			cout << M.P[i].cant * M.P[i].pret;
	}
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 0; i <= n; i++)
		for (int j = 5; j >= 0; j--)
		{
			if (i == j)
				m[i][j] = 6;
			else
				if (i % 2 == 0)
					m[i][j] = 5 - i;
				else
					m[i][j] = 5 - j;
		}


	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int circular(int a, int b)
{
	int nrCif = 0, c = 1, aux = a;
	while (aux > 9)
	{
		aux = aux / 10;
		c = c * 10;
		nrCif++;
	}

	for (int i = 0; i < nrCif; i++)
	{
		if (a == b)
			return i;
		a = (a % 10) * c + a / 10;
	}

	return -1;
}

/////
///
///
///
///  Exercitiul 3
///  
///
///
///
