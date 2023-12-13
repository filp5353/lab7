#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void zad1(int n, string naz)
{
	string pelnaz = naz + ".txt";
	ofstream plik(pelnaz);
	for (int i = 0; i < n; i++)
	{
		plik << i<<" ";
	}
}

void zad2(string naz)
{
	string pelnaz = naz + ".txt";
	fstream plik(pelnaz);
	string sr;
	while (!plik.eof())
	{
		getline(plik, sr);
		cout << sr << " ";
	}
	plik.close();
}

void zad3(int n, string naz)
{
	string pelnaz = naz + ".txt";
	fstream plik(pelnaz);
	int *tab=new int [n];
	//int i = 0;
		for (int i = 0; i < n; i++)
		{
			plik >> tab[i];
			cout << tab[i] << " ";
		}
	plik.close();
}

void zad4(string naz)
{
	string pelnaz = naz + ".txt";
	fstream plik(pelnaz);
	int max=0, min=1000, wiek;
	string imiona_max, imiona_min, imiona;
	while (!plik.eof())
	{
		plik >> imiona >> wiek;
		if (wiek >= max)
		{
			if (wiek == max)
			{
				imiona_max = imiona_max + " " + imiona;
			}
			else
			{
				imiona_max = imiona;
			}
			max = wiek;
		}
		if (wiek <= min)
		{
			if (wiek == min)
			{
				imiona_min = imiona_min + imiona;
			}
			else
			{
				imiona_min = imiona;
			}
			min = wiek;
		}
	}
	cout << max << " " << imiona_max << "\n" << min << " " << imiona_min;
	plik.close();
}

void zad5(string naz)
{
	string pelnaz = naz + ".txt";
	fstream plik(pelnaz);
	string tmp;
	int tmpi,licz=0;
	int tab[25][2];
	int asc = 97;
	for (int i = 0; i < 25; i++)
	{
		tab[i][0]=asc+i;
		tab[i][1]=0;
	}
	while (!plik.eof())
	{
		plik >> tmp;
	}
	int N = tmp.size();
	for (int i = 0; i < N; i++)
	{
		tolower(tmp[i]);
		tmpi = int(tmp[i]);
		for (int i = 0; i < 25; i++)
		{
			if (tmpi == tab[i][0])
			{
				tab[i][1] = tab[i][1] + 1;
			}
		}
		licz++;
	}
	for (int i = 0; i < 25; i++)
	{
		cout << (char)tab[i][0]<<" " << tab[i][1] / licz << "% ";
	}
}

int main()
{
	int n;
	string nazwa;
	cout << "podaj n " << endl;
	cin >> n;
	cout << "podaj nazwe " << endl;
	cin >> nazwa;
	//zad1(n,nazwa);
	//zad2(nazwa);
	//zad3(n,nazwa);
	zad5(nazwa);
}