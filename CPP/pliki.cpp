#include <iostream>
#include <fstream>
using namespace std;
string dane;
int main()
{
    fstream plik;
    plik.open("dane.txt",ios::in|ios::out); // otwieranie pliku z parametrami zapisu (in) i odczytu (out)
    if(plik.good() == true) // sprawdza czy plik zostal otwarty prawidlowo
    {
        cout<<"udalo sie otworzyc"<<endl;
        cout<<endl;

        while(!plik.eof()) // az do konca pliku
        {
            getline(plik,dane); // pobranie jednej linijki tekstu
            cout<<dane<<endl; // wypisanie
        }

    plik.close(); // zamkniecie pliku konieczne! (informacja dodatkwa wyjscie z programu poprzez exit zamyka wszystkie pliki automatycznie wiec jest lepszy niz return 0
    }
    else
    {
        cout<<"nie moge otowrzyc"<<endl;
    }
    system("PAUSE");
    return 0;
}
