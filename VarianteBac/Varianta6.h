#include <iostream>
#include <fstream>

using namespace std;

struct punct
{
	float x, y;
}A, B;

int SolutieS2E2()
{
	cin >> A.x;
	cin >> A.y;
	cin >> B.x;
	cin >> B.y;

	if (A.x == A.y && B.x == B.y)
		return 1;
	return 0;
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (j == 1)
				m[i][j] = i;
			else
				m[i][j] = m[i][j - 1] + 5;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int divizorM(int n, int a[])
{
	int d = a[0];
	for (int i = 1; i < n; i++)
	{
		int x = d, y = a[i], r;
		while (y)
		{
			r = x % y;
			x = y;
			y = r;
		}
		d = x;
	}
	return d;
}

ifstream fin("Bac6.txt");

int x, p, a;

void SolutieS3E3()
{
	fin >> p;
	while (fin >> x)
	{
		if ((x - p * (p + 1) / 2) % p == 0)
		{
			a = (x - p * (p + 1) / 2) / p;
			cout << a + 1 << " ";
		}
		else
			cout << "NU" << " ";
	}
}
