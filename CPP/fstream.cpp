#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string napis;
    char dane[1024];
    char nazwa[10] = "dane.txt";
    fstream plik;
    plik.open(nazwa, ios::in|ios::out);
    if (plik.good())
    {
        cout << "otwarto plik" << endl;
       // plik >> dane; // wczytanie linijki
       // getline(plik,dane); // wczytanie linijki
        //plik.read(dane, 1024);
       // cout << dane << endl;
        getline(cin,napis);
        plik.write(&napis[0], napis.length());
        plik.close();
    }
    else
        cout << "Error" << endl;
    system("PAUSE");
    return 0;
}
/*
http://kursy.ddt.pl/?LessonId=110

void open(const char* nazwa_pliku,ios_base::openmode tryb_otwarcia_pliku);
bool good();
bool is_open();
void close(void);
istream& getline (char* odczytane_dane, streamsize ilosc_danych, char znak_konca_linii);
istream& read(char* bufor, streamsize rozmiar_bufora);
ostream& write(const char* bufor, streamsize ilosc_danych_do_zapisu );
istream& seekg (streamoff offset, ios_base::seekdir kierunek); dla odczytu danych
ostream& seekp (streamoff offset, ios_base::seekdir kierunek);dla zapisu danych
*/
