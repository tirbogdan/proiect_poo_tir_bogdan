#include <iostream>
#include <iomanip>
#include <string>
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

class Locatie
{
	//to do:, mutata in proprul fisier header
private:
	string denumire;//
	string adresa;//
	string telefon;//
	int capacitate;//
	double pretInchiriere;//
	int nrSectoare;//
	char** denumireSector;//
	bool* contineLocuri;//
	int* nrRanduriPerSector;//
	int** nrLocuriPerRand;//
	int*** ocupareLocatie;//

public:
	Locatie()
	{
		this->denumire = "Invalid";
		this->adresa = "Invalid";
		this->telefon = "Nr invalid";
		this->capacitate = 0;
		this->pretInchiriere = 0;
		this->nrSectoare = 0;
		this->denumireSector = nullptr;
		this->contineLocuri = nullptr;
		this->nrRanduriPerSector = nullptr;
		this->nrLocuriPerRand = nullptr;
		this->ocupareLocatie = nullptr;
	}
	Locatie(string denumire, string adresa, string telefon, int capacitate, double pretInchiriere) : Locatie()
	{
		//Validare denumire
		if (denumire.length() >= 3 && denumire.length() <= 50)
		{
			this->denumire = denumire;
		}
		else
		{
			this->denumire = "Invalid";
		}
		//Validare adresa
		if (adresa.length() >= 3 && adresa.length() <= 100)
		{
			this->adresa = adresa;
		}
		else
		{
			this->adresa = "Invalid";
		}

		//Validare nr telefon
		if (telefon.length() != 10)
		{
			this->telefon = "Nr invalid";
		}
		else
		{
			
			bool telefonValid = true;
			for (int i = 0; i < 10; i++)
			{
				if (!isdigit(telefon[i])) telefonValid = false;
			}
			if (!telefonValid)
			{
				this->telefon = "Nr invalid";
			}
			else
			{
				this->telefon = telefon;
			}
		}

		//Validare capacitate
		if (capacitate < 0)
		{
			this->capacitate = 0;
		}
		else
		{
			this->capacitate = capacitate;
		}
		
		//Validare pretInchiriere
		if (pretInchiriere < 0)
		{
			this->pretInchiriere = 0;
		}
		else
		{
			this->pretInchiriere = pretInchiriere;
		}
	}

