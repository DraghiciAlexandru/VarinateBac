#include <iostream>
#include <fstream>

using namespace std;

void SolutieS3E1()
{
	float s = 0;
	int n, A[40][40], mini, ordonat, nr = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	for(int j=0; j<n; j++)
	{
		ordonat = 1;
		mini = A[0][j];
		for(int i=1; i<n && ordonat==1; i++)
		{
			if (A[i - 1][j] > A[i][j])
				ordonat = 0;
			if (A[i][j] < mini)
				mini = A[i][j];
		}
		if(ordonat==1)
		{
			s += mini;
			nr++;
		}
	}
}

void termeni(int n, int& m, int& t)
{
	int s;
	m = 1;
	t = 1;
	while(t<n)
	{
		s = m + t;
		m = t;
		t = s;
	}

	if (t == n)
		t = m + t;
}

ifstream fin("Bac21.txt");

int f[1000];

void SolutieS3E3()
{
	int x, y, z, n, ex = 0;
	fin >> n >> x >> y;
	for(int i=3; i<=n; i++)
	{
		fin >> z;
		if(x<y&&y>z)
		{
			ex = 1;
			f[y]++;
		}
		x = y;
		y = z;
	}
	if (ex == 0)
		cout << "Nu exista";
	else
		for (int i = 1; i < 1000; i++)
			if (f[i] > 0)
				cout << i << " ";
}
