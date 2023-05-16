#include <iostream>
#include <cstdio>
using namespace std;
int policz(char tab[])
{
    int i;
    for (i = 0; tab[i] != 0; i++);
    return i;
}
bool czy_w_przedziale(int a, int b, int c)
{
     if (a <= c and c <= b) return true;
     return false;
}
void zamien_na_male(char tab[])
{
     for (int i = 0; tab[i] != 0; i++) if (czy_w_przedziale(65,90,static_cast<int>(tab[i]))) tab[i] = static_cast<int>(tab[i]) + 32;
}
void zamien_na_duze(char tab[])
{
     for (int i = 0; tab[i] != 0; i++) if (czy_w_przedziale(97,122,static_cast<int>(tab[i]))) tab[i] = static_cast<int>(tab[i]) - 32;
}
void zamien(char tab[])
{
          for (int i = 0; tab[i] != 0; i++)
          {
              if (czy_w_przedziale(65,90,static_cast<int>(tab[i]))) tab[i] = static_cast<int>(tab[i]) + 32;
              else if (czy_w_przedziale(97,122,static_cast<int>(tab[i]))) tab[i] = static_cast<int>(tab[i]) - 32;
          }
}
void wspak(char tab[])
{
     for (int i = policz(tab)-1; i >= 0; i--) cout << tab[i];
}
int main()
{
    const int W = 20;
    char imie[W];
    cin.getline(imie, W);
    zamien_na_duze(imie);
    cout << imie << endl;
    cin.ignore();
    getchar();
    return 0;
}
