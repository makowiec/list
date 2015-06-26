//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     :
// Copyright   : IC
// Description : Program do tworzenia listy plików, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	fstream plik("plik.txt"); //strumien na pliku
	plik.seekg(0, ios::end); //przesuniêcie wskaznika na koniec
	cout << plik.tellg(); // pozycja wskaŸnika na koñcu pliku
	plik.close(); //zamykanie pliku


	return 0;
}
