#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int foo(int a, int b, int* roznica)
{
    *roznica = a - b;
    return (a+b);
}
int main()
{/* // zmienne i inne duperele
    int zmienna = 500;
    int* wskaznik = &zmienna;
    int* wskaznik4 = &zmienna;
    *wskaznik4 = 20;
    cout << "adres komorki pamieci - " << wskaznik4 << endl;
    cout << "adres komorki pamieci - " << wskaznik << endl;
    cout << "wartosc wskaznika - " << *wskaznik << endl; // deferencja
    //wska�nik na sta��, korzystanie z modifkator�w
    const int* wskaznik2 = &zmienna;
    cout << "wartosc wskaznika - " << *wskaznik2 << endl;
    // sta�y wska�nik
    int* const wskaznik3 = &zmienna;
    cout << "wartosc wskaznika - " << *wskaznik3 << endl;    
    int liczba = 56;
    void* a = &liczba; // mo�e wszystko, jednak wczasie przypisania int traci swoj� w�asciwosc, jest uniwersalny, brak deferencji
    int* liczba_2 = static_cast<int*>(a);
    cout << "adres komorki pamieci - " << a << endl;
    cout << "wartosc wskaznika - " << liczba << endl;
    cout << "Adres - " << reinterpret_cast<unsigned>(liczba_2) << endl;
*/
/* // tablice
    int tablica[5];
    int* wtablica = &tablica[0]; // lub wtablica = tablica;
    cout << "adresy tablicy - " << tablica << " tablica[3] - " << (tablica+3) << endl;
    // zerowanie wartosci 3 w tablicy, w poprzedniej linijce wskazalismy(^) na 3 
    *wtablica = 0;
    wtablica[3] = 0;
    *(wtablica+3) = 0;
    cout << tablica[3] << endl;
    /*
    odwo�anie do element�w tablicy wska�nikowej:
             * tablica[3]
             * *(tablica+3)
             s� poprawne ale podatne na b��d przekroczenia wielko�ci tablicy
    */
 /*   // Przekazywanie do funkcji wska�nik�w
    int a = 3,  b = 7, roznica, suma = foo(a,b,&roznica);
    cout << " roznica - " << roznica << " suma - " << suma;
    */
    //Zwalnianie pami�ci i dynamiczne zmienne
   /* int* zmienna = new int;
    *zmienna = 100;
    cout << *zmienna << endl;
    delete zmienna;
    zmienna = NULL;
    cout << zmienna << endl; */
    // Dynamiczne tablica
    int* tablica = new int[10];
    if (!tablica) cout << "brak pami�ci" << endl; // jezeli brak�o pami�ci tablicy nie b�dzie ;p
    for (int i = 0; i < 10; i++)
    {
        tablica[i] = i;
        cout << tablica[i] << endl;
    }
    delete[] tablica;
    getch();
    return 0;
}
