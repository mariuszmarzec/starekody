#include <iostream>
#include <cstdio>
using namespace std;
char klucz[6][2] = {{'P', 'O'}, {'L', 'I'}, {'T', 'Y'}, {'K', 'A'}, {'R', 'E'}, {'N', 'U'}};
bool czy_w_przedziale(int a, int b, int c)
{
     if (a <= c and c <= b) return true;
     return false;
}
void zamien_na_duze(char tab[])
{
     for (int i = 0; tab[i] != 0; i++)
         if (czy_w_przedziale(97,122,static_cast<int>(tab[i])))
              tab[i] = static_cast<int>(tab[i]) - 32;
}
void zaszyfruj(char tablica[])
{
     zamien_na_duze(tablica);
     for (int i = 0; tablica[i] != 0; i++)
     {
         for (int j = 0; j < 6; j++)
         {
             if (tablica[i] == klucz[j][0]) tablica[i] = klucz[j][1];
             else if (tablica[i] == klucz[j][1]) tablica[i] = klucz[j][0];
         }
     }
}
int main()
{
    const int W = 20;
    char imie[W];
    cin.getline(imie,W);
    zaszyfruj(imie);
    cout << imie << endl;
    zaszyfruj(imie);
    cout << imie;
    cout << endl;
    cin.ignore();
    getchar();
    return 0;
}
