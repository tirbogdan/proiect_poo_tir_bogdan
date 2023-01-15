#include "Bilet.h"
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

Bilet::Bilet()
{
	this->idComanda++;
	this->idBilet = "Invalid";
	this->denumireEveniment = "Invalida";
	this->locatieEveniment = "Invalida";
	this->dataEveniment = "Invalida";
	this->oraEveniment = "Invalida";
	this->tipBilet = "Invalid";
	this->pretBilet = 0;
	this->serieBilet = "Invalida";
	this->organizatorEveniment = "Invalid";
}

Bilet::Bilet(string denumireEveniment, string locatieEveniment, string dataEveniment, string oraEveniment, string tipBilet, double pretBilet, string codUnic, string serieBilet, string organizatorEveniment)
{
	this->idComanda++;

	if (denumireEveniment.length() >= 3 && denumireEveniment.length() <= 50)
		this->denumireEveniment = denumireEveniment;
	else
		this->denumireEveniment = "Invalida";

	//Validare idBilet
	if (this->denumireEveniment != "Invalida")
	{
		if (codUnic.length() == 6)
		{
			this->idBilet = this->denumireEveniment.substr(0, 2) + to_string(this->idComanda).substr(0, 2) + codUnic;
		}
		else
			this->idBilet = "Invalid";
	}
	else
		this->idBilet = "Invalid";

	if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
		this->locatieEveniment = locatieEveniment;
	else
		this->locatieEveniment = "Invalida";

	if (dataEveniment.length() == 10)
	{
		int zi = stoi(dataEveniment.substr(0, 2));
		int luna = stoi(dataEveniment.substr(3, 2));
		int an = stoi(dataEveniment.substr(6, 4));
		if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && dataEveniment[2] == '/' && dataEveniment[5] == '/')
			this->dataEveniment = dataEveniment;
		else
			this->dataEveniment = "Invalida";
	}
	else
		this->dataEveniment = "Invalida";


	if (oraEveniment.length() == 5)
	{
		int ora = stoi(oraEveniment.substr(0, 2));
		int minut = stoi(oraEveniment.substr(3, 2));
		if (ora >= 0 && ora <= 23 && minut >= 0 && minut <= 59 && oraEveniment[2] == ':')
			this->oraEveniment = oraEveniment;
		else
			this->oraEveniment = "Invalida";
	}
	else
		this->oraEveniment = "Invalida";

	this->tipBilet = tipBilet;

	if (pretBilet > 0)
		this->pretBilet = pretBilet;
	else
		this->pretBilet = 0;

	if (serieBilet.length() == 10)
		this->serieBilet = serieBilet;
	else
		this->serieBilet = "Invalida";

	if (organizatorEveniment.length() >= 3 && organizatorEveniment.length() <= 50)
		this->organizatorEveniment = organizatorEveniment;
	else
		this->organizatorEveniment = "Invalid";
}

//Getter si setter pentru idBilet
string Bilet::getIdBilet()
{
	return this->idBilet;
}

void Bilet::setIdBilet(string idBilet)
{
	if (this->denumireEveniment != "Invalida")
	{
		if (idBilet.substr(0, 2) == this->denumireEveniment.substr(0, 2) && idBilet.length() == 10)
			this->idBilet = idBilet;
		else
			this->idBilet = "Invalid";
	}
	else
		this->idBilet = "Invalid";
}

//Getter si setter pentru denumireEveniment
string Bilet::getDenumireEveniment()
{
	return this->denumireEveniment;
}

void Bilet::setDenumireEveniment(string denumireEveniment)
{
	if (denumireEveniment.length() >= 3 && denumireEveniment.length() <= 50)
		this->denumireEveniment = denumireEveniment;
	else
		this->denumireEveniment = "Invalida";
}

//Getter si setter pentru locatieEveniment
string Bilet::getLocatieEveniment()
{
	return this->locatieEveniment;
}

void Bilet::setLocatieEveniment(string locatieEveniment)
{
	if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
		this->locatieEveniment = locatieEveniment;
	else
		this->locatieEveniment = "Invalida";
}

//Getter si setter pentru dataEveniment
string Bilet::getDataEveniment()
{
	return this->dataEveniment;
}

