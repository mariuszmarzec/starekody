#include <iostream>
#include <cstdio>
// MAKRA - 
#define ODWOLANIE 200
// #undef ODWOLANIE // zwalnia odwolanie
#define ZMIEN g_z = 0;
#define ZAKONCZ {g_z = 500;}
#define NAPISZ cout << "napis" << endl; \
               cout << "napis2" << endl;
#define PI 3.14
#define POLE_KOLA (PI*4*promien)
/*
//ZAPIS
#define LICZBA (float) 56
// rownowazony jest przez
#define LICZBA 56.0f
               56 - int
              56u - unsigned
             56.0 - double
            56.0f - float
*/
using namespace std;
int g_z = 100;
int main()
{
    cout << ODWOLANIE << endl;
    ZMIEN;
    cout << g_z << endl;
    if (!g_z) ZAKONCZ;
    cout << g_z << endl;
    NAPISZ
    int promien = 3;
    cout << POLE_KOLA << endl;
    //cout << LICZBA;
    cout << __LINE__ << " linia, w ktorej jestesmy" << endl;
    cout << "plik " << __FILE__ << endl;
    cout << "skompilowano dnia " << __DATE__ << " " << __TIME__ << endl;
    // cout << "ostatnia zmiana " << __TIMESTAMP__ << endl; nie dzia³a, nie wiadomo czemu
    // MAKRA PARAMETRYCZNE
    #define POTEGA(x) ((x)*(x))
    cout << POTEGA(2) << endl;
    // #define FOO(tekst) 101##tekst // ## - laczy
    #define STR(napis) #napis
    cout << STR(napis) << endl;
    #define MAKRO
    #ifdef MAKRO
           #define MAKRO2 1
    #endif
    #ifndef MAKRO
           #define MAKRO2 0
    #endif
    cout << MAKRO2 << endl;
    #if defined(MAKRO) // != #if !defined(MAKRO) | Mo¿na u¿ywaæ !, ||, &&, liczb
        #define MAKRO2 1
    #else               // Mo¿na tak¿e u¿yæ #elif (else if)
        #error "kompilacja przerwana"
    #endif
    cout << MAKRO2 << endl;
    /*
    #include "gui\buttons.h"  // 1 
    #include "..\base.h"  // 2 
    #include "..\common\pointers.hpp"  // 3 
    */
    getchar();
    return 0;
}
