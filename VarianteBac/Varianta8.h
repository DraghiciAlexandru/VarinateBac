#include <iostream>
#include <fstream>

using namespace std;

struct triunghi
{
	float a, b, c;
}t;

int SolutieS2E2()
{
	cin >> t.a >> t.b >> t.c;
	if (t.a == t.b && t.a != t.c || t.a == t.c && t.a != t.b || t.c == t.b && t.a != t.c)
		return 1;
	return 0;
}

void SolutieS3E1()
{
	int a[11][11], n, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < n; j++)
			k = k * 2 + a[i][j];
		cout << k << " ";
	}
}

int patrat(int n)
{
	int d = 2, p = 1, k, aux = n;
	while (d * d <= n)
	{
		if (n % d == 0)
		{
			k = 0;
			while (n % d == 0)
			{
				k++;
				n = n / d;
			}
			if (k % 2)
				p *= d;
		}
		d++;
	}

	if (n > 1)
		p *= n;
	return aux / p;
}

ifstream fin("Bac8.txt");

void SoluiteS3E3()
{
	int n, nrz = 0, mZero = 0, nrMax = 0;

	while (fin >> n)
	{
		nrz = 0;
		while (n)
		{
			nrz += n / 5;
			n = n / 5;
		}
		if (nrz > mZero)
		{
			mZero = nrz;
			nrMax = 1;
		}
		else
			if (nrz == mZero)
				nrMax++;
	}

	cout << mZero << " " << nrMax;
}
