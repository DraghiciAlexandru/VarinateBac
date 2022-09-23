#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int n, v[51], k;

void SolutieS3E2()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		if (v[i] != -1)
		{
			cout << v[i] << " ";
			k = 1;
			for (int j = i + 1; j <= n; j++)
				if (v[i] == v[j])
				{
					k++;
					v[j] = -1;
				}
			cout << k << endl;
			v[i] = -1;
		}
	}
}

int fa[100], fb[100], x, nrs, m;

ifstream fin("Bac27.txt");

void SolutieS3E3()
{
	fin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		fin >> x;
		fa[x]++;
	}

	for(int i=1; i<=m; i++)
	{
		fin >> x;
		fb[x]++;
	}
	nrs = 0;
	for(int i=0; i<=99; i++)
	{
		if (fb[i] != 0)
			if (nrs == 0 || fa[i] / fb[i] < nrs)
				nrs = fa[i] / fb[i];
	}
	cout << nrs;
}

