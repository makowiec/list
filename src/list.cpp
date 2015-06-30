//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plików, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double rozmiar_pliku (double rozmiar) // okreœlenie rozmiaru pliku
{
	double wynik_fun;

	if (rozmiar < 1024)
		{
		wynik_fun = rozmiar;
		}
		else
		{
			if (rozmiar < 1048576)
			{
			wynik_fun = rozmiar / 1024;
			}
			else
			{
				if (rozmiar < 1073741824)
				{
				wynik_fun = rozmiar / 1048576;
				}
				else
				{
					if (rozmiar < 1099511627776)
					{
					wynik_fun = rozmiar / 1073741824;
					}
					else
					{
					wynik_fun = 0;
					}	}	}	}

	return wynik_fun;
}

string jednostka_pliku (double rozmiar) //okreœlenie jednostki pliku
{
	string jednostka_fun;

	if (rozmiar < 1024)
		{
		jednostka_fun = " B";
		}
		else
		{
			if (rozmiar < 1048576)
			{
			jednostka_fun = " kB";
			}
			else
			{
				if (rozmiar < 1073741824)
				{
				jednostka_fun = " MB";
				}
				else
				{
					if (rozmiar < 1099511627776)
					{
					jednostka_fun = " GB";
					}
					else
					{
					jednostka_fun = " Error";
		}	}	}	}

	return jednostka_fun;
}

int main()
{
	double rozmiar; //rozmiar pliku w bajtach
	double wynik; // rozmiar pliku w "najwiêkszych jednostkach"
	string jednostka; //do zapisu jednostki
	string kod; //kod - potrzebny do œcie¿ki
	string rok; //rok - potrzebny do œcie¿ki
	string miesiac; //miesi¹c - potrzebny do œcie¿ki
	string sciezka; //scia¿ka do plików

	//cout << "Podaj KOD: ";
	//cin >> kod;
	//cout << "Podaj rok: ";
	//cin >> rok;
	//cout << "Podaj miesiac: ";
	//cin >> miesiac;

	//sciezka = kod + '\\' + rok + '\\' + miesiac + '\\';

	//cout << sciezka << endl;

	fstream plik("plik.txt"); //strumien na pliku
	plik.seekg(0, ios::end); //przesuniêcie wskaznika na koniec
	//cout << plik.tellg(); // pozycja wskaŸnika na koñcu pliku

	rozmiar = plik.tellg();
	plik.close(); //zamykanie pliku

	wynik = rozmiar_pliku (rozmiar);
	jednostka = jednostka_pliku (rozmiar);

	fstream file;
	// otwarcie pliku
	file.open( "wynik.txt", ios::app | ios::in | ios::out );
	//weryfikacja poprawnoœci otwarcia
	if( file.good() == true )
	{
// komentarz sprawdzajacy
	cout << "Uzyskano dostep do pliku!" << endl;

	//zapisanie strumienia do pliku
	file << setprecision(3) << wynik << jednostka << endl;

// komentarz sprawdzajacy
	cout << "Dane zapisane do pliku" << endl;

	//obs³uba b³êdu - brak dostêpu do pliku
	}
	else
// komentarz sprawdzajacy
	cout << "Dostep do pliku zostal zabroniony!" << endl;

	// zamykanie pliku
	file.close();
// komentarz sprawdzajacy
	cout << "Plik zostal zamkniety" << endl;
	return 0;
}
