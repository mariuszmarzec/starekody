#include <iostream> 
using namespace std;
void Funkcja(int liczba) // funkcja, któr¹ bêdziemy wywo³ywaæ 
{ 
    cout << liczba; 
}
int __fastcall dodaj(int a, int b) // deklaracja funkcji ze specjalna konwencja
{
    return a + b;
}
int main() 
{  
    void (*pfnWskaznik)(int); // deklaracja wskaŸnika na powy¿sz¹ funkcjê
    pfnWskaznik = &Funkcja;     // przypisanie funkcji do wskaŸnika 
    (*pfnWskaznik)(500);     // wywo³anie funkcji poprzez ten wskaŸnik 
    cout << endl;
    int ( __fastcall *wskaznik)(int, int); // deklaracja wskaŸnika
    wskaznik = dodaj;     // przypisanie funkcji do wskaŸnika, operator & jest niekonieczny 
    cout << wskaznik(500, 300); // wywo³anie funkcji poprzez ten wskaŸnik, deferencja jest niekonieczna    
    cout << endl;
    system("PAUSE");
    return 0;
} 
 
