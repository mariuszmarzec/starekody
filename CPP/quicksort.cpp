#include <iostream>
#include <conio.h>
#define N 10
using namespace std;
int losuj_zmienna(int a, int b)
{
    return a + rand()%(b-a+1);
}
int zamien(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void wypelnij(int tab[], int w)
{
    for (int i = 0; i < w; i++) tab[i] = losuj_zmienna(0,10);
}
void quicksort (int tablica[], int x, int y)
{
    int i, j, temp, v;
    i=x;
    j=y;
    v=tablica[x];
    
    do
    {
        while (v>tablica[i]) i++; //szukam mniejszego lub rownego
        while (v<tablica[j]) j--; //szukam wiekszego lub rownego
        if (i<=j)
        {
            zamien(tablica[i], tablica[j]);
            i++;
            j--;
        }
    } while (i<=j);
    
    if (x<j) quicksort(tablica,x,j);
    if (i<y) quicksort(tablica,i,y);
}
void wypisz(int tab[], int w)
{
     for (int i = 0; i < w; i++) cout << tab[i] << endl;     
}
using namespace std;
int main()
{
    srand(time(NULL));
    int tab[N];
    wypelnij(tab, N);
    wypisz(tab, N);
    cout << endl;
    quicksort(tab, 0,N-1);
    wypisz(tab, N);
    getch();
    return 0;
}

