#include <iostream>
#include <fstream>

using namespace std;

struct Companie
{
	char titlu[31];
	struct { int luna, an; }start;
	int durata, procent;
}C[51];


void SolutieS3E1()
{
	char v[10][10];
	int n, c[10], l[10], dp = 0, ds = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] = 'X')
			{
				if (i == j)
					dp++;
				if (i + j == n - 1)
					ds++;

				l[i]++;
				c[j]++;
			}
		}
	}


	if (dp == n || ds == n)
		cout << "DA";
	else
	{
		int x = 0;
		for(int i=0; i<n;i++)
			if(l[i]==n||c[i]==n)
			{
				cout << "DA";
				x = 1;
				break;
			}
		if (x == 0)
			cout << "NU";
	}
	
}

void nMax(int &n, int c)
{
	int aux = n, p = 1;

	while(n>9)
	{
		n = n / 10;
		p = p * 10;
	}
	n = 0;

	int flag = 0;
	while(p)
	{
		int cif = (aux / p) % 10;
		p = p / 10;
		if(c>cif && flag==0)
		{
			n = n * 10 + c;
			flag = 1;
		}
		n = n * 10 + cif;
	}
	if (flag == 0)
		n = n * 10 + c;
}

ifstream fin("Bac16.txt");

void intervalAsociat()
{
	int x, y, s, d = 0, maxS = 0, minD = 100;

	fin >> x;
	s = x;
	
	while (fin >> y)
	{
		if (y == x + 1)
			d = y;
		else
		{
			if (maxS < s)
				maxS = s;
			if (minD > d)
				minD = d;
			s = y;
		}
		x = y;
	}
	if (minD > d)
		minD = d;
	
	if (minD >= maxS)
		cout << maxS << " " << minD;
	else
		cout << "Multimea vida";
	
}



