#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

bool autentificare(string parola)
{
	ifstream fin("password.txt");
	string password;
	fin >> password;
	if (parola == password) return true;
	return false;
}

int main()
{
	bool conectat = false;
	cout << "Bine ai venit la aplicatia de gestiune a biletelor unui teatru\n";
	cout << "Pentru a continua te rugam sa introduci parola: ";
	
	for (int i = 2; i >= 0; i--)
	{
		string parola;
		cin >> parola;
		if (autentificare(parola))
		{
			cout << "Felicitari, acum esti conectat";
			conectat = true;
			break;
		}
		else 
		{ 
			system("CLS");
			cout << "Imi pare rau, parola este incorecta\n"; 
			cout << "Mai ai " << i << " incercari\n";
		}
		if (conectat == false && i == 0)
		{
			system("CLS");
			cout << "Ai gresit parola de 3 ori deci nu mai ai acces la aplicatie";
			return 0;
		}
		cout << "Pentru a continua te rugam sa introduci parola: ";
	}
	system("CLS");
	cout << "Felicitari acum esti conectat";
	
	return 0;
}