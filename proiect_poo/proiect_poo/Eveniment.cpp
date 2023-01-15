#include "Eveniment.h"
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

Eveniment::Eveniment() : nrBileteDisponibile(1000)
{
	this->denumire = "";
	this->organizator = "";
	this->descriere = "";
	this->locatieEveniment = "";
	this->dataInceperiiEvenimentului = "";
	this->nrZileDeDesfasurare = 0;
	this->nrDeReprezentariPeZi = nullptr;
	this->oraIncepereReprezentatie = nullptr;
	this->durataReprezentatieInMinute = nullptr;
	this->nrBileteVandute = 0;
}
Eveniment::Eveniment(int nrBileteDisponibile, string denumire, string organizator, string locatieEveniment, string dataInceperiiEvenimentului, int nrZileDeDesfasurare) : nrBileteDisponibile(nrBileteDisponibile)
{
	if (denumire.length() >= 3 && denumire.length() <= 50)
		this->denumire = denumire;
	else
		this->denumire = "Necunoscut";

	if (organizator.length() >= 3 && organizator.length() <= 50)
		this->organizator = organizator;
	else
		this->organizator = "Necunoscut";

	this->descriere = "Necunoscut";

	if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
		this->locatieEveniment = locatieEveniment;
	else
		this->locatieEveniment = "Necunoscut";


	if (dataInceperiiEvenimentului.length() == 10)
	{
		int zi = stoi(dataInceperiiEvenimentului.substr(0, 2));
		int luna = stoi(dataInceperiiEvenimentului.substr(3, 2));
		int an = stoi(dataInceperiiEvenimentului.substr(6, 4));
		if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && dataInceperiiEvenimentului[2] == '/' && dataInceperiiEvenimentului[5] == '/')
			this->dataInceperiiEvenimentului = dataInceperiiEvenimentului;
		else
			this->dataInceperiiEvenimentului = "Invalida";
	}
	else
		this->dataInceperiiEvenimentului = "Invalida";

	if (nrZileDeDesfasurare > 0)
		this->nrZileDeDesfasurare = nrZileDeDesfasurare;
	else
		this->nrZileDeDesfasurare = 0;

	this->nrDeReprezentariPeZi = nullptr;
	this->oraIncepereReprezentatie = nullptr;
	this->durataReprezentatieInMinute = nullptr;
	this->nrBileteVandute = 0;
}

//Creare getter si setter pentru denumire
string Eveniment::getDenumire()
{
	return this->denumire;
}

void Eveniment::setDenumire(string denumire)
{
	if (denumire.length() >= 3 && denumire.length() <= 50)
		this->denumire = denumire;
}

//Creare getter si setter pentru organizator

string Eveniment::getOrganizator()
{
	return this->organizator;
}

void Eveniment::setOrganizator(string organizator)
{
	if (organizator.length() >= 3 && organizator.length() <= 50)
		this->organizator = organizator;
}

//Creare getter si setter pentru descriere

string Eveniment::getDescriere()
{
	return this->descriere;
}

void Eveniment::setDescriere(string descriere)
{
	if (descriere.length() >= 3 && descriere.length() <= 100)
		this->descriere = descriere;
}

//Creare getter si setter pentru locatieEveniment

string Eveniment::getLocatieEveniment()
{
	return this->locatieEveniment;
}

void Eveniment::setLocatieEveniment(string locatieEveniment)
{
	if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
		this->locatieEveniment = locatieEveniment;
}

//Creare getter si setter pentru dataInceperiiEvenimentului

string Eveniment::getDataInceperiiEvenimentului()
{
	return this->dataInceperiiEvenimentului;
}

void Eveniment::setDataInceperiiEvenimentului(string dataInceperiiEvenimentului)
{
	if (dataInceperiiEvenimentului.length() == 10)
	{
		int zi = stoi(dataInceperiiEvenimentului.substr(0, 2));
		int luna = stoi(dataInceperiiEvenimentului.substr(3, 2));
		int an = stoi(dataInceperiiEvenimentului.substr(6, 4));
		if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && dataInceperiiEvenimentului[2] == '/' && dataInceperiiEvenimentului[5] == '/')
			this->dataInceperiiEvenimentului = dataInceperiiEvenimentului;
	}
}

//Creare getter si setter pentru nrZileDeDesfasurare

int Eveniment::getNrZileDeDesfasurare()
{
	return this->nrZileDeDesfasurare;
}

