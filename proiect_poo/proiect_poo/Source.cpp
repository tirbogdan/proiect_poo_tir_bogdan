#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Locatie.h"
#include "Bilet.h"
#include "Eveniment.h"
#include "Auxiliare.h"
#pragma warning(disable: 4996)
using namespace std;



int main()
{
	/*
	Locatie l1;
	cin >> l1;
	Locatie l2;
	l2 = l1;
	*/
	
	string ceVreiSaArati = "-1";
	int ceVreiSaAratiInt = -1;
	do
	{
		cout << "Ce vrei sa arati?" << endl;
		cout << "1. Un meniu functional dar care e inutil" << endl;
		cout << "2. O incursiune prin prima etapa" << endl;
		cout << "0. Am terminat de prezentat deci asta e iesirea" << endl;
		getline(cin, ceVreiSaArati);
		if (ceVreiSaArati == "1") ceVreiSaAratiInt = 1;
		else if (ceVreiSaArati == "2") ceVreiSaAratiInt = 2;
		else if (ceVreiSaArati == "0") ceVreiSaAratiInt = 0;
		else ceVreiSaAratiInt = -1;
		
		//cin.get();
		switch (ceVreiSaAratiInt)
		{
		case 1:
		{
			string optiune = "0";
			do
			{
				Auxiliare::afisareOptiuniMeniuprincipal();
				Auxiliare::functionalitateMeniuPrincipal(optiune);
			} while (optiune != "0");
			break;
		}
		case 2:
		{
			
			system("CLS");
			cout << "Prima clasa pe care am facut-o este clasa Locatie" << endl;
			Locatie l1;
			cout << "Am apelat contructorul fara parametrii si merge" << endl;
			cout << l1;
			cout << "Cam asa arata un obiect de tip locatie contruit cu acest constructor" << endl;
			cout << endl;
			if (Auxiliare::continuam() == false) break;
			
			system("CLS");
			cout << "Acum vom construi un obiect de tip locatie folosind constructorul cu parametri" << endl;
			Locatie l2("Bucuresti", "St", "071231212", 500, 1234.54, "parola");
			cout << "Si cam asa arata acest obiect" << endl;
			cout << l2 << endl;
			cout << endl;
			if (Auxiliare::continuam() == false) break;
			
			system("CLS");
			cout << "Acum vom construi un obiect de tip locatie folosind constructorul de copiere" << endl;
			Locatie l3(l2);
			cout << "Si cam asa arata acest obiect" << endl;
			cout << l3 << endl;
			cout << endl;
			if (Auxiliare::continuam() == false) break;
			
			system("CLS");
			cout << "Poti sa si citesti datele unei locatii de la tastatura!" << endl;
			Locatie l4;
			cin >> l4;
			cout << endl << "Si obiectul creat este acesta: " << endl;
			cout << l4;
			cin.get();
			cout << endl;
			if (Auxiliare::continuam() == false) break;

			system("CLS");
			cout << "Merge si operatorul '=' astfel ca putem sa atribuim primului obiect valoarea ultimului" << endl;
			l1 = l4;
			cout << "Acum primul obiect are aceleasi date ca ultimul obiect creat" << endl;
			cout << l1;

			cout << endl;
			if (Auxiliare::continuam() == false) break;

			system("CLS");
			cout << "Acum intram in partea de setteri si getteri" << endl;
			cout << "Voi apela aici toti setteri si getterii cu date predefinite pentru ca simt ca deja lumea nu mai are rabdare" << endl;

			cout << "Numele locatiei este: " << l4.getDenumire() << endl;
			l4.setDenumire("Medgidia");
			cout << "Noul nume al locatiei este " << l4.getDenumire() << endl;
			
			cout << "Adresa locatiei este: " << l4.getAdresa() << endl;
			l4.setAdresa("Strada Rahovei");
			cout << "Noua adresa a locatiei este " << l4.getAdresa() << endl;
			
			cout << "Numarul de telefon al locatiei este: " << l4.getTelefon() << endl;
			l4.setTelefon("0712312312");
			cout << "Noul numar de telefon al locatiei este " << l4.getTelefon() << endl;
			
			cout << "Capacitatea locatiei este: " << l4.getCapacitate() << endl;
			l4.setCapacitate(1000);
			cout << "Noua capacitate a locatiei este " << l4.getCapacitate() << endl;
			
			cout << "Pretul locatiei este: " << l4.getPretInchiriere() << endl;
			l4.setPretInchiriere(1000.00);
			cout << "Noul pret al locatiei este " << l4.getPretInchiriere() << endl;
			
			
			
			cout << "Ocuparea locurilor din prezent arata in felul urmator: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are urmatoarea ocupare:" << endl;
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					for (int k = 0; k < l4.getNrLocuriPerRand()[i][j]; k++)
					{
						cout << l4.getOcupareLocatie()[i][j][k] << " ";
					}
					cout << endl;
				}
			}
			cout << "Setterul pentru ocuparea locatiei functioneaza in 2 modalitati: " << endl;
			cout << "Poate modifica toata ocuparea locatiei: " << endl;
			int*** ocupareNoua = new int** [l4.getNrSectoare()];
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				ocupareNoua[i] = new int* [l4.getNrRanduriPerSector()[i]];
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					ocupareNoua[i][j] = new int[l4.getNrLocuriPerRand()[i][j]];
					for (int k = 0; k < l4.getNrLocuriPerRand()[i][j]; k++)
					{
						if ((i + j + k) % 2 == 0)
							ocupareNoua[i][j][k] = 1;
						else
							ocupareNoua[i][j][k] = 0;
					}
				}
			}
			l4.setOcupareLocatie(ocupareNoua);
			cout << "Ocuparea locatiei dupa modificare este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are urmatoarea ocupare:" << endl;
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					for (int k = 0; k < l4.getNrLocuriPerRand()[i][j]; k++)
					{
						cout << l4.getOcupareLocatie()[i][j][k] << " ";
					}
					cout << endl;
				}
			}

			l1 = l4;

			cout << "Sau poate modifica doar un anumit loc: " << endl;
			l4.setOcupareLocatie(nullptr, 1, 1, 1);
			cout << "Ocuparea locatiei dupa modificare este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are urmatoarea ocupare:" << endl;
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					for (int k = 0; k < l4.getNrLocuriPerRand()[i][j]; k++)
					{
						cout << l4.getOcupareLocatie()[i][j][k] << " ";
					}
					cout << endl;
				}
			}
			cout << "Setterul si getterul pentru numarul de locuri pe rand functioneaza pe acelasi principiu asa ca voi arata doar prima metoda de functionare" << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					cout << "Numarul de locuri pe randul " << j << " din sectorul " << i << " este " << l4.getNrLocuriPerRand()[i][j] << endl;
				}
			}
			int** nrLocuriPerRandNou = new int* [l4.getNrSectoare()];
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				nrLocuriPerRandNou[i] = new int[l4.getNrRanduriPerSector()[i]];
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					nrLocuriPerRandNou[i][j] = i + j;
				}
			}
			l4.setNrLocuriPerRand(nrLocuriPerRandNou);
			cout << "Numarul de locuri pe rand dupa modificare este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				for (int j = 0; j < l4.getNrRanduriPerSector()[i]; j++)
				{
					cout << "Numarul de locuri pe randul " << j << " din sectorul " << i << " este " << l4.getNrLocuriPerRand()[i][j] << endl;
				}
			}
			
			cout << "Setterul si getterul pentru numarul de randuri pe sector functioneaza, de asemenea, in acelasi mod asa ca apelez la aceeasi modalitate" << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Numarul de randuri pe sectorul " << i << " este " << l4.getNrRanduriPerSector()[i] << endl;
			}
			int* nrRanduriPerSectorNou = new int[l4.getNrSectoare()];
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				nrRanduriPerSectorNou[i] = i+1;
			}
			l4.setNrRanduriPerSector(nrRanduriPerSectorNou);
			cout << "Numarul de randuri pe sector dupa modificare este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Numarul de randuri pe sectorul " << i << " este " << l4.getNrRanduriPerSector()[i] << endl;
			}
			
			cout << "Si a mai ramas doar setterul si getterul pentru denumirea sectoarelor care e mai complex" << endl;
			cout << "Denumirea sectoarelor este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are denumirea " << l4.getDenumireSector()[i] << endl;
			}
			char** denumireSectorNou = new char*[l4.getNrSectoare()];
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				denumireSectorNou[i] = new char[20];
				strcpy_s(denumireSectorNou[i], 20, "Sectorul nou");
			}
			l4.setDenumireSector(denumireSectorNou);
			cout << "Denumirea sectoarelor dupa modificare este: " << endl;
			for (int i = 0; i < l4.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are denumirea " << l4.getDenumireSector()[i] << endl;
			}
			
			
			cout << " Si in final numarul de sectoare in care este impartita locatia este" << l4.getNrSectoare() << endl;
			l4.setNrSectoare(3);
			cout << "Noul numar de sectoare este " << l4.getNrSectoare() << endl;
			
			cout << endl;
			if (Auxiliare::continuam() == false) break;

			system("CLS");
			cout << "Ok mai am cateva functii la locatie si gata, promit." << endl;
			cout << "Asa ca hai a vedem care locatie are o capacitate mai mare dintre locatia 3 si locatia 4" << endl;
			if (l3 > l4)
			{
				cout << "Locatia 3 are o capacitate mai mare" << endl;
			}
			else
			{
				cout << "Locatia 4 are o capacitate mai mare" << endl;
			}
			cout << "Si daca tot suntem aici putem sa crestem si capacitatea locatiei 3 cu un spectator pentru ca unde sunt " << l3.getCapacitate() << " mai incape inca unul" << endl;
			l3++;
			cout << "Acum capacitatea locatiei 3 este " << l3.getCapacitate() << endl;

			cout << endl;
			if (Auxiliare::continuam() == false) break;
			
			system("CLS");
			cout << "Si ultimul lucru de la aceasta clasa il reprezinta cele 2 metode generice" << endl;
			cout << "Prima verifica doar daca parola de administrator este corecta. Aceasta metoda era utila in niste implementari ulterioare pentru a securiza diversele metode de acces dar deoarece in varianta actuala a proiectului nu este folosita nu o sa o mai demonstrez" << endl;
			cout << "Si din moment ce am terminat cu tot amalgamul asta de metode putem sa apelam a doua metoda si sa eliberam sala" << endl;
			l1.elibereazaSala();
			cout << "Si acum putem sa vedem ca sala este libera" << endl;
			for (int i = 0; i < l1.getNrSectoare(); i++)
			{
				cout << "Sectorul " << i << " are urmatoarea ocupare:" << endl;
				for (int j = 0; j < l1.getNrRanduriPerSector()[i]; j++)
				{
					for (int k = 0; k < l1.getNrLocuriPerRand()[i][j]; k++)
					{
						if (l1.getOcupareLocatie()[i][j] != nullptr)
							cout << l1.getOcupareLocatie()[i][j][k] << " ";
						else
							cout << 0 << " ";
					}
					cout << endl;
				}
			}
			
			cout << endl;
			if (Auxiliare::continuam() == false) break;

			
			system("CLS");
			cout << "Si pentru ca stiu ca este sambata dimineata si mai sunt si alte persoane de prezentat nu voi mai trece si prin celelalte 2 clase, principiile de functionare fiind asemanatoare" << endl;
			Sleep(7000);
			break;
		}
		case 0:
		{
			system("CLS");
			cout << "Multumesc pentru atentie! <3" << endl;
			cout << "Acum incepe sesiunea de intrebari";
			break;
		}
		
		default:
			system("CLS");
			cout << "Trebuie sa apesi pe 1, 2 sau 0 si apoi pe Enter. Atat!" << endl;
			break;
		}
	} while (ceVreiSaArati != "0");
	
	return 0;

}