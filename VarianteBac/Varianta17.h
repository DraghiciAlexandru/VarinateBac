#include <iostream>
#include <fstream>

using namespace std;

struct Data
{
	int zi, luna, an;
};

struct produs
{
	char denumire[41];
	Data dexp;
};

produs P; Data azi;

void SolutieS2E1()
{
	if ((P.dexp.an > azi.an) || (P.dexp.an == azi.an && P.dexp.luna > azi.luna)
		|| (P.dexp.an == azi.an && P.dexp.luna == azi.luna && P.dexp.zi > azi.zi))
		cout << "produsul nu este expirat";
	else
		cout << "produsul este expirat";
}

void SolutieS2E2()
{
	char v[5][5];

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
		{
			if (i == j)
				v[i][j] = 'A';
			else if (j == 0)
				v[i][j] = v[i - 1][4];
			else if (i < j || i>j)
				v[i][j] = v[i][j - 1] + 1;
		}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}


int termen(int n)
{
	int i = 1, j = 1, k = 2;

	while(i<=n)
	{
		j = 1;
		while (j <= k)
		{
			if (i == n)
				return j;
			j++;
			i++;
			cout << i << " " << j << endl;
		}
		while(j>1)
		{
			if (i == n)
				return j;
			j--;
			i++;
			cout << i << " " << j << endl;
		}
		k += 3;
	}
}

ifstream fin("Bac17.txt");

int first[10], last[10], lungime[10];

void SolutieS3E3()
{
	int n, ordine = 0;

	while(fin>>n)
	{
		ordine++;
		if(first[n%10]==0)
		{
			first[n % 10] = last[n % 10] = ordine;
			lungime[n % 10] = 1;
		}
		else
		{
			last[n % 10] = ordine;
		}
	}

	int lmax = 0, poz = 0;
	
	for(int i=0; i<10; i++)
	{
		if(first[i]!=0)
		{
			lungime[i] = last[i] - first[i] + 1;
			if (lungime[i] >= lmax)
			{
				lmax = lungime[i];
				if (poz < first[i])
					poz = i;
			}
		}
	}

	if (lmax == 1)
		cout << "Nu exista";
	else
		cout << lmax << " " << first[poz];
	
}


