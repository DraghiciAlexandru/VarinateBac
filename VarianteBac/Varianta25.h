#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct triunghi
{
	float l1, l2, l3;
}t[100];

float x, y;
int n, i;

void SolutieS2E3()
{
	for(int i=0; i<n; i++)
	{
		float p = (t[i].l1 + t[i].l2 + t[i].l3) / 3;
		float aria = sqrt(p * (p - t[i].l1) * (p - t[i].l2) * (p - t[i].l3));
		if (aria >= x && aria <= y)
			cout << t[i].l1 << " " << t[i].l2 << " " << t[i].l3 << "*";
	}
}

int a[11][21];

void SolutieS3E1()
{
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
			if (i == j || i + j == 2 * n)
				a[i][j] = 1;
			else
				a[i][j] = 2;
	}
	for(int i=1; i<=n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

int SolutieS3E2(int v[], int n, int k)
{
	for (int i = 1; i < k / 2; i++)
		swap(v[i], v[k + 1 - i]);
	int i = k + 1;
	int j = n;
	while (i < j)
	{
		swap(v[i], v[j]);
		i++;
		j++;
	}
	for (i = 1; i <= n / 2; i++)
		swap(v[i], v[n + 1 - i]);
	for (i = 1; i < n / 2; i++)
	{
		if (v[i] != v[n + 1 - i])
			return 0;
	}
	return 1;
}


int T, l, c, s, poz;

void SolutieS3E3()
{
	cin >> n;
	T = 0;
	while (s < n)
	{
		T++;
		s += (T + 1) * (T + 2) / 2;
	}
	if (s == n)
		cout << T << " " << T + 1 << " " << T + 2;
	else
	{
		l = T + 1;
		while(s>=n)
		{
			s = s - l;
			l--;
		}
		l++;
		if (s - l == n)
			c = l;
		else
			c = n - s;
		cout << T << " " << l << " " << c;
	}
}

