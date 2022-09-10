#include <iostream>
#include <fstream>

using namespace std;

struct Jucator
{
	int nrTricou, marimeTricou;
};

struct Echipa
{
	int nrJucatori;
	Jucator juc[20];
}E;

void SolutieS2E2()
{
	cin >> E.nrJucatori;
	for (int i = 0; i < E.nrJucatori; i++)
	{
		cin >> E.juc[i].nrTricou >> E.juc[i].marimeTricou;
	}
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 2; j++)
		{
			if(i<3)
			{
				m[i][j] = (i + j) % 6;
				m[i][5 - j] = (i + j) % 6;
			}
			else
			{
				m[i][j] = m[5 - i][j];
				m[i][5 - j] = m[5 - i][j];
			}
		}


	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void divprim(int n, int v[100], int& k)
{
	int d = 2;
	for(int i=2; i*i<=n; i++)
	{
		if (n % i == 0)
		{
			d = i;
			break;
		}
	}

	int f = 0;
	while (d > v[f] && f < k)
	{
		f++;
	}

	cout << f << endl;
	
	for (int i = k; i > f; i--)
	{
		v[f] = v[f - 1];
	}

	k++;
	v[f] = d;

	for (int i = 0; i < k; i++)
		cout << v[i] << " ";
}


/////////////////??????????
///

ifstream fin("Bac10.txt");

int x, fr[32], p, k, fMax;

void SolutieS3E3()
{
	while(fin>>x)
	{
		p = 1;
		k = 0;
		while(p*2<=x)
		{
			p *= 2;
			k++;
		}
		fr[k]++;
	}

	for (int i = 0; i < 32; i++)
	{
		if(fr[i]>=fMax)
		{
			fMax = fr[i];
			k = i;
		}
	}

	cout << k;
}

