#include <iostream>
#include <iomanip>
#include <string>
#include "Locatie.h"
#include "Bilet.h"
#include "Eveniment.h"
#include "Auxiliare.h"
#pragma warning(disable: 4996)
using namespace std;



int main()
{
	
	string optiune = "0";
	do
	{
		Auxiliare::afisareOptiuniMeniuprincipal();
		Auxiliare::functionalitateMeniuPrincipal(optiune);
	}
	while (optiune != "0");
	
	return 0;
}