#include <iostream>
#include <fstream>

using namespace std;

struct punct
{
	float x, y;
};

struct poligon
{
	int nr;
	punct v[101];
}p;

float per;

void SolutieS2E2()
{
	cin >> p.nr;
	int n = p.nr;
	for(int i=0; i<p.nr; i++)
	{
		cin >> p.v[i].x;
		cin >> p.v[i].y;
	}

	per = sqrt((p.v[n].x - p.v[0].x) * (p.v[n].x - p.v[0].x) + (p.v[n].y - p.v[0].y) * (p.v[n].y - p.v[0].y));

	for(int i=1; i<n; i++)
	{
		per += sqrt((p.v[i].x - p.v[i - 1].x) * (p.v[i].x - p.v[i - 1].x) + (p.v[i].y - p.v[i - 1].y) * (p.v[i].y - p.v[i - 1].y));
	}

	cout << per;
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 6;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			if (i == j || i + j == 6)
			{
				m[i][j] = 0;
			}
			else 
			{
				if (i + j < 6)
				{
					if (i > j)
						m[i][j] = 4;
					else
						m[i][j] = 1;
				}
				else
				{
					if (i > j)
						m[i][j] = 3;
					else
						m[i][j] = 2;
				}
			}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int divizori(int n)
{
	int s = 0, d = 2;
	while (n != 1)
	{
		if (n % d == 0)
		{
			while (n % d == 0)
				n = n / d;
			s = s + d;
		}
		d++;
	}
	return s;
}

ifstream fin("Bac5.txt");

int prim(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void SolutieS3E3()
{
	int x, m = 0;
	while(fin>>x)
	{
		int ct = 0;
		while(prim(x)==0)
		{
			ct++;
			x++;
		}
		if (ct + 1 > m)
			m = ct + 1;
	}
	cout << m;
}
