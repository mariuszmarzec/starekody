#include <iostream>
#include <conio.h>
using namespace std;
bool algorytm_naiwny(char t[], char p[], int n, int m)
{
     int i, j;
     bool dopasowany = false;
     for (i = 0; i < n-m+1 and !dopasowany; i++)
     {
         dopasowany = true;
         for (j = 0; j < m and dopasowany; j++)
             if (p[j] != t[i+j])
                 dopasowany = false;
     }
     return dopasowany;
}
int main()
{
    int n = 7, m = 3;
    char* tekst = "mariusz";
    char* wzorzec = "usz";
    if (algorytm_naiwny(tekst,wzorzec,n,m))
       cout << "TAK";
    else
       cout << "NIE";
    getch();
    return 0;    
}

