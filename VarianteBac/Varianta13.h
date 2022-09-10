#include <iostream>
#include <fstream>

using namespace std;

struct Punct
{
	float x, y;
};

struct Cerc
{
	Punct centru;
	int raza;
}C;

bool peAxa()
{
	if (C.centru.y == 0 && abs(C.centru.x) <= C.raza)
		return true;
	return false;
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 5; i >= 1; i--)
		for (int j = 1; j < 6; j++)
		{
			if (i == 5 || j == 1)
				m[i][j] = 5;
			else
				m[i][j] = m[i - 1][j + 1] % 2 + m[i][j - 1] % 2;
		}

	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int rotund(int n)
{
	if (n % 2)
		return 0;
	int a = n % 2, b;
	n = n / 2;
	while(n)
	{
		b = n % 2;
		n = n / 2;
		if (a == b)
			return 0;
		a = b;
	}
	return 1;
}

ifstream fin("Bac13.txt");

void SolutieS3E3()
{
	int x, y, c = 1, aux, nr = -1;
	fin >> x;
	aux = x;
	while(aux)
	{
		c = c * 10;
		aux = aux / 10;
	}

	while (fin >> y)
		if (y % c == x)
			nr = y;
	if (nr != -1)
		cout << nr;
	else
		cout << "NU EXISTA";
}
