#include "Locatie.h"
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

Locatie::Locatie()
{
	this->parolaAdministratorSala = "Admin";
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

Locatie::Locatie(string denumire, string adresa, string telefon, int capacitate, double pretInchiriere, string parolaAdministratorSala) : Locatie()
{
	//Validare parola
	if (parolaAdministratorSala.length() < 8)
	{
		cout << "Parola trebuie sa contina minim 8 caractere!" << endl;
		return;
	}
	else
	{
		this->parolaAdministratorSala = parolaAdministratorSala;
	}
	
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

//Setter si getter pentru parolaAdministratorSala
string Locatie::getParolaAdministratorSala()
{
	return this->parolaAdministratorSala;
}

void Locatie::setParolaAdministratorSala(string parolaAdministratorSala)
{
	if (parolaAdministratorSala.length() < 8)
	{
		cout << "Parola trebuie sa contina minim 8 caractere!" << endl;
		return;
	}
	else
	{
		this->parolaAdministratorSala = parolaAdministratorSala;
	}
}

//Setter si getter pentru denumire
string Locatie::getDenumire()
{
	return this->denumire;
}

void Locatie::setDenumire(string denumire)
{
	if (denumire.length() > 3 && denumire.length() < 50) 
		this->denumire = denumire;
	//Doresc sa schimb denumirea locatiei doar daca e o denumire valida pentru a nu pierde date in cazul in care se schimba cu o denumire invalida.
}

//Setter si getter pentru adresa
string Locatie::getAdresa()
{
	return this->adresa;
}

void Locatie::setAdresa(string adresa)
{
	if (adresa.length() > 3 && adresa.length() < 100) 
		this->adresa = adresa;
	//Doresc sa schimb adresa doar daca e o denumire valida pentru a nu pierde date in cazul in care se schimba cu o adresa invalida.
}

//Setter si getter pentru telefon
string Locatie::getTelefon()
{
	return this->telefon;
}

void Locatie::setTelefon(string telefon)
{
	if (telefon.length() == 10)
	{
		bool telefonValid = true;
		for (int i = 0; i < 10; i++)
			if (!isdigit(telefon[i])) 
				telefonValid = false;
		if (telefonValid)
			this->telefon = telefon;
	}
}

//Setter si getter pentru capacitate
int Locatie::getCapacitate()
{
	return this->capacitate;
}

void Locatie::setCapacitate(int capacitate)
{
	if (capacitate >= 0)
		this->capacitate = capacitate;
}

//Setter si getter pentru pretInchiriere
double Locatie::getPretInchiriere()
{
	return this->pretInchiriere;
}

void Locatie::setPretInchiriere(double pretInchiriere)
{
	if (capacitate >= 0)
		this->pretInchiriere = pretInchiriere;
}

//Setter si getter pentru nrSectoare
int Locatie::getNrSectoare()
{
	return this->nrSectoare;
}

void Locatie::setNrSectoare(int nrSectoare) 
{
	if (nrSectoare >= 0)
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

		this->nrSectoare = nrSectoare;
	}
}

//Setter si getter pentru denumireSector
char** Locatie::getDenumireSector()
{
	if (this->nrSectoare == 0 || this->denumireSector == nullptr) return nullptr;
	char** denumiri = new char* [this->nrSectoare];
	for (int i = 0; i < this->nrSectoare; i++)
	{
		denumiri[i] = new char[strlen((this->denumireSector)[i]) + 1];
		strcpy(denumiri[i], (this->denumireSector)[i]);
	}
	return denumiri;
}

void Locatie::setDenumireSector(char** denumireSector, int sectorRedenumit, char* denumireNoua)
{
	if (denumireSector != nullptr)
	{
		if (this->denumireSector != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
			{
				delete[](this->denumireSector)[i];
			}
			delete[] this->denumireSector;
			this->denumireSector = nullptr;
		}

		this->denumireSector = new char* [this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			(this->denumireSector)[i] = new char[strlen(denumireSector[i]) + 1];
			strcpy((this->denumireSector)[i], denumireSector[i]);
		}
	}
	else if (sectorRedenumit != -1 && denumireNoua != nullptr)
	{
		if (sectorRedenumit >= 0 && sectorRedenumit < this->nrSectoare)
		{
			delete[](this->denumireSector)[sectorRedenumit];
			(this->denumireSector)[sectorRedenumit] = new char[strlen(denumireNoua) + 1];
			strcpy((this->denumireSector)[sectorRedenumit], denumireNoua);
		}
	}
}

//Setter si getter pentru contineLocuri
bool* Locatie::getContineLocuri()
{
	if (this->contineLocuri == nullptr) return nullptr;
	bool* afisare = new bool[this->nrSectoare];
	for (int i = 0; i < this->nrSectoare; i++)
	{
		afisare[i] = this->contineLocuri[i];
	}
	return afisare;
}

void Locatie::setContineLocuri(bool* contineLocuri, int schimbareStareSector)
{
	if (contineLocuri != nullptr)
	{
		//dezalocam ocuparea locatiei
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
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
		//dezalocam nrLocuriPerRand
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
		//dezalocam nrRanduriPerSector
		if (this->nrRanduriPerSector != nullptr)
		{
			delete[] this->nrRanduriPerSector;
			this->nrRanduriPerSector = nullptr;
		}
		
		if (this->contineLocuri != nullptr)
		{
			delete[] this->contineLocuri;
			this->contineLocuri = nullptr;
		}

		this->contineLocuri = new bool[this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			this->contineLocuri[i] = contineLocuri[i];
		}
	}
	else if (schimbareStareSector != -1)
	{
		if (schimbareStareSector >= 0 && schimbareStareSector < this->nrSectoare)
		{
			//dezalocam ocuparea locatiei pentru sectorul respectiv
			if (this->ocupareLocatie != nullptr)
			{
					if (this->contineLocuri[schimbareStareSector] != 0)
					{
						for (int i = 0; i < this->nrRanduriPerSector[schimbareStareSector]; i++)
						{
							delete[] this->ocupareLocatie[schimbareStareSector][i];
						}
						delete[] this->ocupareLocatie[schimbareStareSector];
					}
				delete[] this->ocupareLocatie;
				this->ocupareLocatie = nullptr;
			}
			
			//dezalocam nrLocuriPerRand pentru sectorul respectiv
			if (this->nrLocuriPerRand != nullptr)
			{
				if (this->contineLocuri[schimbareStareSector] != 0)
				{
					delete[] this->nrLocuriPerRand[schimbareStareSector];
				}
				delete[] this->nrLocuriPerRand;
				this->nrLocuriPerRand = nullptr;
			}
			if (this->nrRanduriPerSector != nullptr)
			{
				this->nrRanduriPerSector[schimbareStareSector] = 0;
			}
			

			this->contineLocuri[schimbareStareSector] = !this->contineLocuri[schimbareStareSector];
		}
	}
}

//Setter si getter pentru nrRanduriPerSector 
int* Locatie::getNrRanduriPerSector()
{
	if (this->nrRanduriPerSector == nullptr || this->nrSectoare == 0) return nullptr;
	int* afisare = new int[this->nrSectoare];
	for (int i = 0; i < this->nrSectoare; i++)
	{
		afisare[i] = this->nrRanduriPerSector[i];
	}
	return afisare;
}

void Locatie::setNrRanduriPerSector(int* nrRanduriPerSector, int sectorModificat, int nrRanduriNou)
{
	if (nrRanduriPerSector != nullptr)
	{
		//dezalocam ocuparea locatiei
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
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
		//dezalocam nrLocuriPerRand
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
		//dezalocam nrRanduriPerSector
		if (this->nrRanduriPerSector != nullptr)
		{
			delete[] this->nrRanduriPerSector;
			this->nrRanduriPerSector = nullptr;
		}

		this->nrRanduriPerSector = new int[this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			if (this->contineLocuri[i] == 1)
				this->nrRanduriPerSector[i] = nrRanduriPerSector[i];
			else
				this->nrRanduriPerSector[i] = 0;
		}
	}
	else if (sectorModificat != -1)
	{
		if (sectorModificat >= 0 && sectorModificat < this->nrSectoare)
		{
			//dezalocam ocuparea locatiei pentru sectorul respectiv
			if (this->ocupareLocatie != nullptr)
			{
				if (this->contineLocuri[sectorModificat] != 0)
				{
					for (int i = 0; i < this->nrRanduriPerSector[sectorModificat]; i++)
					{
						delete[] this->ocupareLocatie[sectorModificat][i];
					}
					delete[] this->ocupareLocatie[sectorModificat];
				}
				delete[] this->ocupareLocatie;
				this->ocupareLocatie = nullptr;
			}
			//dezalocam nrLocuriPerRand pentru sectorul respectiv
			if (this->nrLocuriPerRand != nullptr)
			{
				if (this->contineLocuri[sectorModificat] != 0)
				{
					delete[] this->nrLocuriPerRand[sectorModificat];
				}
				delete[] this->nrLocuriPerRand;
				this->nrLocuriPerRand = nullptr;
			}
			if (this->nrRanduriPerSector != nullptr)
			{
				this->nrRanduriPerSector[sectorModificat] = nrRanduriNou;
			}
			else
			{
				this->nrRanduriPerSector = new int[this->nrSectoare];
				for (int i = 0; i < this->nrSectoare; i++)
				{
					this->nrRanduriPerSector[i] = 0;
				}
				this->nrRanduriPerSector[sectorModificat] = nrRanduriNou;
			}
		}
	}
}

//Setter si getter pentru nrLocuriPerRand
int** Locatie::getNrLocuriPerRand()
{
	if (this->nrLocuriPerRand == nullptr || this->nrSectoare == 0) return nullptr;
	int** afisare = new int* [this->nrSectoare];
	for (int i = 0; i < this->nrSectoare; i++)
	{
		if (this->contineLocuri[i] == 1)
		{
			afisare[i] = new int[this->nrRanduriPerSector[i]];
			for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
			{
				afisare[i][j] = this->nrLocuriPerRand[i][j];
			}
		}
		else
		{
			afisare[i] = nullptr;
		}
	}
	return afisare;
}

void Locatie::setNrLocuriPerRand(int** nrLocuriPerRand, int sectorModificat, int randModificat, int nrLocuriNou)
{
	if (nrLocuriPerRand != nullptr)
	{
		//dezalocam ocuparea locatiei
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
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
		//dezalocam nrLocuriPerRand
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

		this->nrLocuriPerRand = new int* [this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			if (this->contineLocuri[i] == 1)
			{
				this->nrLocuriPerRand[i] = new int[this->nrRanduriPerSector[i]];
				for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
				{
					this->nrLocuriPerRand[i][j] = nrLocuriPerRand[i][j];
				}
			}
			else
			{
				this->nrLocuriPerRand[i] = nullptr;
			}
		}
	}
	else
	{
		if (sectorModificat >= 0 && sectorModificat < this->nrSectoare && randModificat >= 0 && randModificat < this->nrRanduriPerSector[sectorModificat] && this->contineLocuri[sectorModificat] == 1)
		{
			if (this->nrLocuriPerRand != nullptr)
			{
				this->nrLocuriPerRand[sectorModificat][randModificat] = nrLocuriNou;
			}
			else
			{
				this->nrLocuriPerRand = new int* [this->nrSectoare];
				for (int i = 0; i < this->nrSectoare; i++)
				{
					if (this->contineLocuri[i] == 1)
					{
						this->nrLocuriPerRand[i] = new int[this->nrRanduriPerSector[i]];
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							this->nrLocuriPerRand[i][j] = 0;
						}
					}
					else
					{
						this->nrLocuriPerRand[i] = nullptr;
					}
				}
				this->nrLocuriPerRand[sectorModificat][randModificat] = nrLocuriNou;
			}
		}
	}
}

