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

int main()
{
	double rozmiar;

	fstream plik("plik.txt"); //strumien na pliku
	plik.seekg(0, ios::end); //przesuniêcie wskaznika na koniec
	//cout << plik.tellg(); // pozycja wskaŸnika na koñcu pliku

	rozmiar = plik.tellg();

	plik.close(); //zamykanie pliku

// sprawdzanie rozmiaru pliku i dodanie odpowiedniej jednostki

	if (rozmiar < 1024)
	cout << rozmiar <<" B" <<std::endl;
	else
		if (rozmiar < 1048576)
		cout << setprecision(3) << rozmiar / 1024 << " kB" <<std::endl;
		else
			if (rozmiar < 1073741824)
			cout << setprecision(3) << rozmiar / 1048576 <<" MB" <<std::endl;
			else
				if (rozmiar < 1099511627776)
				cout << setprecision(3) << rozmiar / 1073741824 <<" GB" <<std::endl;
				else
				cout << "Error" <<std::endl;

	return 0;
}
