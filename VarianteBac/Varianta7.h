#include <iostream>
#include <fstream>

using namespace std;

struct punct
{
	float x, y;
}A, B;

int SolutieS2E2()
{
	cin >> A.x;
	cin >> A.y;
	cin >> B.x;
	cin >> B.y;

	if (A.x == 0 && B.x == 0 || A.y == 0 && B.y == 0)
		return 1;
	return 0;
}

void SolutieS2E3()
{
	int m[50][50];
	int n = 5;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i % 2 == 1)
				m[i][j] = (i - 1) * 5 + j;
			else
				m[i][j] = (i - 1) * 5 + (6 - j);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void permuta(int n, int a[], int k)
{
	for (int i = 1, j = n - k; i < j; i++, j--)
		swap(a[i], a[j]);
	for (int i = n - k + 1, j = n; i < j; i++, j--)
		swap(a[i], a[j]);
	for (int i = 1, j = n; i < j; i++, j--)
		swap(a[i], a[j]);
}

ifstream fin("Bac7In.txt");
ofstream fout("Bac7Out.txt");

int x, p, vf[10];

void SolutieS3E3()
{
	while (fin >> x)
	{
		p = log10(x);
		vf[p]++;
	}

	for (int i = 0; i <= 9; i++)
		while (vf[i])
		{
			fout << pow(10, i) << " ";
			vf[i]--;
		}
}