#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string napis, odczyt;
    cin >> napis;
    ofstream plik("plik.txt");
    plik << napis << endl << napis << endl;
    plik.close();
    ifstream plik_odczyt("plik.txt");
    while (!plik_odczyt.eof())
    {
       // plik_odczyt >> odczyt; // 1 pobieranie do zmiennej
       getline(plik_odczyt, odczyt);
       cout << odczyt << endl;
    }
    plik_odczyt.close();
    cin.ignore();
    getchar();
    return 0;
}