void Bilet::setDataEveniment(string dataEveniment)
{
	if (dataEveniment.length() == 10)
	{
		int zi = stoi(dataEveniment.substr(0, 2));
		int luna = stoi(dataEveniment.substr(3, 2));
		int an = stoi(dataEveniment.substr(6, 4));
		if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && dataEveniment[2] == '/' && dataEveniment[5] == '/')
			this->dataEveniment = dataEveniment;
		else
			this->dataEveniment = "Invalida";
	}
	else
		this->dataEveniment = "Invalida";
}

//Getter si setter pentru oraEveniment
string Bilet::getOraEveniment()
{
	return this->oraEveniment;
}

void Bilet::setOraEveniment(string oraEveniment)
{
	if (oraEveniment.length() == 5)
	{
		int ora = stoi(oraEveniment.substr(0, 2));
		int minut = stoi(oraEveniment.substr(3, 2));
		if (ora >= 0 && ora <= 23 && minut >= 0 && minut <= 59 && oraEveniment[2] == ':')
			this->oraEveniment = oraEveniment;
		else
			this->oraEveniment = "Invalida";
	}
	else
		this->oraEveniment = "Invalida";
}

//Getter si setter pentru tipBilet de adaugat verificare
string Bilet::getTipBilet()
{
	return this->tipBilet;
}

void Bilet::setTipBilet(string tipBilet)
{

	this->tipBilet = tipBilet;
}

//Getter si setter pentru pretBilet
double Bilet::getPretBilet()
{
	return this->pretBilet;
}

void Bilet::setPretBilet(float pretBilet)
{
	if (pretBilet > 0)
		this->pretBilet = pretBilet;
	else
		this->pretBilet = 0;
}

//Getter si setter pentru serieBilet
string Bilet::getSerieBilet()
{
	return this->serieBilet;
}

void Bilet::setSerieBilet(string serieBilet)
{
	if (serieBilet.length() == 10)
	{
		this->serieBilet = serieBilet;
	}
	else
		this->serieBilet = "Invalida";
}

//Getter si setter pentru organizatorEveniment
string Bilet::getOrganizatorEveniment()
{
	return this->organizatorEveniment;
}

void Bilet::setOrganizatorEveniment(string organizatorEveniment)
{
	if (organizatorEveniment.length() >= 3 && organizatorEveniment.length() <= 50)
		this->organizatorEveniment = organizatorEveniment;
	else
		this->organizatorEveniment = "Invalid";
}

//2 metode generice
void Bilet::upgrateBilet(string noulTipBilet, float noulPretBilet)
{
	this->tipBilet = noulTipBilet;
	if (noulPretBilet > 0)
		this->pretBilet = noulPretBilet;
}

void Bilet::utilizeazaCodReducere(string codReducere)
{
	if (codReducere == "osky15")
		this->pretBilet = this->pretBilet * 0.75;
	else if (codReducere == "osky20")
		this->pretBilet = this->pretBilet * 0.8;
	else
		cout << "Codul introdus nu este valid!" << endl;
}


//Supraincarcarea a 2 operatori

//supraincarcare operator!
bool Bilet::operator!()
{
	if (this->idBilet == "Invalid")
		return true;
	else
		return false;
}

//supraincarcare operator cast la string
Bilet::operator string()
{
	return this->idBilet;
}

string Bilet::creareCodUnic()
{
	string codUnic = "";

	for (int i = 0; i < 6; i++)
	{
		int random = rand() % 3;
		if (random == 0)
			codUnic += (char)(rand() % 26 + 65); // pentru litere mari
		else if (random == 1)
			codUnic += (char)(rand() % 26 + 97); // pentru litere mici
		else
			codUnic += (char)(rand() % 10 + 48); // pentru cifre
	}

	return codUnic;
}