	//Setter si getter pentru denumire
	string getDenumire()
	{
		return this->denumire;
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() > 3 && denumire.length() < 50) this->denumire = denumire;
		else this->denumire = "Invalid";
	}

	//Setter si getter pentru adresa
	string getAdresa()
	{
		return this->adresa;
	}

	void setAdresa(string adresa)
	{
		if (adresa.length() > 3 && adresa.length() < 100) this->adresa = adresa;
		else this->adresa = "Invalid";
	}

	//Setter si getter pentru telefon
	string getTelefon()
	{
		return this->telefon;
	}

	void setTelefon(string telefon)
	{
		if (telefon.length() != 10)
		{
			this->telefon = "Nr invalid";

		}
		else
		{

			bool telefonValid = true;
			for (int i = 0; i < 10; i++)
			{
				if (!isdigit(telefon[i])) telefonValid = false;
			}
			if (!telefonValid)
			{
				this->telefon = "Nr invalid";
			}
			else
			{
				this->telefon = telefon;
			}
		}
	}

	//Setter si getter pentru capacitate
	int getCapacitate()
	{
		return this->capacitate;
	}

	void setCapacitate(int capacitate)
	{
		if (capacitate < 0) this->capacitate = 0;
		else this->capacitate = capacitate;
	}

	//Setter si getter pentru pretInchiriere
	double getPretInchiriere()
	{
		return this->pretInchiriere;
	}

	void setPretInchiriere(double pretInchiriere)
	{
		if (capacitate < 0) this->pretInchiriere = 0;
		else this->pretInchiriere = pretInchiriere;
	}

	//Setter si getter pentru nrSectoare
	int getNrSectoare()
	{
		return this->nrSectoare;
	}

	void setNrSectoare(int nrSectoare)
	{
		if (nrSectoare < 0) this->nrSectoare = 0;
		else this->nrSectoare = nrSectoare;
	}

	//Setter si getter pentru denumireSector
	char** getDenumireSector()
	{
		if (this->nrSectoare == 0 || this->denumireSector == nullptr) return nullptr;
		char** denumiri = new char*[this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			denumiri[i] = new char[strlen((this->denumireSector)[i]) + 1];
			strcpy(denumiri[i], (this->denumireSector)[i]);
		}
		return denumiri;
	}

	void setDenumireSector(char** denumireSector, int nrSectoare)
	{
		if (denumireSector != nullptr || nrSectoare > 0)
		{
			//Dezalocam ce avem deja in vectorul de denumiri al sectoarelor
			if (this->denumireSector != nullptr)
			{
				for (int i = 0; i < this->nrSectoare; i++)
				{
					delete[](this->denumireSector)[i];
				}
				delete[] this->denumireSector;
			}
			
			this->denumireSector = new char* [nrSectoare];
			for (int i = 0; i < nrSectoare; i++)
			{
				(this->denumireSector)[i] = new char[strlen(denumireSector[i]) + 1];
				strcpy((this->denumireSector)[i], denumireSector[i]);
			}
			this->nrSectoare = nrSectoare;
		}
	}

	//Setter si getter pentru contineLocuri
	bool* getContineLocuri()
	{
		if (this->contineLocuri == nullptr) return nullptr;
		bool* afisare = new bool[this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			afisare[i] = this->contineLocuri[i];
		}
		return afisare;
	}

	void setContineLocuri(bool* contineLocuri, int nrSectoare)
	{
		if (contineLocuri != nullptr && nrSectoare == this->nrSectoare)
		{
			if (this->contineLocuri != nullptr) 
				delete[] this->contineLocuri;

			this->contineLocuri = new bool[nrSectoare];
			for (int i = 0; i < nrSectoare; i++)
			{
				this->contineLocuri[i] = contineLocuri[i];
			}
		}
	}

	//Setter si getter pentru nrRanduriPerSector 
	int* getNrRanduriPerSector()
	{
		if (this->nrRanduriPerSector == nullptr || this->nrSectoare == 0) return nullptr;
		int* afisare = new int[this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			afisare[i] = this->nrRanduriPerSector[i];
		}
		return afisare;
	}

	void setNrRanduriPerSector(int* nrRanduriPerSector, int nrSectoare)
	{
		if (nrRanduriPerSector != nullptr && nrSectoare == this->nrSectoare)
		{
			if (this->nrRanduriPerSector != nullptr)
			{
				delete[] this->nrRanduriPerSector;
				this->nrRanduriPerSector = nullptr;
			}

			this->nrRanduriPerSector = new int[nrSectoare];
			for (int i = 0; i < nrSectoare; i++)
			{
				this->nrRanduriPerSector[i] = nrRanduriPerSector[i];
			}
		}
	}

	//Setter si getter pentru nrLocuriPerRand
	int** getNrLocuriPerRand()
	{
		if (this->nrSectoare == 0 || this->nrRanduriPerSector == nullptr || this->nrLocuriPerRand == nullptr) return nullptr;
		int** nrLocuriReturnate = new int* [this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			nrLocuriReturnate[i] = new int[this->nrRanduriPerSector[i]];
		}
		for (int i = 0; i < this->nrSectoare; i++)
		{
			for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
			{
				nrLocuriReturnate[i][j] = this->nrLocuriPerRand[i][j];
			}
		}
		return nrLocuriReturnate;
	}

	void setNrLocuriPerRand(int** nrLocuriPerRand, int* nrRanduriPerSector, int nrSectoare)
	{
		if (nrSectoare = this->nrSectoare && nrRanduriPerSector != nullptr && nrLocuriPerRand != nullptr)
		{
			bool nrRanduriCorect = true; // verificam daca sunt la fel de multe randuri per fiecare sector pentru a putea modifica numarul de locuri
			for (int i = 0; i < nrSectoare; i++)
			{
				if (this->nrRanduriPerSector[i] != nrRanduriPerSector[i]) nrRanduriCorect = false;
			}
			if (nrRanduriCorect)
			{
				if (this->nrLocuriPerRand != nullptr)
				{
					//dezalocam memoria doar daca avem ceva alocat
					for (int i = 0; i < this->nrSectoare; i++)
					{
						delete[] this->nrLocuriPerRand[i];
					}
					delete[] this->nrLocuriPerRand;
				}
				this->nrLocuriPerRand = new int* [nrSectoare];
				for (int i = 0; i < nrSectoare; i++)
				{
					this->nrLocuriPerRand[i] = new int[nrRanduriPerSector[i]];
				}
				for (int i = 0; i < nrSectoare; i++)
				{
					for (int j = 0; j < nrRanduriPerSector[i]; j++)
					{
						this->nrLocuriPerRand[i][j] = nrLocuriPerRand[i][j];
					}
				}
			}

		}

	}

	//Setter si getter pentru ocupareLocatie
	int*** getOcupareLocatie()
	{
		if (this->nrSectoare == 0 || this->nrRanduriPerSector == nullptr || this->nrLocuriPerRand == nullptr || this->ocupareLocatie == nullptr) return nullptr;
		
		int*** afisaj = new int** [this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			afisaj[i] = new int* [this->nrRanduriPerSector[i]];
		}
		for (int i = 0; i < this->nrSectoare; i++)
		{
			for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
			{
				afisaj[i][j] = new int[this->nrLocuriPerRand[i][j]];
			}
		}
		for (int i = 0; i < this->nrSectoare; i++)
		{
			for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
			{
				for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
				{
					afisaj[i][j][k] = this->ocupareLocatie[i][j][k];
				}
			}
		}
		return afisaj;
	}

	void setOcupareLocatie(int*** ocupareLocatie, int** nrLocuriPerRand, int* nrRanduriPerSector, int nrSectoare)
	{
		if (nrSectoare > 0 && nrRanduriPerSector != nullptr && nrLocuriPerRand != nullptr && ocupareLocatie != nullptr)
		{
			if (nrSectoare == this->nrSectoare)
			{
				bool nrCorect = true; 
				for (int i = 0; i < nrSectoare && nrCorect == true; i++)
				{
					if (this->nrRanduriPerSector[i] != nrRanduriPerSector[i]) nrCorect = false;
					for (int j = 0; j < this->nrRanduriPerSector[i] && nrCorect == true; j++)
					{
						if (this->nrLocuriPerRand[i][j] != nrLocuriPerRand[i][j]) nrCorect = false;
						for (int k = 0; k < this->nrLocuriPerRand[i][j] && nrCorect == true; k++)
						{
							if(ocupareLocatie[i][j][k] != 0 || ocupareLocatie[i][j][k] != 1) nrCorect = false;
						}
					}
				}
				if (nrCorect)
				{
					if (this->ocupareLocatie != nullptr)
					{
						//Dezalocam memoria doar daca avem ceva alocat

						for (int i = 0; i < nrSectoare; i++)
						{
							for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
							{
								delete[] this->ocupareLocatie[i][j];
							}
							delete[] this->ocupareLocatie[i];
						}
						delete[] this->ocupareLocatie;
					}
					//Alocam o noua zona de memorie pentru ocupareLocatie
					this->ocupareLocatie = new int** [nrSectoare];
					for (int i = 0; i < nrSectoare; i++)
					{
						this->ocupareLocatie[i] = new int* [nrRanduriPerSector[i]];
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							this->ocupareLocatie[i][j] = new int[this->nrLocuriPerRand[i][j]];
						}
					}

					//Copiem dintr-un vector in celalalt elementele
					for (int i = 0; i < nrSectoare; i++)
					{
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
							{
								this->ocupareLocatie[i][j][k] = ocupareLocatie[i][j][k];
							}
						}
					}
				}
			}
		}
	}

	//Constructorul de copiere
	Locatie(const Locatie& l)
	{
		this->denumire = l.denumire;
		this->adresa = l.adresa;
		this->telefon = l.telefon;
		this->capacitate = l.capacitate;
		this->pretInchiriere = l.pretInchiriere;
		this->nrSectoare = l.nrSectoare;

		//Copiere denumire sector
		if (l.denumireSector != nullptr || l.nrSectoare > 0)
		{
			this->denumireSector = new char* [l.nrSectoare];
			for (int i = 0; i < l.nrSectoare; i++)
			{
				(this->denumireSector)[i] = new char[strlen(l.denumireSector[i]) + 1];
				strcpy((this->denumireSector)[i], l.denumireSector[i]);
			}
		}
		else this->denumireSector = nullptr;
		//Copiere contineLocuri
		if (l.contineLocuri != nullptr && l.nrSectoare == this->nrSectoare)
		{
			this->contineLocuri = new bool[l.nrSectoare];
			for (int i = 0; i < l.nrSectoare; i++)
			{
				this->contineLocuri[i] = l.contineLocuri[i];
			}
		}
		else this->contineLocuri = nullptr;
		//Copiere nrRanduriPerSector
		if (l.nrRanduriPerSector != nullptr && l.contineLocuri != nullptr)
		{
			this->nrRanduriPerSector = new int[l.nrSectoare];
			for (int i = 0; i < l.nrSectoare; i++)
			{
				this->nrRanduriPerSector[i] = l.nrRanduriPerSector[i];
			}
		}
		else this->nrRanduriPerSector = nullptr;
		//Copiere nrLocuriPerRand
		if (l.nrLocuriPerRand != nullptr && l.contineLocuri != nullptr)
		{
			this->nrLocuriPerRand = new int* [l.nrSectoare];
			for (int i = 0; i < l.nrSectoare; i++)
			{
				if (l.contineLocuri[i] != 0)
				{
					this->nrLocuriPerRand[i] = new int[l.nrRanduriPerSector[i]];
					for (int j = 0; j < l.nrRanduriPerSector[i]; j++)
					{
						this->nrLocuriPerRand[i][j] = l.nrLocuriPerRand[i][j];
					}
				}
				
			}
		}
		else this->nrLocuriPerRand = nullptr;

		//Copiere ocupareLocatie
		if (l.nrSectoare > 0 && l.nrRanduriPerSector != nullptr && l.nrLocuriPerRand != nullptr && l.ocupareLocatie != nullptr && l.contineLocuri != nullptr)
		{
				//Alocam o noua zona de memorie pentru ocupareLocatie
				this->ocupareLocatie = new int** [l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					if (l.contineLocuri[i] != 0)
					{
						this->ocupareLocatie[i] = new int* [l.nrRanduriPerSector[i]];
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							this->ocupareLocatie[i][j] = new int[l.nrLocuriPerRand[i][j]];
						}
					}
				}

				//Copiem dintr-un vector in celalalt elementele
				for (int i = 0; i < this->nrSectoare; i++)
				{
					for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
					{
						for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
						{
							this->ocupareLocatie[i][j][k] = l.ocupareLocatie[i][j][k];
						}
					}
				}
		}
		else this->ocupareLocatie = nullptr;
	}

	~Locatie()
	{
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < nrSectoare; i++)
			{
				if (this->contineLocuri[i] != 0)
				{
					for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
					{
						delete[] this->ocupareLocatie[i][j];
					}
					delete[] this->ocupareLocatie[i];
				}
			}
			delete[] this->ocupareLocatie;
			this->ocupareLocatie = nullptr;
		}

		if (this->nrLocuriPerRand != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
			{
				if (this->contineLocuri[i] != 0)
				{
					delete[] this->nrLocuriPerRand[i];
				}
			}
			delete[] this->nrLocuriPerRand;
			this->nrLocuriPerRand = nullptr;
		}

		if (this->nrRanduriPerSector != nullptr)
		{
			delete[] this->nrRanduriPerSector;
			this->nrRanduriPerSector = nullptr;
		}

		if (this->denumireSector != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
			{
				delete[](this->denumireSector)[i];
			}
			delete[] this->denumireSector;
			this->denumireSector = nullptr;
		}

		if (this->contineLocuri != nullptr)
		{
			delete[] this->contineLocuri;
			this->contineLocuri = nullptr;
		}
	}

	//Create operator=
	Locatie& operator=(const Locatie& l)
	{
		if (this != &l)
		{
			this->denumire = l.denumire;
			this->adresa = l.adresa;
			this->telefon = l.telefon;
			this->capacitate = l.capacitate;
			this->pretInchiriere = l.pretInchiriere;
			this->nrSectoare = l.nrSectoare;

			//Copiere denumire sector
			if (l.denumireSector != nullptr || l.nrSectoare > 0)
			{
				//Dezalocam ce avem deja in vectorul de denumiri al sectoarelor
				if (this->denumireSector != nullptr)
				{
					for (int i = 0; i < this->nrSectoare; i++)
					{
						delete[](this->denumireSector)[i];
					}
					delete[] this->denumireSector;
				}
				
				this->denumireSector = new char* [l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					(this->denumireSector)[i] = new char[strlen(l.denumireSector[i]) + 1];
					strcpy((this->denumireSector)[i], l.denumireSector[i]);
				}
			}
			else this->denumireSector = nullptr;
			//Copiere contineLocuri
			if (l.contineLocuri != nullptr && l.nrSectoare == this->nrSectoare)
			{
				if (this->contineLocuri != nullptr)
					delete[] this->contineLocuri;
				
				this->contineLocuri = new bool[l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					this->contineLocuri[i] = l.contineLocuri[i];
				}
			}
			else this->contineLocuri = nullptr;
			//Copiere nrRanduriPerSector
			if (l.nrRanduriPerSector != nullptr)
			{
				if (this->nrRanduriPerSector != nullptr)
				{
					delete[] this->nrRanduriPerSector;
					this->nrRanduriPerSector = nullptr;
				}
				
				this->nrRanduriPerSector = new int[l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					this->nrRanduriPerSector[i] = l.nrRanduriPerSector[i];
				}
			}
			else this->nrRanduriPerSector = nullptr;
			//Copiere nrLocuriPerRand
			if (l.nrRanduriPerSector != nullptr && l.nrLocuriPerRand != nullptr)
			{
				if (this->nrLocuriPerRand != nullptr)
				{
					//dezalocam memoria doar daca avem ceva alocat
					for (int i = 0; i < this->nrSectoare; i++)
					{
						delete[] this->nrLocuriPerRand[i];
					}
					delete[] this->nrLocuriPerRand;
				}
				
				this->nrLocuriPerRand = new int* [l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					this->nrLocuriPerRand[i] = new int[l.nrRanduriPerSector[i]];
				}
				for (int i = 0; i < l.nrSectoare; i++)
				{
					for (int j = 0; j < l.nrRanduriPerSector[i]; j++)
					{
						this->nrLocuriPerRand[i][j] = l.nrLocuriPerRand[i][j];
					}
				}
			}
			else this->nrLocuriPerRand = nullptr;
			//Copiere ocupareLocatie
			if (l.nrSectoare > 0 && l.nrRanduriPerSector != nullptr && l.nrLocuriPerRand != nullptr && l.ocupareLocatie != nullptr)
			{
				if (this->ocupareLocatie != nullptr)
				{
					//Dezalocam memoria doar daca avem ceva alocat

					for (int i = 0; i < nrSectoare; i++)
					{
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							delete[] this->ocupareLocatie[i][j];
						}
						delete[] this->ocupareLocatie[i];
					}
					delete[] this->ocupareLocatie;
				}
				
				//Alocam o noua zona de memorie pentru ocupareLocatie
				this->ocupareLocatie = new int** [l.nrSectoare];
				for (int i = 0; i < l.nrSectoare; i++)
				{
					this->ocupareLocatie[i] = new int* [l.nrRanduriPerSector[i]];
					for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
					{
						this->ocupareLocatie[i][j] = new int[l.nrLocuriPerRand[i][j]];
					}
				}

				//Copiem dintr-un vector in celalalt elementele
				for (int i = 0; i < this->nrSectoare; i++)
				{
					for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
					{
						for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
						{
							this->ocupareLocatie[i][j][k] = l.ocupareLocatie[i][j][k];
						}
					}
				}
			}
			else this->ocupareLocatie = nullptr;
		}
		return *this;
	}

	//2 operatori supraincarcati
	
	//Operatorii relationari	
	//Operatorul >
	bool operator>(const Locatie& l)
	{
		//verifica daca o locatie este mai incapatoare decat alta
		if (this->capacitate > l.capacitate)
			return true;
		else return false;
	}
	//Operatorul <
	bool operator<(const Locatie& l)
	{
		//verifica daca o locatie este mai putin incapatoare decat alta
		if (this->capacitate < l.capacitate)
			return true;
		else return false;
	}
	//Operatorul >=
	bool operator>=(const Locatie& l)
	{
		//verifica daca o locatie este mai incapatoare sau egala cu alta
		if (this->capacitate >= l.capacitate)
			return true;
		else return false;
	}
	//Operatorul <=
	bool operator<=(const Locatie& l)
	{
		//verifica daca o locatie este mai putin incapatoare sau egala cu alta
		if (this->capacitate <= l.capacitate)
			return true;
		else return false;
	}
	//Operatorul ==
	bool operator==(const Locatie& l)
	{
		//verifica daca o locatie are aceeasi capacitate cu alta
		if (this->capacitate == l.capacitate)
			return true;
		else return false;
	}

	//Operatorul ++ preincrementare
	Locatie& operator++()
	{
		//incrementam capacitatea cu 1
		this->capacitate++;
		return *this;
	}
	//Operatorul ++ postincrementare
	Locatie operator++(int)
	{
		//incrementam capacitatea cu 1
		Locatie copie = *this;
		this->capacitate++;
		return copie;
	}
	
	//2 Metode generice
	
	void elibereazaSala()
	{
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
			{
				for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
				{
					for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
					{
						this->ocupareLocatie[i][j] = 0;
					}
				}
			}
		}
	}
	
	void aseazaOmPeLoc(int sector, int, int rand, int loc)
	{
		if (sector > 0 && sector <= this->nrSectoare && rand > 0 && rand <= this->nrRanduriPerSector[sector] && loc > 0 && loc <= this->nrLocuriPerRand[sector][rand])
		{
			this->ocupareLocatie[sector][rand][loc] = 1;
		}
	}
	
	//Citire si Afisare
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);

};

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Locatia cu denumirea " << l.denumire << " se afla la adresa " << l.adresa;
	out << "\nAceasta poate fi inchiriata pentru " << setprecision(2) << fixed << l.pretInchiriere << " de lei pe zi";
	out << "\nLocatia are capacitatea de " << l.capacitate << " locuri impartite in " << l.nrSectoare << " sectiuni\n";
	if (l.nrSectoare != 0 && l.denumireSector != nullptr)
	{
		for (int i = 0; i < l.nrSectoare; i++)
		{
			if (l.contineLocuri == nullptr)
			{
				out << "Sectiunea " << l.denumireSector[i] << endl;
			}
			else
			{
				out << "Sectiunea " << l.denumireSector[i] << (l.contineLocuri[i] == true ? " are " : " nu are ") << "locuri numerotate in care oamenii sa se aseze";
				if (l.contineLocuri[i])
				{
					out << "\nAcestea sunt dispuse astfel(0 inseamna scaun gol, 1 scaun ocupat):\n";
					for (int j = 0; j < l.nrRanduriPerSector[i]; j++)
					{
						for (int k = 0; k < l.nrLocuriPerRand[i][j]; k++)
						{
							out << l.ocupareLocatie[i][j][k] << " ";
						}
						out << "\n";
					}
				}
			}
		}

		
	}
	out << "Pentru alte detalii sunati la numarul " << l.telefon <<endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	bool valid = false;
	while (valid == false)
	{
		cout << "Introduceti denumirea locatiei: ";
		getline(in, l.denumire);
		if (l.denumire.length() >= 3 && l.denumire.length() <= 50)
		{
			valid = true;
		}
		else
		{
			cout << "Denumirea trebuie sa aiba intre 3 si 50 de caractere\n";
		}
	}
	valid = false;
	while (valid == false)
	{
		cout << "Introduceti adresa locatiei: ";
		getline(in, l.adresa);
		if (l.adresa.length() >= 3 && l.adresa.length() <= 100)
		{
			valid = true;
		}
		else
		{
			cout << "Adresa trebuie sa aiba intre 3 si 50 de caractere\n";
		}
	}
	valid = false;
	while (valid == false)
	{
		cout << "Introduceti numarul de telefon al locatiei: ";
		getline(in, l.telefon);
		if (l.telefon.length() == 10)
		{
			bool telefonValid = true;
			for (int i = 0; i < 10; i++)
			{
				if (!isdigit(l.telefon[i])) telefonValid = false;
			}
			if (telefonValid)
			{
				valid = true;
			}
			else
			{
				cout << "Numarul de telefon trebuie sa contina doar cifre\n";
			}
		}
		else
		{
			cout << "Numarul de telefon trebuie sa aiba 10 cifre\n";
		}
	}
	valid = false;
	while (valid == false)
	{
		cout << "Introduceti pretul de inchiriere al locatiei: ";
		in >> l.pretInchiriere;
		if (l.pretInchiriere > 0)
		{
			valid = true;
		}
		else
		{
			cout << "Pretul de inchiriere trebuie sa fie un numar pozitiv\n";
		}
	}
	valid = false;
	while (valid == false)
	{
		cout << "Introduceti capacitatea locatiei: ";
		in >> l.capacitate;
		if (l.capacitate > 0)
		{
			valid = true;
		}
		else
		{
			cout << "Capacitatea trebuie sa fie un numar pozitiv\n";
		}
	}
	valid = false;

	//Dezalocam memoria daca avem ceva alocat
	if (l.denumireSector != nullptr)
	{
		for (int i = 0; i < l.nrSectoare; i++)
		{
			delete[] l.denumireSector[i];
		}
		delete[] l.denumireSector;
	}

	if (l.contineLocuri != nullptr)
	{
		delete[] l.contineLocuri;
	}

	if (l.ocupareLocatie != nullptr)
	{
		for (int i = 0; i < l.nrSectoare; i++)
		{
			for (int j = 0; j < l.nrRanduriPerSector[i]; j++)
			{
				delete[] l.ocupareLocatie[i][j];
			}
			delete[] l.ocupareLocatie[i];
		}
		delete[] l.ocupareLocatie;
	}

	if (l.nrLocuriPerRand != nullptr)
	{
		for (int i = 0; i < l.nrSectoare; i++)
		{
			delete[] l.nrLocuriPerRand[i];
		}
		delete[] l.nrLocuriPerRand;
	}

	if (l.nrRanduriPerSector != nullptr)
	{
		delete[] l.nrRanduriPerSector;
	}

	while (valid == false)
	{
		cout << "Introduceti numarul de sectiuni al locatiei: ";
		in >> l.nrSectoare;
		if (l.nrSectoare > 0)
		{
			valid = true;
		}
		else
		{
			cout << "Numarul de sectiuni trebuie sa fie un numar pozitiv\n";
		}
	}
	valid = false;
	if (l.nrSectoare != 0)
	{
		
		//Alocam memoria pentru celelalte campuri
		l.denumireSector = new char* [l.nrSectoare];
		l.contineLocuri = new bool[l.nrSectoare];
		l.nrRanduriPerSector = new int[l.nrSectoare];
		l.nrLocuriPerRand = new int* [l.nrSectoare];
		l.ocupareLocatie = new int** [l.nrSectoare];
		for (int i = 0; i < l.nrSectoare; i++)
		{
			cout << "Introduceti denumirea sectiunii " << i << ": ";
			char buffer[100];
			in.get();
			in.getline(buffer, 100, '\n');
			l.denumireSector[i] = new char[strlen(buffer) + 1];
			strcpy(l.denumireSector[i], buffer);
			cout << "Introduceti daca sectiunea " << i << " contine locuri (1 - da, 0 - nu): ";
			while (valid == false)
			{
				int raspuns;
				in >> raspuns;
				if ((raspuns == 0 || raspuns == 1))
				{
					if (raspuns == 0) l.contineLocuri[i] = false;
					else l.contineLocuri[i] = true;
					valid = true;
				}
				else
				{
					cout << "Optiunea trebuie sa fie 1 sau 0" << endl;
					in.clear();
				}

			}
			valid = false;
			
			if (l.contineLocuri[i] == 1)
			{
				cout << "Introduceti numarul de randuri: ";
				in >> l.nrRanduriPerSector[i];
				l.nrLocuriPerRand[i] = new int[l.nrRanduriPerSector[i]];
				l.ocupareLocatie[i] = new int* [l.nrRanduriPerSector[i]];
				for (int j = 0; j < l.nrRanduriPerSector[i]; j++)
				{
					cout << "Introduceti numarul de locuri pe randul " << j << ": ";
					in >> l.nrLocuriPerRand[i][j];
					l.ocupareLocatie[i][j] = new int[l.nrLocuriPerRand[i][j]];
					for (int k = 0; k < l.nrLocuriPerRand[i][j]; k++)
					{
						l.ocupareLocatie[i][j][k] = 0;
					}
				}
			}
		}
	}
	return in;
}

