#include <iostream>
#include <fstream>

using namespace std;

struct Turn
{
	int lungime, latime, inaltime;
	char culoare[20];
};

Turn T[100];

void SolutieS2E2()
{
	for(int i=0; i<100; i++)
	{
		if (T[i].lungime == T[i].latime && T[i].lungime == T->inaltime)
			cout << T[i].culoare;
	}
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
		{
			if (i % 3 + j % 3 == 4)
				m[i][j] = 6;
			else
				m[i][j] = i % 3 + j % 3;
		}

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}


//////
///
///  2
///
///


int perechi(int n, int m)
{
	int a, b, r, k = 0;
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			a = i;
			b = j;
			while(b)
			{
				r = a % b;
				a = b;
				b = r;
			}
			if (i * j / a == m)
				k++;
		}
	}

	return k;
}

ifstream fin("Bac12.txt");

int fr[20];

void SolutieS3E3()
{
	int x, fMax=0;
	while(fin>>x)
	{
		fr[x + 9]++;
	}

	for(int i=0; i<=18; i++)
	{
		if (fr[i] > fMax)
			fMax = fr[i];
	}
	for (int i = 0; i <= 18; i++)
		if (fr[i] == fMax)
			cout << i - 9 << " ";
}

