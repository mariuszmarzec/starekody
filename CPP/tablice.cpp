#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;
int zamien(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int losuj_zmienna(int a, int b)
{
    return a + rand()%(b-a+1);
}
void wypelnij(int tab[], int w)
{
     //int a, b;
     //cout << "wprowadz przedzial" << endl;
     //cin >> a >> b;
     for (int i = 0; i < w; i++) tab[i] = losuj_zmienna(0,20);
}
void wypisz(int tab[], int w)
{
     for (int i = 0; i < w; i++) cout << setw(2) << i << " ";
     cout << endl;
     for (int i = 0; i < w; i++) cout << setw(2) << tab[i] << " ";
     cout << endl;     
}
int sumuj(int tab[], int w)
{
    int suma = 0;
    for (int i = 0; i < w; i++) suma += tab[i];
    return suma;
}
void dodaj_do_3(int tablica1[], int  tablica2[], int  tablica3[], int W)
{
    for (int i = 0; i < W; i++) tablica3[i] = tablica1[i] + tablica2[i];
}
void znajdz(int tablica[], int w, int n)
{
    for (int i = 0; i < w; i++)
    {
        if (tablica[i] == n)
        {
            cout << "Podana liczba znajduje sie w tablicy" << endl;
            break;
        }
        else  if (w-1 == i) cout << "Podana liczba nie znajduje sie w tablicy" << endl;
    } 
}
bool znajdz2(int tablica[], int w, int n)
{
         for (int i = 0; i < w; i++) if (tablica[i] == n) return true;
         return false;
}
int max(int tablica[], int w)
{
     int max = tablica[0];
     for (int i = 1; i < w; i++) if (max < tablica[i]) max = tablica[i];
     return max;
}
int index_of_max(int tablica[], int w)
{
    int max = 0;
    for (int i = 1; i < w; i++) if (tablica[max] < tablica[i]) max = i;
    return max;
}
int min(int tablica[], int w)
{
     int min = 0;
     for (int i = 1; i < w; i++) if (min > tablica[i]) min = tablica[i];
     return min;
}
int index_of_min(int tablica[], int w)
{
    int min = 0;
    for (int i = 1; i < w; i++) if (tablica[min] > tablica[i]) min = i;
    return min;
}
bool wartownik(int tab[], int w, int szukane)
{
    int i;
    tab[w-1] = szukane;
    for (i = 0; tab[i] != szukane; i++);
    if (i < 10) return true;
    else return false;
}
void gdzie(int tab[], int w, int szukane)
{
     for (int i = 0; i < w; i++) if (tab[i] == szukane) cout << i << endl;
}
void sortowaniebab(int tablica[], int w)
{
     for (int i = 0; i < w; i++)
         for (int j = 0; j < w-i-1; j++)
             if (tablica[j+1] < tablica[j]) zamien(tablica[j+1], tablica[j]);
}
void sortowaniebab_flag(int tablica[], int w)
{
     int i = 0, j = 0;
     bool flaga = true;
     for (i = 0; i < w and flaga; i++)
     {
         flaga = false;
         for (j = 0; j < w-i-1; j++)
         {
             if (tablica[j+1] < tablica[j])
             {
                 zamien(tablica[j+1], tablica[j]);
                 flaga = true;
             }
         }
     }
}
void sort_wstaw(int tablica[], int w)
{
     int i, j, liczba;
     for (i = 1; i < w; i++)
     {
         liczba = tablica[i];
         for (j = i-1; 0 <= j and liczba < tablica[j]; j--)
         {
                 tablica[j+1] = tablica[j];
         }
         tablica[j+1] = liczba;
     }
}
void sortowanie_przez_wybor(int tablica[], int w)
{
    while (w)
    {
          zamien(tablica[index_of_max(tablica,w)], tablica[w-1]);
          --w;
    }
}
void sort_shella(int tablica[], int w)
{
     // h - obliczanie metoda Kuntha
     int i, j, h = 1, liczba;
     while (h < w)
           h = 3*h+1;
     h /= 9;
     while (h)
     {
         for (i = h; i < w; i+=h)
         {
             liczba = tablica[i];
             for (j = i-h; 0 <= j and liczba < tablica[j]; j-=h)
             {
                     tablica[j+h] = tablica[j];
             }
             tablica[j+h] = liczba;
         }
         cout << "h = " << h << endl;
         wypisz(tablica,w);
         h = h/3;
     }
}
void merge(int A[], int W, int pocz, int sr, int kon)
{
    int i,j,q, B[W];
    for (i=pocz; i<=kon; i++)
        B[i] = A[i];  // Skopiowanie danych do tablicy pomocniczej
    i = pocz;
    j = sr+1;
    q = pocz;                 // Ustawienie wskaŸników tablic
    while (i<=sr && j<=kon)
    {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
        if (B[i]<B[j])
                A[q++]=B[i++];
        else
                A[q++]=B[j++];
    }
    while (i<=sr)
       A[q++] = B[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
    for (i = pocz; i <= kon; i++) cout << A[i] << " ";
    cout << endl;
}
 
/* Procedura sortowania tab[pocz...kon] */
void mergesort(int A[], int W, int pocz, int kon)
{
    int sr;
    if (pocz<kon)
    {
        sr=(pocz+kon)/2;
        mergesort(A, W, pocz, sr);    // Dzielenie lewej czêœci
        mergesort(A, W, sr+1, kon);   // Dzielenie prawej czêœci
        merge(A, W, pocz, sr, kon);   // £¹czenie czêœci lewej i prawej
    }
}
void przywroc_kopiec(int A[], int W, int i)
{
    int lsyn, psyn, wiekszy = i;
    lsyn = 2*i;
    psyn = lsyn+1;
    if (lsyn <= W)
      if (A[lsyn] > A[i])
         wiekszy = lsyn;
    
    if (psyn <= W)
      if (A[psyn] > A[wiekszy])
         wiekszy = psyn;
    
    if (wiekszy != i)
    {
       zamien(A[i], A[wiekszy]);
       przywroc_kopiec(A, W, wiekszy);
    }
}
void rozbierz_kopiec(int A[], int W)
{
     int i;
     for (i = W; i > 1; i--)
     {
         zamien(A[1],A[i]);
         przywroc_kopiec(A, --W, 1);
     }
}
void heapsort(int A[], int W)
{
     int i;
     for (i = W/2; i > 0; i--)
     {
        przywroc_kopiec(A,W,i);
     }
     rozbierz_kopiec(A, W);
}

int main()
{
    srand(time((time_t*)NULL));
    int W = 8;
    //cin >> W;
    int* tablica1 = new int[W];
    wypelnij(tablica1,W);
    cout << endl;
    wypisz(tablica1,W);
    //heapsort(tablica1,W-1);
    mergesort(tablica1,10,0,W-1);
    cout << endl;
    wypisz(tablica1,W);
    cout << endl;
    system("PAUSE");
    getch();
    return 0;
}
/*
    if (znajdz2(tablica1, W, n)) cout << "Podana liczba znajduje sie w tablicy" << endl;
    else cout << "Podana liczba nie znajduje sie w tablicy" << endl;
        if (wartownik(tablica1,W,20)) cout << "jest" << endl;
    else cout << "nie ma" << endl;
    
void sortowanie_przez_wstawianie(int tab[], int n)
{
     int i, k, elem;
     for (i = 0; i < n; i++)
     {
         elem = tab[i];
         k = i-1;
         while (k >= 0 && tab[k] > elem)
         {
               tab[k+1] = tab[k];
               k--;
         }
         tab[k+1] = elem;
     }
}


void merge(int A[], int lewy, int q, int prawy)
{
     int i, j, k, w;
     i = lewy;
     j = q+1;
     k = 1;
     w = prawy-lewy+1;
     int B[w];
     
     while (i <= q and j <=prawy)
         if (A[i] < A[j])
             B[k++] = A[i++];
         else
             B[k++] = A[j++];
     
     //if (i > q)
     //   for (j, k; j <= prawy and k <= prawy; j++, k++) B[k] = A[j];
     //else
      //  for (i, k; i <= q and k <= prawy; i++, k++) B[k] = A[i];
    for (i = lewy; i <= prawy; i++) A[i] = B[i];
}
void mergesort(int A[], int lewy, int prawy)
{
     if (lewy < prawy)
     {
         int q = (lewy+prawy)/2;
         mergesort(A,lewy,q);
         mergesort(A,q+1,prawy);
         merge(A,lewy,q,prawy);
         wypisz(A,prawy+1);      
     }
}
*/

