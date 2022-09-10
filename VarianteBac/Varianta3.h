#include <iostream>
#include <fstream>

using namespace std;

struct Data
{
	int zi, luna, an;
};

struct Elev
{
	char nume[21];
	Data dn;
}E1, E2;

void CitireS2E2()
{
	cout << "Nume1:";
	cin >> E1.nume;
	cout << "Zi1:";
	cin >> E1.dn.zi;
	cout << "Luna1:";
	cin >> E1.dn.luna;
	cout << "An1:";
	cin >> E1.dn.an;
	cout << "Nume2:";
	cin >> E2.nume;
	cout << "Zi2:";
	cin >> E2.dn.zi;
	cout << "Luna2:";
	cin >> E2.dn.luna;
	cout << "An2:";
	cin >> E2.dn.an;
}

void MaiMare()
{
	CitireS2E2();
	
	if (E1.dn.luna < E2.dn.luna)
		cout << E1.nume;
	else if (E1.dn.luna > E2.dn.luna)
		cout << E2.nume;
	else
	{
		if (E1.dn.zi < E2.dn.zi)
			cout << E1.nume;
		else 
			cout << E2.nume;
	}
}

void SolutieS3E1()
{
	int m[50][50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = 0; j < n; j++)
			m[i][j] = m[i + 1][j];
	for (int i = 0; i < n; i++)
		for (int j = n / 2; j < n; j++)
			m[i][j] = m[i][j + 1];

	n--;
	
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int frcV[10];

void numar(int n, int& m)
{
	int flag = 0;
	m = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			frcV[n % 10]++;
			flag = 1;
		}
		n = n / 10;
	}
	
	if (flag == 0)
	{
		m = -1;
	}
	else
	{
		for (int i = 9; i > 0; i--)
		{
			if(frcV[i]>0)
			{
				m = m * 10 + i;
				frcV[i]--;
				i++;
			}
		}
	}

	cout << m;
}

ofstream fout("Bac3.txt");

int cmmdc(int x, int y)
{
	while (x != y)
	{
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	return  x;
}

int nrCifre(int x)
{
	int ct = 0;
	while(x)
	{
		ct++;
		x = x / 10;
	}
	return ct;
}

void SolutieS3E3()
{
	int n, m, k;
	cout << "n:";
	cin >> n;
	cout << "M:";
	cin >> m;
	cout << "K:";
	cin >> k;

	int cmmmc = (n * m) / cmmdc(n, m);
	int aux = cmmmc;
	
	while(nrCifre(cmmmc)<k)
	{
		cmmmc += aux;
	}

	while(nrCifre(cmmmc)==k)
	{
		fout << cmmmc << " ";
		cmmmc += aux;
	}
}
