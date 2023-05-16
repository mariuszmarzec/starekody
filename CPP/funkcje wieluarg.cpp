#include<iostream>
#include<cstdarg>
using namespace std;
void funkcja(int liczba, ...)
{
     int i;
     char* bufor; // przechowuje argument typu char
     va_list lista_arg;
     va_start(lista_arg, liczba);
     for (i = 0; i < liczba; i++)
     {
         bufor = va_arg(lista_arg, char*);
         cout << bufor;
     }
     va_end(lista_arg);
     cout << endl;
}
int main()
{
    funkcja(2,"mariusz ","marzec");
    cout << endl;
    system("PAUSE");
    return 0;
}
