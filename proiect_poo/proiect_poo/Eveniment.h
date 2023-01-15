#pragma once
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
	Eveniment();
	Eveniment(int nrBileteDisponibile, string denumire, string organizator, string locatieEveniment, string dataInceperiiEvenimentului, int nrZileDeDesfasurare);

	//Creare getter si setter pentru denumire
	string getDenumire();
	void setDenumire(string denumire);

	//Creare getter si setter pentru organizator

	string getOrganizator();
	void setOrganizator(string organizator);

	//Creare getter si setter pentru descriere

	string getDescriere();
	void setDescriere(string descriere);


	//Creare getter si setter pentru locatieEveniment

	string getLocatieEveniment();
	void setLocatieEveniment(string locatieEveniment);

	//Creare getter si setter pentru dataInceperiiEvenimentului

	string getDataInceperiiEvenimentului();
	void setDataInceperiiEvenimentului(string dataInceperiiEvenimentului);

	//Creare getter si setter pentru nrZileDeDesfasurare

	int getNrZileDeDesfasurare();
	void setNrZileDeDesfasurare(int nrZileDeDesfasurare);

	//Creare getter si setter pentru nrDeReprezentariPeZi

	int* getNrDeReprezentariPeZi();
	void setNrDeReprezentariPeZi(int* nrDeReprezentariPeZi, int nrZileDeDesfasurare);

	//Creare getter si setter pentru oraIncepereReprezentatie

	string** getOraIncepereReprezentatie();
	void setOraIncepereReprezentatie(string** oraIncepereReprezentatie);

	//Creare getter si setter pentru durataReprezentatieInMinute

	int** getDurataReprezentatieInMinute();
	void setDurataReprezentatieInMinute(int** durataReprezentatieInMinute);

	//Getter pentru nrBileteDisponibile pentru ca e constant si nu poate fi modificat

	int getNrBileteDisponibile();

	//Creare getter si setter pentru nrBileteVandute

	int getNrBileteVandute();
	void setNrBileteVandute(int nrBileteVandute);

	//2 metode generice

	void schimbaDurataEveniment(int durataNoua, int zi, int reprezentatie);

	void schimbaOraIncepereEveniment(string oraNoua, int zi, int reprezentatie);


	//Creare constructor de copiere

	Eveniment(const Eveniment& e);

	//Supraincarcare operator=

	Eveniment& operator=(const Eveniment& e);

	//Supraincarcare operatori[]
	int operator[](int index);

	//Supraincarcare operator+
	Eveniment operator+(int nrBilete);

	//Asigurarea comutativitatii
	friend Eveniment operator+(int nrBilete, Eveniment e);

	//Creare destructor

	~Eveniment();

	//Citire si Afisare
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

