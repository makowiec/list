//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     :
// Copyright   : IC
// Description : Program do tworzenia listy plik�w, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	fstream plik("plik.txt"); //strumien na pliku
	plik.seekg(0, ios::end); //przesuni�cie wskaznika na koniec
	cout << plik.tellg(); // pozycja wska�nika na ko�cu pliku
	plik.close(); //zamykanie pliku


	return 0;
}
