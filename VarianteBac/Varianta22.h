#include <iostream>
#include <fstream>

using namespace std;

void SolutieS2E2()
{
	char v[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				v[i][j] = 'a';
			else if (j < i)
				v[i][j] = v[i - 1][j] + 1;
			else
				v[i][j] = v[i][j - 1] + 1;
		}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

int prime(int n, int a[])
{
	int nr_perechi = 0, x, y, rest;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			x = a[i];
			y = a[i];
			do
			{
				rest = x % y;
				x = y;
				y = rest;
			} while (rest != 0);
			if (x == 1)
				nr_perechi++;
		}
	}
	return nr_perechi;
}

ifstream fin("Bac22.txt");

void SolutieS3E3()
{
	int n, min1, min2, x;
	fin >> n;
	min1 = min2 = 1000;
	for (int i = 1; i <= n; i++)
	{
		fin >> x;
		if (x < min1)
		{
			min2 = min1;
			min1 = x;
		}
		else
			if (x<min2 && x>min1)
				min2 = x;
		if (i % 7 == 0)
		{
			if (min1 != 1000 && min2 != 1000 && min1 != min2)
				cout << min1 << " " << min2 << " ";
			else
				cout << 0 << " ";
			min1 = min2 = 100;
		}
	}
}
