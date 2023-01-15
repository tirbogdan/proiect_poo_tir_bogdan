#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Locatie.h"
#pragma warning(disable: 4996)
using namespace std;
class Auxiliare
{
private:
	Locatie *locatii;
	static int nrLocatii;
public:
	Auxiliare();
	
	static void afisareOptiuniMeniuprincipal();
	static void functionalitateMeniuPrincipal(string &optiune);
	static void afisareOptiuniMeniuLocatii();
	static void functionalitateMeniuLocatii(string& optiune);
	static void afisareOptiuniMeniuBilete();
	static void functionalitateMeniuBilete(string& optiune);
	static void afisareOptiuniMeniuEvenimente();
	static void functionalitateMeniuEvenimente(string& optiune);
	static bool verificareOptiune(string optiune, int nrMaxOptiuni);
	static void citesteLocatie(Locatie& locatii);

};

