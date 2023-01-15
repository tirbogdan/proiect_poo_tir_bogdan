#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;
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
	Bilet();
	Bilet(string denumireEveniment, string locatieEveniment, string dataEveniment, string oraEveniment, string tipBilet, double pretBilet, string codUnic, string serieBilet, string organizatorEveniment);
	
	//Getter si setter pentru idBilet
	string getIdBilet();
	void setIdBilet(string idBilet);

	//Getter si setter pentru denumireEveniment
	string getDenumireEveniment();
	void setDenumireEveniment(string denumireEveniment);

	//Getter si setter pentru locatieEveniment
	string getLocatieEveniment();
	void setLocatieEveniment(string locatieEveniment);

	//Getter si setter pentru dataEveniment
	string getDataEveniment();
	void setDataEveniment(string dataEveniment);

	//Getter si setter pentru oraEveniment
	string getOraEveniment();
	void setOraEveniment(string oraEveniment);

	//Getter si setter pentru tipBilet de adaugat verificare
	string getTipBilet();
	void setTipBilet(string tipBilet);
	
	//Getter si setter pentru pretBilet
	double getPretBilet();
	void setPretBilet(float pretBilet);

	//Getter si setter pentru serieBilet
	string getSerieBilet();
	void setSerieBilet(string serieBilet);

	//Getter si setter pentru organizatorEveniment
	string getOrganizatorEveniment();
	void setOrganizatorEveniment(string organizatorEveniment);

	//2 metode generice
	void upgrateBilet(string noulTipBilet, float noulPretBilet);
	void utilizeazaCodReducere(string codReducere);

	//Supraincarcarea a 2 operatori

	//supraincarcare operator!
	bool operator!();

	//supraincarcare operator cast la string
	operator string();

	static string creareCodUnic();
	

	//Citire si Afisare
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};





