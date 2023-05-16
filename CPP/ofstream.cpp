#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int main()
{
/* ODCZYT, ZAPIS
    int a = 0, b = 0;
    ofstream zapis("plik.txt");
    for (int i = 0; i < 10; i++) zapis << i << endl;
    zapis.close();
    ifstream odczyt("plik.txt");
    while (!odczyt.eof())
    {
        odczyt >> a;
        b += a;
    }
    odczyt.close();
    cout << b;
    */
    // FUNKCJA GET - pobiera jeden znak, dolicza 3 znaki konca wiersza
/*    char znak;
    int liczba = 0;
    ifstream odczyt("plik.txt");
    while (!odczyt.eof())
    {
          odczyt.get(znak);
          if (odczyt) ++liczba;
    }
    odczyt.close();
    cout << liczba; */
    // isalnum tylko alfanumeryczne, isdigit cyfry isalpha litera
/*    char znak;
    int liczba = 0;
    ifstream odczyt("plik.txt");
    while (!odczyt.eof())
    {
          odczyt.get(znak);
          if (isalnum(znak)) ++liczba;
    }
    odczyt.close();
    cout << liczba;
*/ // put - zapisuje do pliku 
/*    char z;
    ofstream odczyt("plik.txt");
    cin >> z;
    odczyt.put(z);
    odczyt.close();
*/
    char znaki[200];
    ifstream odczyt("plik.txt");
    while (!odczyt.eof())
    {
          odczyt.getline(znaki, 20);
          cout << znaki << endl;
    }
    odczyt.close();
    cin.ignore();
    getchar();
    return 0;
}
