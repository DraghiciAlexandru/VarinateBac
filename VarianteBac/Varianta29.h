#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int mat[200], lrom[200], inf[200];

void SolutieS2E2()
{
	int nr = 0;
	float media;
	for (int i = 0; i < 200; i++)
	{
		if (mat[i] >= 5 && lrom[i] >= 5 && inf[i] >= 5)
		{
			media = (mat[i] + lrom[i] + inf[i]) / 3.0;
			if (media >= 7)
				nr++;
		}
	}
	cout << nr;
}

void SolutieS2E3()
{
	char v[7][7];

	for (int i = 0; i <= 6; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (j == 0 || j == 6)
				cout << "* ";
			else
				if ((i <= 3) && (j + i == 6 || i == j))
					cout << "* ";
				else
					cout << "- ";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

void SolutieS3E2()
{
	int n, k, p[1000], a, b, r;
	for(int i=1; i<n; i++)
	{
		a = i;
		b = n;
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		if(a==1)
		{
			k++;
			p[k] = i;
		}
	}
	cout << k << endl;
	for (int i = 1; i <= k; i++)
		cout << p[i] << " ";
}

ifstream fin("Bac29.txt");

int x, k, fr[100], s;

void SolutieS3E3()
{
	fin >> k;
	while (fin >> x)
	{
		fr[x]++;
	}

	for (int i = 99; i >= 0; i--)
	{
		s += fr[i];
		if (s >= k)
		{
			cout << i;
			break;
		}
	}
	cout << -1;
}
