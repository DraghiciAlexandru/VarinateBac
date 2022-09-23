#include <iostream>
#include <fstream>

using namespace std;

struct oras
{
	char tara[30], nume_oras[20];
	int nr_locuitori_oras;
	float suprafata_oras;
}o[200];

void SolutieS2E1()
{
	for(int i=0; i<200; i++)
	{
		if (o[i].nr_locuitori_oras / o[i].suprafata_oras > 15)
		{
			cout << o[i].nume_oras << " " << o[i].tara << endl;
		}
	}
}

void SolutieS2E2()
{
	int x, y, a, b, k, t;
	cin >> a >> b >> k;
	for (x = a; x <= b; x++)
	{
		y = 0;
		t = x;
		while (t != 0)
		{
			y = y * 10 + t % 10;
			t = t / 10;
		}
		if (y % k == 0)
			cout << x << " ";
	}
}

void SolutieS3E1()
{
	int n, A[50][50], nmax = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	for(int i=0; i<n; i++)
	{
		if (A[i][i] > nmax)
			nmax = A[i][i];
		if (A[i][n - i - 1] > nmax)
			nmax = A[i][n - i - 1];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] % 2 == 0 && A[i][j] < 1000)
				A[i][j] = nmax;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void cifre(int& n, int& k)
{
	int nr = 0, p1 = 1, p2 = 1, cif, cn, f[10] = { 0 };
	k = 0;
	cn = n;
	while (cn != 0)
	{
		cif = cn % 10;
		if (cif % 2 == 0 && f[cif] == 0)
		{
			k += cif * p2;
			p2 *= 10;
			f[cif] = 1;
		}
		if (cif % 2 == 1)
		{
			nr += cif * p1;
			p1 *= 10;
		}
		cn /= 10;
	}
	if (nr == n)
		k = -1;
	else
		n = nr;
}

