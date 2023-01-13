#include <iostream>
#include <iomanip>
#include <string>
#include "Locatie.h"
#pragma warning(disable: 4996)
using namespace std;

class Eveniment
{
	//to do: implementare in propriul fisier header
private:
	string denumire;
	string organizator;
	string descriere;
	string locatieEveniment;
	string dataInceperiiEvenimentului;
	int nrZileDeDesfasurare;
	int* nrDeReprezentariPeZi;
	string** oraIncepereReprezentatie;
	int** durataReprezentatieInMinute;
	const int nrBileteDisponibile;
	int nrBileteVandute;

public:
	Eveniment() : nrBileteDisponibile(1000)
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
	Eveniment(int nrBileteDisponibile, string denumire, string organizator, string locatieEveniment, string dataInceperiiEvenimentului, int nrZileDeDesfasurare) : nrBileteDisponibile(nrBileteDisponibile)
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

	//Creare getteri si setteri pentru atribute

	//Creare getter si setter pentru denumire
	string getDenumire()
	{
		return this->denumire;
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() >= 3 && denumire.length() <= 50)
			this->denumire = denumire;
	}

	//Creare getter si setter pentru organizator

	string getOrganizator()
	{
		return this->organizator;
	}

	void setOrganizator(string organizator)
	{
		if (organizator.length() >= 3 && organizator.length() <= 50)
			this->organizator = organizator;
	}

	//Creare getter si setter pentru descriere

	string getDescriere()
	{
		return this->descriere;
	}

	void setDescriere(string descriere)
	{
		if (descriere.length() >= 3 && descriere.length() <= 100)
			this->descriere = descriere;
	}


	//Creare getter si setter pentru locatieEveniment

	string getLocatieEveniment()
	{
		return this->locatieEveniment;
	}

	void setLocatieEveniment(string locatieEveniment)
	{
		if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
			this->locatieEveniment = locatieEveniment;
	}

	//Creare getter si setter pentru dataInceperiiEvenimentului

	string getDataInceperiiEvenimentului()
	{
		return this->dataInceperiiEvenimentului;
	}

	void setDataInceperiiEvenimentului(string dataInceperiiEvenimentului)
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

	int getNrZileDeDesfasurare()
	{
		return this->nrZileDeDesfasurare;
	}

	void setNrZileDeDesfasurare(int nrZileDeDesfasurare)
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

	int* getNrDeReprezentariPeZi()
	{
		return this->nrDeReprezentariPeZi;
	}

	void setNrDeReprezentariPeZi(int* nrDeReprezentariPeZi, int nrZileDeDesfasurare)
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

	string** getOraIncepereReprezentatie()
	{
		return this->oraIncepereReprezentatie;
	}

	void setOraIncepereReprezentatie(string** oraIncepereReprezentatie)
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

	int** getDurataReprezentatieInMinute()
	{
		return this->durataReprezentatieInMinute;
	}

	void setDurataReprezentatieInMinute(int** durataReprezentatieInMinute)
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

	int getNrBileteDisponibile()
	{
		return this->nrBileteDisponibile;
	}

	//Creare getter si setter pentru nrBileteVandute

	int getNrBileteVandute()
	{
		return this->nrBileteVandute;
	}

	void setNrBileteVandute(int nrBileteVandute)
	{
		if (nrBileteVandute >= 0 && nrBileteVandute <= this->nrBileteDisponibile)
		{
			this->nrBileteVandute = nrBileteVandute;
		}

	}

	//2 metode generice

	void schimbaDurataEveniment(int durataNoua, int zi, int reprezentatie)
	{
		if (zi >= 0 && zi < this->nrZileDeDesfasurare && reprezentatie >= 0 && reprezentatie < this->nrDeReprezentariPeZi[zi])
		{
			this->durataReprezentatieInMinute[zi][reprezentatie] = durataNoua;
		}
	}

	void schimbaOraIncepereEveniment(string oraNoua, int zi, int reprezentatie)
	{
		if (zi >= 0 && zi < this->nrZileDeDesfasurare && reprezentatie >= 0 && reprezentatie < this->nrDeReprezentariPeZi[zi])
		{
			this->oraIncepereReprezentatie[zi][reprezentatie] = oraNoua;
		}
	}


	//Creare constructor de copiere

	Eveniment(const Eveniment& e) : nrBileteDisponibile(e.nrBileteDisponibile)
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

	Eveniment& operator=(const Eveniment& e)
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
	}

	//Supraincarcare operatori[]
	int operator[](int index) // returneaza numarul de reprezentaridin ziua data drept index dar nu il poate modifica
	{
		if (index >= 0 && index < this->nrZileDeDesfasurare)
			return this->nrDeReprezentariPeZi[index];
		else
			throw - 1;
	}

	//Supraincarcare operator+
	Eveniment operator+(int nrBilete)
	{
		Eveniment copie	 = *this;
		copie.nrBileteVandute += nrBilete;
		return copie;
	}

	//Asigurarea comutativitatii
	friend Eveniment operator+(int nrBilete, Eveniment e)
	{
		return e + nrBilete;
	}

	//Creare destructor

	~Eveniment()
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

	//Citire si Afisare
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Denumira evenimentului este: " << e.denumire << endl;
	out << "Organizatorul evenimentuluieste : " << e.organizator << endl;
	out << "Descriere: " << e.descriere << endl;
	out << "Evenimentul va avea loc la: " << e.locatieEveniment << " incepand cu data de " << e.dataInceperiiEvenimentului << endl;
	out << "Numarul de zile de desfasurare este de : " << e.nrZileDeDesfasurare << endl;
	out << "Numar bilete vandute in prezent este de : " << e.nrBileteVandute << " din " << e.nrBileteDisponibile << " disponibile" << endl;
	out << "Programul reprezentatiilor este: " << endl;
	for (int  i = 0; i < e.nrZileDeDesfasurare; i++)
	{
		out << "Pentru ziua " << i + 1 << ":" << endl;
		for (int j = 0; j < e.nrDeReprezentariPeZi[i]; j++)
		{			out << "Reprezentatia " << j + 1 << " va avea loc la ora " << e.oraIncepereReprezentatie[i][j] << " si va dura " << e.durataReprezentatieInMinute[i][j] << " minute" << endl;
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
	e.oraIncepereReprezentatie = new string* [e.nrZileDeDesfasurare];
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


class Bilet
{
	//to do: de verificat daca tipul biletului este unul valabil
private:
	static int idComanda;	
	string idBilet;//
	string denumireEveniment;//
	string locatieEveniment;//
	string dataEveniment;//
	string oraEveniment;//
	string tipBilet;
	double pretBilet;//
	string serieBilet;//
	string organizatorEveniment;//

public:
	Bilet()
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
	
	Bilet(string denumireEveniment, string locatieEveniment, string dataEveniment, string oraEveniment, string tipBilet, double pretBilet, string codUnic, string serieBilet, string organizatorEveniment)
	{
		this->idComanda++;

		if (denumireEveniment.length() >= 3 && denumireEveniment.length() <= 50	)
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
	string getIdBilet()
	{
		return this->idBilet;
	}
	void setIdBilet(string idBilet)
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
	string getDenumireEveniment()
	{
		return this->denumireEveniment;
	}
	
	void setDenumireEveniment(string denumireEveniment)
	{
		if (denumireEveniment.length() >= 3 && denumireEveniment.length() <= 50)
			this->denumireEveniment = denumireEveniment;
		else
			this->denumireEveniment = "Invalida";
	}
	
	//Getter si setter pentru locatieEveniment
	string getLocatieEveniment()
	{
		return this->locatieEveniment;
	}
	
	void setLocatieEveniment(string locatieEveniment)
	{
		if (locatieEveniment.length() >= 3 && locatieEveniment.length() <= 50)
			this->locatieEveniment = locatieEveniment;
		else
			this->locatieEveniment = "Invalida";
	}
	
	//Getter si setter pentru dataEveniment
	string getDataEveniment()
	{
		return this->dataEveniment;
	}
	
	void setDataEveniment(string dataEveniment)
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
	string getOraEveniment()
	{
		return this->oraEveniment;
	}

	void setOraEveniment(string oraEveniment)
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
	string getTipBilet()
	{
		return this->tipBilet;
	}
	
	void setTipBilet(string tipBilet) 
	{
		
		this->tipBilet = tipBilet;
	}
	
	//Getter si setter pentru pretBilet
	double getPretBilet()
	{
		return this->pretBilet;
	}
	
	void setPretBilet(float pretBilet)
	{
		if (pretBilet > 0)
			this->pretBilet = pretBilet;
		else
			this->pretBilet = 0;
	}
	
	//Getter si setter pentru serieBilet
	string getSerieBilet()
	{
		return this->serieBilet;
	}
	
	void setSerieBilet(string serieBilet)
	{
		if (serieBilet.length() == 10)
		{
			this->serieBilet = serieBilet;
		}
		else
			this->serieBilet = "Invalida";
	}

	//Getter si setter pentru organizatorEveniment
	string getOrganizatorEveniment()
	{
		return this->organizatorEveniment;
	}
	
	void setOrganizatorEveniment(string organizatorEveniment)
	{
		if (organizatorEveniment.length() >= 3 && organizatorEveniment.length() <= 50)
			this->organizatorEveniment = organizatorEveniment;
		else
			this->organizatorEveniment = "Invalid";
	}
	
	//2 metode generice
	void upgrateBilet(string noulTipBilet, float noulPretBilet)
	{
		this->tipBilet = noulTipBilet;
		if (noulPretBilet > 0)
			this->pretBilet = noulPretBilet;
	}
	
	void utilizeazaCodReducere(string codReducere)
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
	bool operator!()
	{
		if (this->idBilet == "Invalid")
			return true;
		else
			return false;
	}

	//supraincarcare operator
	operator string()
	{
		return this->idBilet;
	}

	static string creareCodUnic()
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
	
	//Citire si Afisare
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};

ostream& operator<<(ostream& out, Bilet b)
{
	out << "Comanda cu numarul " << b.idComanda << ":" << endl;
	out << "ID bilet: " << b.idBilet << endl;
	out << "Denumire eveniment: " << b.denumireEveniment << endl;
	out << "Evenimentul se desfasoare la " << b.locatieEveniment << " pe data de " << b.dataEveniment << " la ora " << b.oraEveniment << endl;
	out << "Tip bilet : " << b.tipBilet << endl;
	out << "Pret bilet este: " << setprecision(2) << fixed  << b.pretBilet << endl;
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



int main()
{
	//Testare functionalitati
	Locatie l;
	//cout << l;

	string loc = "buftea";
	string adresa = "str mare din bucuresti";
	string telefon = "0770103861";
	Locatie l1(loc, adresa, telefon, 500, 12313.95);
	//cout << l1;
	//l1.setDenumire("Milmoiesti");
	//cout << endl << l1.getDenumire();
	//l1.setAdresa("Strada asta");
	//cout << endl << l1.getAdresa();
	//l1.setTelefon("1234567890");
	//cout << endl << l1.getTelefon();
	//l1.setCapacitate(123);
	//cout << endl << l1.getCapacitate();
	//l1.setPretInchiriere(123.3123);
	//cout << endl << l1.getPretInchiriere();
	

	char** zone = nullptr;
	zone = new char* [3];
	zone[0] = new char[strlen("Peluza A") + 1];
	zone[1] = new char[strlen("Peluza B") + 1];
	zone[2] = new char[strlen("Peluza C") + 1];
	strcpy(zone[0], "Peluza A");
	strcpy(zone[1], "Peluza B");
	strcpy(zone[2], "Peluza C");
	l1.setNrSectoare(3);
	l1.setDenumireSector(zone);
	//cout << l1;
	//l1.setNrSectoare(5);
	//cout << l1.getNrSectoare();
	/*
	for (int i = 0; i < l1.getNrSectoare(); i++)
	{
		cout << endl << l1.getDenumireSector()[i];
	}
	l1.setDenumireSector(nullptr, 3, (char*)"Ghencea");
	for (int i = 0; i < l1.getNrSectoare(); i++)
	{
		cout << endl << l1.getDenumireSector()[i];
	}
	strcpy(zone[2], "Peluza D");
	l1.setDenumireSector(zone);
	for (int i = 0; i < l1.getNrSectoare(); i++)
	{
		cout << endl << l1.getDenumireSector()[i];
	}
	*/
	bool* testBool;
	testBool = new bool[3];
	testBool[0] = true;
	testBool[1] = false;
	testBool[2] = true;

	l1.setContineLocuri(testBool);
	for (int i = 0; i < l1.getNrSectoare(); i++)
	{
		if (l1.getContineLocuri() != nullptr)
		{
			cout << "Sectorul " << i << ((l1.getContineLocuri()[i] == 0) ? " contine locuri\n" : " nu contine locuri\n");
		}
	}
	l1.setContineLocuri(nullptr, 2);
	cout << endl;
	for (int i = 0; i < l1.getNrSectoare(); i++)
	{
		if (l1.getContineLocuri() != nullptr)
		{
			cout << "Sectorul " << i << ((l1.getContineLocuri()[i] == 0) ? " contine locuri\n" : " nu contine locuri\n");
		}
	}
	return 0;
}