void Eveniment::setNrZileDeDesfasurare(int nrZileDeDesfasurare)
{
	if (nrZileDeDesfasurare != this->nrZileDeDesfasurare && nrZileDeDesfasurare > 0)
	{
		//Dezalocam memoria pentru vectorii oraIncepereReprezentatie si durataReprezentatieInMinute, nrDeReprezentariPeZi
		if (this->oraIncepereReprezentatie != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->oraIncepereReprezentatie[i];
			delete[] this->oraIncepereReprezentatie;
			this->oraIncepereReprezentatie = nullptr;
		}

		if (this->durataReprezentatieInMinute != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->durataReprezentatieInMinute[i];
			delete[] this->durataReprezentatieInMinute;
			this->durataReprezentatieInMinute = nullptr;
		}

		if (this->nrDeReprezentariPeZi != nullptr)
		{
			delete[] this->nrDeReprezentariPeZi;
			this->nrDeReprezentariPeZi = nullptr;
		}

		this->nrZileDeDesfasurare = nrZileDeDesfasurare;
	}

}

//Creare getter si setter pentru nrDeReprezentariPeZi

int* Eveniment::getNrDeReprezentariPeZi()
{
	return this->nrDeReprezentariPeZi;
}

void Eveniment::setNrDeReprezentariPeZi(int* nrDeReprezentariPeZi, int nrZileDeDesfasurare)
{
	if (nrDeReprezentariPeZi != nullptr && nrZileDeDesfasurare > 0)
	{
		//Dezalocam memoria pentru vectorii oraIncepereReprezentatie si durataReprezentatieInMinute
		if (this->oraIncepereReprezentatie != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->oraIncepereReprezentatie[i];
			delete[] this->oraIncepereReprezentatie;
			this->oraIncepereReprezentatie = nullptr;
		}

		if (this->durataReprezentatieInMinute != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->durataReprezentatieInMinute[i];
			delete[] this->durataReprezentatieInMinute;
			this->durataReprezentatieInMinute = nullptr;
		}

		//Apoi realocam vectorul nrDeReprezentariPeZi
		if (this->nrDeReprezentariPeZi != nullptr)
			delete[] this->nrDeReprezentariPeZi;
		this->nrDeReprezentariPeZi = new int[nrZileDeDesfasurare];
		for (int i = 0; i < nrZileDeDesfasurare; i++)
			this->nrDeReprezentariPeZi[i] = nrDeReprezentariPeZi[i];
		this->nrZileDeDesfasurare = nrZileDeDesfasurare;
	}
}

//Creare getter si setter pentru oraIncepereReprezentatie

string** Eveniment::getOraIncepereReprezentatie()
{
	return this->oraIncepereReprezentatie;
}

void Eveniment::setOraIncepereReprezentatie(string** oraIncepereReprezentatie)
{
	if (oraIncepereReprezentatie != nullptr)
	{
		if (this->oraIncepereReprezentatie != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->oraIncepereReprezentatie[i];
			delete[] this->oraIncepereReprezentatie;
			this->oraIncepereReprezentatie = nullptr;
		}

		//Apoi realocam vectorul oraIncepereReprezentatie

		this->oraIncepereReprezentatie = new string * [this->nrZileDeDesfasurare];
		for (int i = 0; i < this->nrZileDeDesfasurare; i++)
		{
			this->oraIncepereReprezentatie[i] = new string[this->nrDeReprezentariPeZi[i]];
			for (int j = 0; j < this->nrDeReprezentariPeZi[i]; j++)
				this->oraIncepereReprezentatie[i][j] = oraIncepereReprezentatie[i][j];
		}
	}
}

//Creare getter si setter pentru durataReprezentatieInMinute

int** Eveniment::getDurataReprezentatieInMinute()
{
	return this->durataReprezentatieInMinute;
}

void Eveniment::setDurataReprezentatieInMinute(int** durataReprezentatieInMinute)
{
	if (durataReprezentatieInMinute != nullptr)
	{
		if (this->durataReprezentatieInMinute != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->durataReprezentatieInMinute[i];
			delete[] this->durataReprezentatieInMinute;
			this->durataReprezentatieInMinute = nullptr;
		}

		//Apoi realocam vectorul durataReprezentatieInMinute

		this->durataReprezentatieInMinute = new int* [this->nrZileDeDesfasurare];
		for (int i = 0; i < this->nrZileDeDesfasurare; i++)
		{
			this->durataReprezentatieInMinute[i] = new int[this->nrDeReprezentariPeZi[i]];
			for (int j = 0; j < this->nrDeReprezentariPeZi[i]; j++)
				this->durataReprezentatieInMinute[i][j] = durataReprezentatieInMinute[i][j];
		}
	}
}

//Getter pentru nrBileteDisponibile pentru ca e constant si nu poate fi modificat