int main()
{
	//Testare functionalitati
	/*
	Locatie l;
	string loc = "buftea";
	string adresa = "str mare din bucuresti";
	string telefon = "0770103861";
	Locatie l1(loc, adresa, telefon, 500, 12313.95);
	char** zone = nullptr;
	zone = new char* [3];
	zone[0] = new char[strlen("Peluza A") + 1];
	zone[1] = new char[strlen("Peluza B") + 1];
	zone[2] = new char[strlen("Peluza C") + 1];
	strcpy(zone[0], "Peluza A");
	strcpy(zone[1], "Peluza B");
	strcpy(zone[2], "Peluza C");
	
	l1.setDenumireSector(zone, 3);
	Locatie l2;
	l2 = l = l1;
	l.setCapacitate(100);
	l2.setCapacitate(200);

	cin >> l;
	cout << endl << l;
	

	Bilet b;
	cout << b << endl;
	cin >> b;
	cout << endl << b << endl;
	cout << (string)b << endl;
	
	
	cout << Bilet::creareCodUnic() << endl;
	cout << Bilet::creareCodUnic() << endl;
	*/

	Eveniment e;
	//cin >> e;
	//cout << endl << e;
	cout << e + 100 << endl;
	cout << 99 + e << endl;
	
	return 0;
}

//to do pentru urmatoarea etapa
/*
--de implementat clasele in fisiere separate
--de modificat logica de la setterii pentru locatii
--de adaugat un vector de locatii si unul de bilete in eveniment
*/