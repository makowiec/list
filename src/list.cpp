//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plik�w, Ansi-style
//				 Pliki mniejsze ni� 1TB
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctime>

using namespace std;

double rozmiar_pliku (double rozmiar) // okre�lenie rozmiaru pliku
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

string jednostka_pliku (double rozmiar) //okre�lenie jednostki pliku
{
	string jednostka_fun;

	if (rozmiar < 1024)
		{
			jednostka_fun = " B ; ";
		}
		else
		{
			if (rozmiar < 1048576)
			{
				jednostka_fun = " kB ; ";
			}
			else
			{
				if (rozmiar < 1073741824)
				{
					jednostka_fun = " MB ; ";
				}
				else
				{
					if (rozmiar < 1099511627776)
					{
						jednostka_fun = " GB ; ";
					}
					else
					{
						jednostka_fun = " Error ; ";
		}	}	}	}

	return jednostka_fun;
}

void listDir(const char * dirn, fstream &file)
{

	double rozmiar; //rozmiar pliku w bajtach
	double wynik; // rozmiar pliku w "najwi�kszych jednostkach"
	string jednostka; //do zapisu jednostki

	char dirnPath[1024];
    sprintf(dirnPath, "%s\\*", dirn);

    WIN32_FIND_DATA f;
    HANDLE h = FindFirstFile(dirnPath, &f);

    if (h == INVALID_HANDLE_VALUE) { return; }

    do
    {
        const char * name = f.cFileName;

        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) { continue; }

        char filePath[1024];
        sprintf(filePath, "%s%s%s", dirn, "\\", name);

        fstream plik(filePath); //strumien na pliku
        plik.seekg(0, ios::end); //przesuni�cie wskaznika na koniec
        rozmiar = plik.tellg(); // zapisnie rozmiaru pliku do zmiennej
        plik.close(); //zamykanie pliku

        wynik = rozmiar_pliku (rozmiar); // wywo�anie funkcji obliczaj�cej rozmiar w "najwiekszych jednostkach"
        jednostka = jednostka_pliku (rozmiar); // wywo�anie funkcj okre�laj�cej jedostk�

        // rozmiar folderu to -1 poni�szy if usuwa foldery z listy
        if (wynik>=0)
        {
        	file << setprecision(3) << wynik << jednostka << filePath << endl;
        }

// komentarz sprawdzajacy
        cout << "Dane zapisane do pliku" << endl;

        if (f.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
        {
            listDir(filePath, file);
        }

    } while (FindNextFile(h, &f));
    FindClose(h);
}

string dtnow ()
{

		time_t rawtime;
	    tm* timeinfo;
	    char buffer [80];

	    time(&rawtime);
	    timeinfo = localtime(&rawtime);

	    strftime(buffer,80,"%d/%m/%Y - %H:%M:%S",timeinfo);

	    return buffer;
}

int main()
{


	string kod; //kod - potrzebny do �cie�ki
	string rok; //rok - potrzebny do �cie�ki
	string miesiac; //miesi�c - potrzebny do �cie�ki
	string sciezka; //scia�ka do plik�w

	cout << "Podaj KOD: ";
	cin >> kod;
	cout << "Podaj rok: ";
	cin >> rok;
	cout << "Podaj miesiac: ";
	cin >> miesiac;
	sciezka = kod + '\\' + rok + '\\' + miesiac + '\\';
	cout << sciezka << endl;


// komentarz sprawdzajacy
	cout << dtnow() <<endl;

	// usuwanie pliku z poprzedni� list�
	if( remove( "wynik.txt" ) == 0 )

		cout << "Plik zosta� usuni�ty" << endl;


	fstream file;
	// otwarcie pliku
	file.open( "wynik.txt", ios::app | ios::in | ios::out );
	//weryfikacja poprawno�ci otwarcia
	if( file.good() == true )
	{

		// Linia informacyjna dla stworzonego pliku
		file << "Lista stworzona dla: " << kod << " za rok: " << rok << " miesiac: "<< miesiac <<". Data wykonania: " << dtnow() << endl;

// komentarz sprawdzajacy
		cout << "Uzyskano dostep do pliku!" << endl;
		listDir("C:\\baza", file); //wywo�anie g�ownej funkcji
    }

	//obs�uba b��du - brak dost�pu do pliku
	else
	{
// komentarz sprawdzajacy
	cout << "Dostep do pliku zostal zabroniony!" << endl;
	}
	// zamykanie pliku
	file.close();
// komentarz sprawdzajacy
	cout << "Plik zostal zamkniety" << endl;

	return 0;
}




