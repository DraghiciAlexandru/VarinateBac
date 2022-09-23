#include <iostream>
#include <fstream>

using namespace std;

void SolutieS2E2()
{
	char v[5][5];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if(i%2==0)
			{
				if (j < 2)
					v[i][j] = 'a';
				else
					v[i][j] = 'b';
			}
			else
			{
				if (j < 2)
					v[i][j] = 'A';
				else
					v[i][j] = 'B';
			}
		}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

void factor(int n, int v[], int& fp, int& p)
{
	int f[100], pt[100], c, nf = 0, d, pf, poz, ok = 0;
	fp = 1;
	c = v[1];
	d = 2;
	while(c>1)
	{
		pf = 0;
		while(c%d==0)
		{
			c /= d;
			pf++;
		}
		if(pf!=0)
		{
			nf++;
			f[nf] = d;
			pt[nf] = pf;
		}
		d++;
	}

	poz = 1;
	for (int i = 2; i < n && fp>0; i++)
	{
		for(int j=poz; j<=nf; j++)
		{
			if(c%f[j]==0)
			{
				pf = 0;
				ok = 1;
				while(c%f[j]==0)
				{
					pf++;
					c /= f[i];
				}
				if (pf < pt[j])
					pt[j] = pf;
				fp = f[j];
				p = pt[j];
				poz = j;
				break;
			}
		}
		if(ok==0)
		{
			fp = -1;
			p = 0;
		}
	}
}

ofstream fout("Bac19.txt");

void SolutieS3E3()
{
	int nr = 0;
	for(int c1=1; c1<=9; c1+=2)
		for(int c2=1; c2<=9; c2+=2)
			for(int c3=1; c3<=9; c3+=2)
			{
				nr = c1 * 100000 + c2 * 10000 + c3 * 1000 + c3 * 100 + c2 * 10 + c1;
				fout << nr << endl;
			}
}
