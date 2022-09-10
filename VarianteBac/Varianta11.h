#include <iostream>
#include <fstream>

using namespace std;

struct Fisier
{
	char nume[30], extensie[5];
	int dimensiune;
};

struct Dosar
{
	Fisier F[100];
	int nrFisiere;
}D;

int sum;

void SolutieS2E1()
{
	for (int i = 0; i < D.nrFisiere; i++)
		sum += D.F[i].dimensiune;
}

int a[50][50], v[50], n;

int sumColoana(int nr)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i][nr];
	return s;
}

int sumLinie(int nr)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[nr][i];
	return s;
}

void SolutieS3E1()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		v[i] = sumColoana(i);
	
	for(int i=0; i<n; i++)
	{
		if(sumLinie(i)==0)
		{
			for (int j = 0; j < n; j++)
				a[i][j] = v[j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void nrPrime(int n, int& k, int p[])
{
	int a, b, r;
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
}

//////
///
///    3
///



