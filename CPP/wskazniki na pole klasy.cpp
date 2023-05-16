#include <iostream>
#include <stdio.h>
using namespace std;
class foo
{
      public:
             int pole;
             static int statycznepole;
             static int funkcja(int x) {return x*statycznepole;} 
};
int foo::statycznepole = 12;
struct VECTOR3 {float x, y, z; };
int main()
{
    foo przyklad;
    przyklad.pole = 20;
    cout << przyklad.pole << endl;
    int* wskazniknapole = &(przyklad.pole); // deklaracja wskaznnika na element klasy
    cout << *wskazniknapole << endl;
    // str 417
    float VECTOR3::*wspolrzedna; // typ klasa::wskaznik
    wspolrzedna = &VECTOR3::x;
    VECTOR3 wektor;
    wektor.*wspolrzedna = 56;
    cout << wektor.x << endl;
    // jezeli chcemy wywolac wskaznik na statyczna metoda robimy to tak
    //
    // nazwa_klasy::nazwa_metody
    // na niestatyczne funkcje jest nie mo¿liwe
    int (*wsk_funkcja)(int);
    wsk_funkcja = foo::funkcja; 
    cout << wsk_funkcja(5);
    cin.ignore();
    getchar();
    return 0;
}
