#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void SolutieS3E2()
{
	int n, v[101], w[101], k;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	w[1] = v[1];
	k = 1;
	for(int i=2; i<=n; i++)
	{
		if (v[i] != v[i - 1])
		{
			k++;
			w[k] = v[i];
		}
	}
	n = k;
	for (int i = 1; i <= k; i++)
		v[i] = w[i];
	for (int i = 1; i <= k; i++)
		cout << v[i] << " ";
}

ifstream fin("Bac28.txt");

int x, vf[200], vfmax;

void SolutieS3E3()
{
	while (fin >> x)
	{
		vf[x + 99]++;
	}
	for (int i = -99; i <= 99; i++)
	{
		if (vf[i + 99] > vfmax)
			vfmax = vf[i + 99];
	}
	for (int i = -99; i <= 99; i++)
	{
		if (vf[i + 99] == vfmax)
			cout << i << " ";
	}
}