int Eveniment::getNrBileteDisponibile()
{
	return this->nrBileteDisponibile;
}

//Creare getter si setter pentru nrBileteVandute

int Eveniment::getNrBileteVandute()
{
	return this->nrBileteVandute;
}

void Eveniment::setNrBileteVandute(int nrBileteVandute)
{
	if (nrBileteVandute >= 0 && nrBileteVandute <= this->nrBileteDisponibile)
	{
		this->nrBileteVandute = nrBileteVandute;
	}

}

//Metode generice

void Eveniment::schimbaDurataEveniment(int durataNoua, int zi, int reprezentatie)
{
	if (zi >= 0 && zi < this->nrZileDeDesfasurare && reprezentatie >= 0 && reprezentatie < this->nrDeReprezentariPeZi[zi])
	{
		this->durataReprezentatieInMinute[zi][reprezentatie] = durataNoua;
	}
}

void Eveniment::schimbaOraIncepereEveniment(string oraNoua, int zi, int reprezentatie)
{
	if (zi >= 0 && zi < this->nrZileDeDesfasurare && reprezentatie >= 0 && reprezentatie < this->nrDeReprezentariPeZi[zi] && oraNoua.length() == 5)
	{
		
		int ora = stoi(oraNoua.substr(0, 2));
		int minut = stoi(oraNoua.substr(3, 2));
		if (ora >= 0 && ora <= 23 && minut >= 0 && minut <= 59 && oraNoua[2] == ':')
			this->oraIncepereReprezentatie[zi][reprezentatie] = oraNoua;
	}
}

//Constructor de copiere
Eveniment::Eveniment(const Eveniment& e) : nrBileteDisponibile(e.nrBileteDisponibile)
{
	this->denumire = e.denumire;
	this->organizator = e.organizator;
	this->descriere = e.descriere;
	this->locatieEveniment = e.locatieEveniment;

	this->dataInceperiiEvenimentului = e.dataInceperiiEvenimentului;
	this->nrZileDeDesfasurare = e.nrZileDeDesfasurare;

	if (e.nrZileDeDesfasurare > 0 && e.nrDeReprezentariPeZi != nullptr)
	{
		this->nrDeReprezentariPeZi = new int[e.nrZileDeDesfasurare];
		for (int i = 0; i < e.nrZileDeDesfasurare; i++)
			this->nrDeReprezentariPeZi[i] = e.nrDeReprezentariPeZi[i];
	}

	if (e.nrZileDeDesfasurare > 0 && e.oraIncepereReprezentatie != nullptr && e.nrDeReprezentariPeZi != nullptr)
	{
		this->oraIncepereReprezentatie = new string * [e.nrZileDeDesfasurare];
		for (int i = 0; i < e.nrZileDeDesfasurare; i++)
		{
			this->oraIncepereReprezentatie[i] = new string[e.nrDeReprezentariPeZi[i]];
			for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
				this->oraIncepereReprezentatie[i][j] = e.oraIncepereReprezentatie[i][j];
		}
	}

	if (e.nrZileDeDesfasurare > 0 && e.durataReprezentatieInMinute != nullptr && e.nrDeReprezentariPeZi != nullptr)
	{
		this->durataReprezentatieInMinute = new int* [e.nrZileDeDesfasurare];
		for (int i = 0; i < e.nrZileDeDesfasurare; i++)
		{
			this->durataReprezentatieInMinute[i] = new int[e.nrDeReprezentariPeZi[i]];
			for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
				this->durataReprezentatieInMinute[i][j] = e.durataReprezentatieInMinute[i][j];
		}
	}

	this->nrBileteVandute = e.nrBileteVandute;

}

