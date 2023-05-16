#include <iostream> 
using namespace std;
void Funkcja(int liczba) // funkcja, kt�r� b�dziemy wywo�ywa� 
{ 
    cout << liczba; 
}
int __fastcall dodaj(int a, int b) // deklaracja funkcji ze specjalna konwencja
{
    return a + b;
}
int main() 
{  
    void (*pfnWskaznik)(int); // deklaracja wska�nika na powy�sz� funkcj�
    pfnWskaznik = &Funkcja;     // przypisanie funkcji do wska�nika 
    (*pfnWskaznik)(500);     // wywo�anie funkcji poprzez ten wska�nik 
    cout << endl;
    int ( __fastcall *wskaznik)(int, int); // deklaracja wska�nika
    wskaznik = dodaj;     // przypisanie funkcji do wska�nika, operator & jest niekonieczny 
    cout << wskaznik(500, 300); // wywo�anie funkcji poprzez ten wska�nik, deferencja jest niekonieczna    
    cout << endl;
    system("PAUSE");
    return 0;
} 
 
