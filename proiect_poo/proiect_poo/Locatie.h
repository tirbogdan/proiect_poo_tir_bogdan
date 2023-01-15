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
	string parolaAdministratorSala;
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
	Locatie(string denumire, string adresa, string telefon, int capacitate, double pretInchiriere, string parolaAdministratorSala = "Admin");
	
	//Setter si getter pentru parolaAdministratorSala
	string getParolaAdministratorSala();
	void setParolaAdministratorSala(string parolaAdministratorSala);
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
	Locatie(const Locatie& l);
	

	~Locatie();

	//Create operator=
	Locatie& operator=(const Locatie& l);

	//2 operatori supraincarcati

	//Operatorii relationari	
	//Operatorul >
	bool operator>(const Locatie& l);
	//Operatorul <
	bool operator<(const Locatie& l);
	//Operatorul >=
	bool operator>=(const Locatie& l);
	//Operatorul <=
	bool operator<=(const Locatie& l);
	//Operatorul ==
	bool operator==(const Locatie& l);

	//Operatorul ++ preincrementare
	Locatie& operator++();
	//Operatorul ++ postincrementare
	Locatie operator++(int);

	//2 Metode generice

	void elibereazaSala();

	int verificaParola(string parola);

	//Citire si Afisare
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);

};



