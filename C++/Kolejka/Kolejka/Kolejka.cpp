// Kolejka.cpp: Określa punkt wejścia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct elem {
	int dane;
	elem*nast;
};


void add(elem* &poczatek, elem* &koniec, int dod)
{
	elem* pomocnik;
	if (poczatek == 0)
	{
		pomocnik = new elem;
		pomocnik->dane = dod;
		pomocnik->nast = NULL;
		poczatek=koniec = pomocnik;

	}
	else
	{
		pomocnik = new elem;
		pomocnik->dane = dod;
		pomocnik->nast = NULL;
		koniec->nast = pomocnik;
		koniec = pomocnik;
	}

}

int next(elem* &poczatek, elem* &koniec)
{
	int a;
	elem* pomoc;
	if (poczatek == koniec)
	{
		a = poczatek->dane;
		delete poczatek;
		poczatek = koniec = NULL;
		return a;
	}
	else
	{
		a = poczatek->dane;
		pomoc = poczatek->nast;
		delete poczatek;
		poczatek = pomoc;
		return a;
	}
}


int main()
{
	int a;
	elem* poczatek;
	elem* koniec;
	poczatek = koniec = NULL;
	add(poczatek, koniec, 8);
	cout << poczatek << endl;
	add(poczatek, koniec, 7);
	add(poczatek, koniec, 6);
	cout << poczatek << endl;
	add(poczatek, koniec, 4);
	cout << poczatek << endl;
	cout << koniec << endl;

	cout << next(poczatek, koniec) << endl;
	cout << next(poczatek, koniec) << endl;
	cout << next(poczatek, koniec) << endl;
	cout << next(poczatek, koniec) << endl;
	cout << poczatek << endl;
	cout << koniec << endl;
	cin >> a;
	return 0;
}