//Supraincarcare operator=

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		this->denumire = e.denumire;
		this->organizator = e.organizator;
		this->descriere = e.descriere;
		this->locatieEveniment = e.locatieEveniment;
		this->dataInceperiiEvenimentului = e.dataInceperiiEvenimentului;
		this->nrZileDeDesfasurare = e.nrZileDeDesfasurare;

		//Dezalocarea a ceea ce avem deja stocat
		if (this->oraIncepereReprezentatie != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->oraIncepereReprezentatie[i];
			delete[] this->oraIncepereReprezentatie;
		}

		if (this->durataReprezentatieInMinute != nullptr)
		{
			for (int i = 0; i < this->nrZileDeDesfasurare; i++)
				delete[] this->durataReprezentatieInMinute[i];
			delete[] this->durataReprezentatieInMinute;
		}

		if (this->nrDeReprezentariPeZi != nullptr)
			delete[] this->nrDeReprezentariPeZi;
		//Alocarea noilor date
		if (e.nrZileDeDesfasurare > 0 && e.nrDeReprezentariPeZi != nullptr)
		{
			this->nrDeReprezentariPeZi = new int[e.nrZileDeDesfasurare];
			for (int i = 0; i < e.nrZileDeDesfasurare; i++)
				this->nrDeReprezentariPeZi[i] = e.nrDeReprezentariPeZi[i];
		}

		if (e.nrZileDeDesfasurare > 0 && e.oraIncepereReprezentatie != nullptr && e.nrDeReprezentariPeZi != nullptr)
		{
			this->oraIncepereReprezentatie = new string * [e.nrZileDeDesfasurare];
			for (int i = 0; i < e.nrZileDeDesfasurare; i++)
			{
				this->oraIncepereReprezentatie[i] = new string[e.nrDeReprezentariPeZi[i]];
				for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
					this->oraIncepereReprezentatie[i][j] = e.oraIncepereReprezentatie[i][j];
			}
		}

		if (e.nrZileDeDesfasurare > 0 && e.durataReprezentatieInMinute != nullptr && e.nrDeReprezentariPeZi != nullptr)
		{
			this->durataReprezentatieInMinute = new int* [e.nrZileDeDesfasurare];
			for (int i = 0; i < e.nrZileDeDesfasurare; i++)
			{
				this->durataReprezentatieInMinute[i] = new int[e.nrDeReprezentariPeZi[i]];
				for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
					this->durataReprezentatieInMinute[i][j] = e.durataReprezentatieInMinute[i][j];
			}
		}

		this->nrBileteVandute = e.nrBileteVandute;

	}
	return *this;
}

//Supraincarcare operatori[]
int Eveniment::operator[](int index) // returneaza numarul de reprezentaridin ziua data drept index dar nu il poate modifica
{
	if (index >= 0 && index < this->nrZileDeDesfasurare)
		return this->nrDeReprezentariPeZi[index];
	else
		throw - 1;
}

//Supraincarcare operator+
Eveniment Eveniment::operator+(int nrBilete)
{
	Eveniment copie = *this;
	copie.nrBileteVandute += nrBilete;
	return copie;
}

//Asigurarea comutativitatii
Eveniment operator+(int nrBilete, Eveniment e)
{
	return e + nrBilete;
}

