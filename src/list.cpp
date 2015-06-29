//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plik�w, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	double rozmiar; //rozmiar pliku w bajtach
	double wynik; // rozmiar pliku w "najwi�kszych jednostkach"
	string jednostka; //do zapisu jednostki

	fstream plik("plik.txt"); //strumien na pliku
	plik.seekg(0, ios::end); //przesuni�cie wskaznika na koniec
	//cout << plik.tellg(); // pozycja wska�nika na ko�cu pliku

	rozmiar = plik.tellg();
	plik.close(); //zamykanie pliku

	// sprawdzanie rozmiaru pliku i dodanie odpowiedniej jednostki

	if (rozmiar < 1024)
	{
	//cout << rozmiar <<" B" <<std::endl;
	wynik = rozmiar;
	jednostka = " B";
	}
	else
	{
		if (rozmiar < 1048576)
		{
				//cout << setprecision(3) << rozmiar / 1024 << " kB" <<std::endl;
		wynik = rozmiar / 1024;
		jednostka = " kB";
		}
		else
		{
			if (rozmiar < 1073741824)
			{
			//cout << setprecision(3) << rozmiar / 1048576 <<" MB" <<std::endl;
			wynik = rozmiar / 1048576;
			jednostka = " MB";
			}
			else
			{
				if (rozmiar < 1099511627776)
				{
				//cout << setprecision(3) << rozmiar / 1073741824 <<" GB" <<std::endl;
				wynik = rozmiar / 1073741824;
				jednostka = " GB";
				}
				else
				{
				//cout << "Error" <<std::endl;
				wynik = 0;
				jednostka = " Error";
	}	}	}	}

	fstream file;
	// otwarcie pliku
	file.open( "wynik.txt", ios::app | ios::in | ios::out );
	//weryfikacja poprawno�ci otwarcia
	if( file.good() == true )
	{
	cout << "Uzyskano dostep do pliku!" << endl;

	//zapisanie strumienia do pliku
	file << setprecision(3) << wynik << jednostka << endl;

	// komentarz sprawdzajacy
	cout << "Dane zapisane do pliku" << endl;

	//obs�uba b��du - brak dost�pu do pliku
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
