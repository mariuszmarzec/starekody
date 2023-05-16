#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int wzorzec1znakowy(string napis)
{
    int i, j, l = 0, w = napis.length();
    for (i = 48; i < 58; i++)
        for (j = 0; j < w; j++)
                if (napis[j] == static_cast<char>(i))
                   l++;
    return l;
}
bool czy_uzyty(string napis)
{
}
int wzorzecnznakowy(string napis)
{
    string wzorzec;
    vector <string> wzorce;
    string najdluzszy;
    bool uzyty;
    int l = 0, n = 0; // liczba powtorzen wzorca
    int wz = 2; // dlugosc wzorca
    int i, j, k, m, w = napis.length();
    while (wz <= w)
    {
        for (k = 0; k + wz-1 < w; k++)
        {
            wzorzec = napis.substr(k, wz);
            uzyty = false;
            
            for (i = 0; i < wzorce.size() and !uzyty; i++)
                if (wzorzec == wzorce[i])
                   uzyty = true;
            
            if (!uzyty)
            {
                wzorce.push_back(wzorzec);
                cout << wzorzec<< "   ";
                l = 0;
                for (i = 0; i+wz-1 < w; i++)
                {
                    if (napis.substr(i, wz) == wzorzec) l++;
                }
                cout <<  l << endl;
                if (l > 1) najdluzszy = wzorzec;
                n+= l;
            }
        }
        wzorce.clear();
        wz++;
    }
    cout << "Najdluzszy wzorzec " << najdluzszy << endl;
    return n;
}
int main()
{
    char plik_pi[7] = "pi.txt";
    string liczba_ip;
    fstream plik;
    
    plik.open("pi.txt", ios::in);
    getline(plik, liczba_ip);
    cout << liczba_ip << endl;
    plik.close();
    cout << endl;
    cout << "ilosc powtorzen wzorcow: " << wzorzec1znakowy(liczba_ip) + wzorzecnznakowy(liczba_ip) << endl;
    system("PAUSE");    
    return 0;
}