//Destructor
Eveniment::~Eveniment()
{

	if (this->nrZileDeDesfasurare > 0 && this->oraIncepereReprezentatie != nullptr)
	{
		for (int i = 0; i < this->nrZileDeDesfasurare; i++)
			delete[] this->oraIncepereReprezentatie[i];
		delete[] this->oraIncepereReprezentatie;
	}

	if (this->nrZileDeDesfasurare > 0 && this->durataReprezentatieInMinute != nullptr)
	{
		for (int i = 0; i < this->nrZileDeDesfasurare; i++)
			delete[] this->durataReprezentatieInMinute[i];
		delete[] this->durataReprezentatieInMinute;
	}

	if (this->nrZileDeDesfasurare > 0 && this->nrDeReprezentariPeZi != nullptr)
		delete[] this->nrDeReprezentariPeZi;
}

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Denumira evenimentului este: " << e.denumire << endl;
	out << "Organizatorul evenimentuluieste : " << e.organizator << endl;
	out << "Descriere: " << e.descriere << endl;
	out << "Evenimentul va avea loc la: " << e.locatieEveniment << " incepand cu data de " << e.dataInceperiiEvenimentului << endl;
	out << "Numarul de zile de desfasurare este de : " << e.nrZileDeDesfasurare << endl;
	out << "Numar bilete vandute in prezent este de : " << e.nrBileteVandute << " din " << e.nrBileteDisponibile << " disponibile" << endl;
	out << "Programul reprezentatiilor este: " << endl;
	for (int i = 0; i < e.nrZileDeDesfasurare; i++)
	{
		out << "Pentru ziua " << i + 1 << ":" << endl;
		for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
		{
			out << "Reprezentatia " << j + 1 << " va avea loc la ora " << e.oraIncepereReprezentatie[i][j] << " si va dura " << e.durataReprezentatieInMinute[i][j] << " minute" << endl;
		}
	}
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	bool valid = false;
	while (valid == false)
	{
		cout << "Denumirea evenimentului este: ";
		getline(in, e.denumire);
		if (e.denumire.length() >= 3 && e.denumire.length() <= 50)
			valid = true;
		else
			cout << "Denumirea trebuie sa aiba intre 3 si 50 de caractere" << endl;
	}
	valid = false;
	while (valid == false)
	{
		cout << "Organizatorul evenimentului este: ";
		getline(in, e.organizator);
		if (e.organizator.length() >= 3 && e.organizator.length() <= 50)
			valid = true;
		else
			cout << "Organizatorul trebuie sa aiba intre 3 si 50 de caractere" << endl;
	}
	valid = false;
	while (valid == false)
	{
		cout << "Descrierea evenimentului este: ";
		getline(in, e.descriere);
		if (e.descriere.length() >= 3 && e.descriere.length() <= 100)
			valid = true;
		else
			cout << "Descrierea trebuie sa aiba intre 3 si 100 de caractere" << endl;
	}
	valid = false;
	while (valid == false)
	{
		cout << "Locatia evenimentului este: ";
		getline(in, e.locatieEveniment);
		if (e.locatieEveniment.length() >= 3 && e.locatieEveniment.length() <= 50)
			valid = true;
		else
			cout << "Locatia trebuie sa aiba intre 3 si 50 de caractere" << endl;
	}
	valid = false;
	while (valid == false)
	{
		cout << "Introduceti data evenimentului: ";
		getline(in, e.dataInceperiiEvenimentului);
		if (e.dataInceperiiEvenimentului.length() == 10)
		{
			int zi = stoi(e.dataInceperiiEvenimentului.substr(0, 2));
			int luna = stoi(e.dataInceperiiEvenimentului.substr(3, 2));
			int an = stoi(e.dataInceperiiEvenimentului.substr(6, 4));
			if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2020 && an <= 2035 && e.dataInceperiiEvenimentului[2] == '.' && e.dataInceperiiEvenimentului[5] == '.')
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
		cout << "Introduceti numarul de zile de desfasurare: ";
		in >> e.nrZileDeDesfasurare;
		if (e.nrZileDeDesfasurare > 0)
			valid = true;
		else
			cout << "Numarul de zile de desfasurare trebuie sa fie mai mare decat 0!" << endl;
	}
	valid = false;
	if (e.nrDeReprezentariPeZi != nullptr)
	{
		if (e.nrZileDeDesfasurare > 0 && e.oraIncepereReprezentatie != nullptr)
		{
			for (int i = 0; i < e.nrZileDeDesfasurare; i++)
				delete[] e.oraIncepereReprezentatie[i];
			delete[] e.oraIncepereReprezentatie;
		}

		if (e.nrZileDeDesfasurare > 0 && e.durataReprezentatieInMinute != nullptr)
		{
			for (int i = 0; i < e.nrZileDeDesfasurare; i++)
				delete[] e.durataReprezentatieInMinute[i];
			delete[] e.durataReprezentatieInMinute;
		}

		if (e.nrDeReprezentariPeZi != nullptr)
			delete[] e.nrDeReprezentariPeZi;
	}
	e.nrDeReprezentariPeZi = new int[e.nrZileDeDesfasurare];
	e.oraIncepereReprezentatie = new string * [e.nrZileDeDesfasurare];
	e.durataReprezentatieInMinute = new int* [e.nrZileDeDesfasurare];
	for (int i = 0; i < e.nrZileDeDesfasurare; i++)
	{
		cout << "Pentru ziua " << i + 1 << " numarul de reprezentari este: ";
		in >> e.nrDeReprezentariPeZi[i];
		e.oraIncepereReprezentatie[i] = new string[e.nrDeReprezentariPeZi[i]];
		e.durataReprezentatieInMinute[i] = new int[e.nrDeReprezentariPeZi[i]];
		for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
		{
			valid = false;
			in.get();
			while (valid == false)
			{
				cout << "Ora de incepere a reprezentatiei " << j + 1 << " din ziua " << i + 1 << " este: ";
				getline(in, e.oraIncepereReprezentatie[i][j]);
				if (e.oraIncepereReprezentatie[i][j].length() == 5)
				{
					int ora = stoi(e.oraIncepereReprezentatie[i][j].substr(0, 2));
					int minut = stoi(e.oraIncepereReprezentatie[i][j].substr(3, 2));
					if (ora >= 0 && ora <= 23 && minut >= 0 && minut <= 59 && e.oraIncepereReprezentatie[i][j][2] == ':')
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
				cout << "Durata reprezentatiei " << j + 1 << " din ziua " << i + 1 << " este: ";
				in >> e.durataReprezentatieInMinute[i][j];
				if (e.durataReprezentatieInMinute[i][j] > 0)
					valid = true;
				else
					cout << "Durata trebuie sa fie mai mare decat 0!" << endl;
			}
		}
	}

	cout << "Numarul de bilete vandute pana in prezent este: ";
	in >> e.nrBileteVandute;
	return in;

}