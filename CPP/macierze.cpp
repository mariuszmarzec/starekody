#include <iostream>
#include <cstdio>
using namespace std;
int losuj_zmienna(int a, int b)
{
    return a + rand()%(b-a+1);
}
void wypelnij(int* tab[], int X, int Y)
{
    for (int i = 0; i < X; i++)
    {
        tab[i] = new int[Y];
        for (int j = 0; j < Y; j++) tab[i][j] = losuj_zmienna(0,10);
    }
}
void wypisz_macierz(int* tab[], int X, int Y)
{
    for (int i= 0; i < X; i++)
    {
        cout << " ";
        for (int j = 0; j < Y; j++)
        {
            cout << tab[i][j];
            if (tab[i][j] == 10) cout << " ";
            else cout << "  ";
        }
        cout << " " << endl;
    }
}
int** mnozenie_macierzy(int** macierz1, int** macierz2, int X, int Y)
{
    int** macierz3 = new int*[X];
    for (int i = 0; i < X; i++)
    {
        macierz3[i] = new int[X];
        for (int j = 0; j < X; j++)
        {
            macierz3[i][j] = 0;
            for (int k = 0; k < Y; k++) macierz3[i][j] += macierz1[i][k]*macierz2[k][j];
        }
    }
    return macierz3;
}
int main()
{
    srand(time(NULL));
    int X, Y;
    cout << "MNOZENIE MACIERZY" << endl << "Podaj rozmiary macierzy 1" << endl;
    cin >> X;
    do
    {
        cout << "X <= Y" << endl;
        cin >> Y;
    }
    while (X > Y);
    int** macierz1 = new int*[X];
    int** macierz2 = new int*[Y];
    int** macierz3;
    wypelnij(macierz1,X,Y);
    wypelnij(macierz2,Y,X);
    cout << "MACIERZ 1" << endl;
    cout << endl;
    wypisz_macierz(macierz1,X,Y);
    cout << endl;
    cout << "MACIERZ 2" << endl;
    cout << endl;
    wypisz_macierz(macierz2,Y,X);
    macierz3 = mnozenie_macierzy(macierz1,macierz2,X,Y);
    cout << endl;
    cout << "MACIERZ 3" << endl;
    cout << endl;
    wypisz_macierz(macierz3,X,X);
    cout << endl;
    cin.ignore();
    getchar();
    return 0;
}