//Setter si getter pentru ocupareLocatie
int*** Locatie::getOcupareLocatie()
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

void Locatie::setOcupareLocatie(int*** ocupareLocatie, int sectorModificat, int randModificat, int locModificat, int stareNoua)
{
	if (ocupareLocatie != nullptr)
	{
		//dezalocam ocuparea locatiei
		if (this->ocupareLocatie != nullptr)
		{
			for (int i = 0; i < this->nrSectoare; i++)
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
		
		this->ocupareLocatie = new int** [this->nrSectoare];
		for (int i = 0; i < this->nrSectoare; i++)
		{
			if (this->contineLocuri[i] == 1)
			{
				this->ocupareLocatie[i] = new int* [this->nrRanduriPerSector[i]];
				for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
				{
					this->ocupareLocatie[i][j] = new int[this->nrLocuriPerRand[i][j]];
					for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
					{
						this->ocupareLocatie[i][j][k] = ocupareLocatie[i][j][k];
					}
				}
			}
			else
			{
				this->ocupareLocatie[i] = nullptr;
			}
		}
	}
	else
	{
		if (sectorModificat >= 0 && sectorModificat < this->nrSectoare && randModificat >= 0 && randModificat < this->nrRanduriPerSector[sectorModificat] && locModificat >= 0 && locModificat < this->nrLocuriPerRand[sectorModificat][randModificat] && this->contineLocuri[sectorModificat] == 1)
		{
			if (this->ocupareLocatie != nullptr)
			{
				this->ocupareLocatie[sectorModificat][randModificat][locModificat] = stareNoua;
			}
			else
			{
				this->ocupareLocatie = new int** [this->nrSectoare];
				for (int i = 0; i < this->nrSectoare; i++)
				{
					if (this->contineLocuri[i] == 1)
					{
						this->ocupareLocatie[i] = new int* [this->nrRanduriPerSector[i]];
						for (int j = 0; j < this->nrRanduriPerSector[i]; j++)
						{
							this->ocupareLocatie[i][j] = new int[this->nrLocuriPerRand[i][j]];
							for (int k = 0; k < this->nrLocuriPerRand[i][j]; k++)
							{
								this->ocupareLocatie[i][j][k] = 0;
							}
						}
					}
					else
					{
						this->ocupareLocatie[i] = nullptr;
					}
				}
				this->ocupareLocatie[sectorModificat][randModificat][locModificat] = stareNoua;
			}
		}
	}
}

//Constructorul de copiere
Locatie::Locatie(const Locatie& l)
{
	this->parolaAdministratorSala = l.parolaAdministratorSala;
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

//Destructor
Locatie::~Locatie()
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

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		this->parolaAdministratorSala = l.parolaAdministratorSala;
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
		
//Operatorii relationari	
	//Operatorul >
bool Locatie::operator>(const Locatie& l)
{
	//verifica daca o locatie este mai incapatoare decat alta
	if (this->capacitate > l.capacitate)
		return true;
	else return false;
}
//Operatorul <
bool Locatie::operator<(const Locatie& l)
{
	//verifica daca o locatie este mai putin incapatoare decat alta
	if (this->capacitate < l.capacitate)
		return true;
	else return false;
}
//Operatorul >=
bool Locatie::operator>=(const Locatie& l)
{
	//verifica daca o locatie este mai incapatoare sau egala cu alta
	if (this->capacitate >= l.capacitate)
		return true;
	else return false;
}
//Operatorul <=
bool Locatie::operator<=(const Locatie& l)
{
	//verifica daca o locatie este mai putin incapatoare sau egala cu alta
	if (this->capacitate <= l.capacitate)
		return true;
	else return false;
}
//Operatorul ==
bool Locatie::operator==(const Locatie& l)
{
	//verifica daca o locatie are aceeasi capacitate cu alta
	if (this->capacitate == l.capacitate)
		return true;
	else return false;
}

//Operatorul ++ preincrementare
Locatie& Locatie::operator++()
{
	//incrementam capacitatea cu 1
	this->capacitate++;
	return *this;
}
//Operatorul ++ postincrementare
Locatie Locatie::operator++(int)
{
	//incrementam capacitatea cu 1
	Locatie copie = *this;
	this->capacitate++;
	return copie;
}

void Locatie::elibereazaSala()
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

int Locatie::verificaParola(string parola)
{
	if (parola == this->parolaAdministratorSala)
		return 1;
	else return 0;
}


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
	out << "Pentru alte detalii sunati la numarul " << l.telefon << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	bool valid = false;
	while (valid = false)
	{
		cout << "Introduceti parola pe care o doriti: ";
		getline(in, l.parolaAdministratorSala);
		if (l.parolaAdministratorSala.length() >= 8)
		{
			valid = true;
		}
		else cout << "Parola trebuie sa contina minim 8 caractere\n";
	}
	valid = false;
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