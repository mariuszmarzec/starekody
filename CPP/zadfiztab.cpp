#include <iostream>
#include <cstdlib>
using namespace std;
int losuj_zmienna(int a, int b)
{
    return a + rand()%(b-a+1);
}
void wypelnij(int* tab, int w)
{
     int i;
     for (i = 0; i < w; i++) tab[i] = losuj_zmienna(0,9);
}
void wypelnij_macierz(int* tab[], int X, int Y)
{
    for (int i = 0; i < X; i++)
    {
        tab[i] = new int[Y];
        for (int j = 0; j < Y; j++) tab[i][j] = losuj_zmienna(0,9);
    }
}

void wypisztab(int* tab, int w)
{
     int i;
     for (i = 0; i < w; i++) cout << tab[i] << endl;     
}
void wypiszmacierz(int** tab, int M, int N)
{
     int i,j;
     for (i = 0; i < M; i++)
     { 
          for (j = 0; j < N; j++)
          {
              cout << tab[i][j] << " ";
          }
          cout << endl;     
     }
}

// SREDNIA W TABLICY
float srednia(int* tablica, int W)
{
    float srednia = 0;
    for (int i = 0; i < W; i++) srednia += tablica[i];
    return (float) srednia/W; 
}
// SREDNIA W MACIERZY
float srednia_macierz(int** tablica, int M, int N)
{
    float sred = 0;
    for (int i = 0; i < M; i++) sred += srednia(tablica[i], N);
    return (float) sred/M;
}
// FUNKCJA DO ZADANIA 1 UWAGA SPRAWDZA ELEMENT O INDEKSIE X i X+1, zakladamy ze x nalezy do [0, W-1]
bool warunektab(int* tablica, int W, int x)
{
    float srednia_tab = srednia(tablica, W);
    float suma = tablica[x]+tablica[x+1];
    if (srednia_tab == suma) return true;
    return false;
}
// FUNKCJA DO ZADANIA 3 WYKORZYSTUJACA WARUNEK Z ZADANIA 2 DLA PODANEGO WIERSZA - arg wiersz
bool warunekmacierz(int** tablica, int M, int N, int wiersz,int x)
{
    float srednia_tab = srednia_macierz(tablica, M, N);
    float suma = tablica[wiersz][x]+tablica[wiersz][x+1];
    if (srednia_tab == suma) return true;
    return false;
}
int main()
{
    srand(time(NULL));
    int M = 4;
    int N = 4;
    int wiersz ,x;
    int** macierz = new int*[M];
    wypelnij_macierz(macierz, M, N);
    wypiszmacierz(macierz, M, N);
    cout << endl;
    cout << "Wpisz wiersz pierwszy element:" << endl;
    cin >> wiersz >> x;
    if (warunekmacierz(macierz, M, N, wiersz, x))
       cout << "TAK" << endl;
    else 
       cout << "NIE" << endl; 
    system("PAUSE");
    return 0;
}
/*
1)SprawdŸ czy w tablicy n-elementowej suma dowolnych dwóch s¹siednich elementow jest rowna sredniej arytmetycznej wszystkich elementow tablicy.
2)Wykorzystac funkcje z p-ktu1 do obliczen w poszczególnych wierszach macierzy.
3)Ulo¿yc funkcje,(ktorej parametrem jest ca³a macierz), wykonujac obliczenia jak w p-kcie1.


*/
