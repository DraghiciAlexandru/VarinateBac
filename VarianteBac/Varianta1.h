#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Data
{
	int zi, luna, an;
};

struct Elev
{
	char nume[21];
	Data dn;
};

Elev e;

void citireS2E2()
{
	cout << "Nume:";
	cin >> e.nume;
	cout << "Zi:";
	cin >> e.dn.zi;
	cout << "Luna:";
	cin >> e.dn.luna;
	cout << "An:";
	cin >> e.dn.an;
}

void SolutieS2E2()
{
	citireS2E2();
	if (e.dn.an == 2000)
		cout << e.nume;
	else
		cout << e.dn.zi << " " << e.dn.luna << " " << e.dn.an;
}

int A[5][5];

void SolutieS2E3()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			A[i][j] = (i + j) % 5;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}


char s[101], aux[101];
int max = 0;

/*void citireS3E1()
{
	cout << "Sir:";
	cin.get(s, 101);
	strcpy(aux, s);
}

char** VCuvinte(char* sir)
{
	char** cuvinte = new char* [25];
	
	int nr = 0;

	
	char * p;
	p = strtok(sir, "#");
	while(p!=NULL)
	{
		strcpy(cuvinte[nr], p);
		nr++;
		p = strtok(NULL, "#");
	}

	return cuvinte;
}*/

void afisareS3E1(char**cuvinte)
{
	for(char*p=cuvinte[0];p!=NULL;p++)
	{

		cout << endl;
		 
	}
}

void SolutieS3E1()
{
	char x[120] = "#Voi#da#bacu#la#info#";
	//afisareS3E1(VCuvinte(x));
}

int numarareS3E2(int n, int m, int a[], int b[])
{
	int nr = 0, min = b[0];
	for(int i=1; i<m; i++)
	{
		if (b[i] < min)
			min = b[i];
	}
	for(int i=0; i<n; i++)
	{
		if (a[i] < min)
			nr++;
	}
	return nr;
}


ifstream fin("bac.txt");


void SolutieS3E3()
{
	int x, y, l = 1, lmax = 1;

	fin >> x;
	while(fin>>y)
	{
		int aux = y;
		while (aux > 9)
			aux= aux / 10;
		if (x % 10 == aux)
			l++;
		else
		{
			if (l > lmax)
				lmax = l;
			l = 1;
		}
		x = y;
	}

	cout << lmax;
}