ostream& operator<<(ostream& out, Bilet b)
{
	out << "Comanda cu numarul " << b.idComanda << ":" << endl;
	out << "ID bilet: " << b.idBilet << endl;
	out << "Denumire eveniment: " << b.denumireEveniment << endl;
	out << "Evenimentul se desfasoare la " << b.locatieEveniment << " pe data de " << b.dataEveniment << " la ora " << b.oraEveniment << endl;
	out << "Tip bilet : " << b.tipBilet << endl;
	out << "Pret bilet este: " << setprecision(2) << fixed << b.pretBilet << endl;
	out << "Serie bilet: " << b.serieBilet << endl;
	out << "Organizatorul evenimentului este: " << b.organizatorEveniment << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	bool valid = false;

	b.idComanda++;

	while (valid == false)
	{
		cout << "Introduceti denumirea evenimentului: ";
		getline(in, b.denumireEveniment);

		if (b.denumireEveniment.length() >= 3 && b.denumireEveniment.length() <= 50)
			valid = true;
		else
			cout << "Denumirea evenimentului trebuie sa aiba intre 3 si 50 caractere!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti ID-ul biletului: ";
		getline(in, b.idBilet);

		if (b.idBilet.substr(0, 2) == b.denumireEveniment.substr(0, 2) && b.idBilet.length() == 10)
			valid = true;
		else
			cout << "ID-ul trebuie sa aiba 10 caractere! Primele 2 caratere reprezinta primele 2 caractere din denumirea evenimentului!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti locatia evenimentului: ";
		getline(in, b.locatieEveniment);

		if (b.locatieEveniment.length() >= 3 && b.locatieEveniment.length() <= 50)
			valid = true;
		else
			cout << "Locatia evenimentului trebuie sa aiba intre 3 si 50 caractere!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti data evenimentului: ";
		getline(in, b.dataEveniment);
		if (b.dataEveniment.length() == 10)
		{
			int zi = stoi(b.dataEveniment.substr(0, 2));
			int luna = stoi(b.dataEveniment.substr(3, 2));
			int an = stoi(b.dataEveniment.substr(6, 4));
			if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && b.dataEveniment[2] == '.' && b.dataEveniment[5] == '.')
				valid = true;
			else
				cout << "Data trebuie sa fie de forma dd.mm.yyyy si sa fie intre 01.01.2020 si 31.12.2035!" << endl;
		}
		else
			cout << "Data trebuie sa fie de forma dd.mm.yyyy si sa fie intre 01.01.2020 si 31.12.2035!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti ora evenimentului: ";
		getline(in, b.oraEveniment);
		if (b.oraEveniment.length() == 5)
		{
			int ora = stoi(b.oraEveniment.substr(0, 2));
			int minut = stoi(b.oraEveniment.substr(3, 2));
			if (ora >= 0 && ora <= 23 && minut >= 0 && minut <= 59 && b.oraEveniment[2] == ':')
				valid = true;
			else
				cout << "Ora trebuie sa fie de forma hh:mm si sa fie intre 00:00 si 23:59!" << endl;
		}
		else
			cout << "Ora trebuie sa fie de forma hh:mm si sa fie intre 00:00 si 23:59!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti tipul biletului: ";
		getline(in, b.tipBilet);
		if (b.tipBilet.length() >= 3 && b.tipBilet.length() <= 50)
			valid = true;
		else
			cout << "Tipul biletului trebuie sa aiba intre 3 si 50 caractere!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti pretul biletului: ";
		in >> b.pretBilet;
		if (b.pretBilet > 0)
			valid = true;
		else
			cout << "Pretul biletului trebuie sa fie mai mare decat 0!" << endl;
	}
	valid = false;
	in.get();

	while (valid == false)
	{

		cout << "Introduceti seria biletului: ";
		getline(in, b.serieBilet);
		if (b.serieBilet.length() == 10)
			valid = true;
		else
			cout << "Seria trebuie sa aiba 10 caractere!" << endl;
	}
	valid = false;

	while (valid == false)
	{
		cout << "Introduceti organizatorul evenimentului: ";
		getline(in, b.organizatorEveniment);
		if (b.organizatorEveniment.length() >= 3 && b.organizatorEveniment.length() <= 50)
			valid = true;
		else
			cout << "Organizatorul evenimentului trebuie sa aiba intre 3 si 50 caractere!" << endl;
	}

	return in;
}

int Bilet::idComanda = 10;