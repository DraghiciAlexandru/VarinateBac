#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void SolutieS3E2()
{
	int n, v[1000];
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> v[i];
	}

	for(int i=1; i<n;)
	{
		if (v[i] == v[i + 1])
		{
			for (int j = i + 2; j <= n; j++)
				v[j - 1] = v[j];
			n--;
		}
		else
			i++;
	}
	cout << n;
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";
}

ifstream fin("Bac30.txt");

int x, y, a, b, maxa, minb, ok;

void SolutieS3E3()
{
	fin >> x;
	a = x;
	ok = 0;
	while(fin>>y)
	{
		if (y == x + 1)
			b = y;
		else
		{
			if(ok==0)
			{
				maxa = a;
				minb = b;
				ok = 1;
			}
			else
			{
				if (maxa < a)
					maxa = a;
				if (minb > b)
					minb = b;
			}
			a = y;
		}
		x = y;
	}
	if(ok==0)
	{
		maxa = a;
		minb = b;
		ok = 1;
	}
	else
	{
		if (maxa < a)
			maxa = a;
		if (minb > b)
			minb = b;
	}
	if (minb >= maxa)
		cout << maxa << " " << minb;
	else
		cout << "multimea vida";
}