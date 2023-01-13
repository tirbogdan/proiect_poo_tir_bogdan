#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

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
	Locatie();
	Locatie(string denumire, string adresa, string telefon, int capacitate, double pretInchiriere);
	

	//Setter si getter pentru denumire
	string getDenumire();
	void setDenumire(string denumire);

	//Setter si getter pentru adresa
	string getAdresa();
	void setAdresa(string adresa);

	//Setter si getter pentru telefon
	string getTelefon();
	void setTelefon(string telefon);

	//Setter si getter pentru capacitate
	int getCapacitate();
	void setCapacitate(int capacitate);

	//Setter si getter pentru pretInchiriere
	double getPretInchiriere();
	void setPretInchiriere(double pretInchiriere);

	//Setter si getter pentru nrSectoare
	int getNrSectoare();
	void setNrSectoare(int nrSectoare);

	//Setter si getter pentru denumireSector
	char** getDenumireSector();
	void setDenumireSector(char** denumireSector, int sectorRedenumit = -1, char* denumireNoua = nullptr);
	

	//Setter si getter pentru contineLocuri
	bool* getContineLocuri();
	void setContineLocuri(bool* contineLocuri, int schimbareStareSector = -1);

	//Setter si getter pentru nrRanduriPerSector 
	int* getNrRanduriPerSector();
	void setNrRanduriPerSector(int* nrRanduriPerSector, int sectorModificat = -1, int nrRanduriNou = -1);

	//Setter si getter pentru nrLocuriPerRand
	int** getNrLocuriPerRand();
	void setNrLocuriPerRand(int** nrLocuriPerRand, int sectorModificat = -1, int randModificat = -1, int nrLocuriNou = -1);

	//Setter si getter pentru ocupareLocatie
	int*** getOcupareLocatie();
	void setOcupareLocatie(int*** ocupareLocatie, int sectorModificat = -1, int randModificat = -1, int locModificat = -1, int stareNoua = -1);

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



