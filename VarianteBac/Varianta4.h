#include <iostream>
#include <fstream>

using namespace std;

struct complex
{
	int pre;
	int pim;
};

complex z;

void SolutieS2E2()
{
	cin >> z.pre >> z.pim;
	cout << sqrt(z.pre * z.pre + z.pim * z.pim);
}

void SolutieS2E3()
{
	int m[50][50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == 0 || j == 0)
				m[i][j] = 1;
			else
				m[i][j] = (m[i][j - 1] + m[i - 1][j]) % 10;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void SolutieS3E2(int n, int m)
{
	int ct = 0;
	for (int i = n; i <= m; i++)
	{
		int aux = i;
		while (aux)
		{
			ct++;
			aux = aux / 10;
		}
	}
	cout << ct;
}

ifstream fin("Bac4.txt");

int vf[200];

void SolutieS3E3()
{
	int n;

	for (int i = -99; i < 100; i++)
		vf[i] = 0;
	
	while (fin >> n)
	{
		vf[n]++;
	}

	int m = 0;

	for (int i = -99; i < 100; i++)
		if (vf[i] > m)
			m = vf[i];

	for (int i = -99; i < 100; i++)
		if (vf[i] == m)
			cout << i << " ";
}