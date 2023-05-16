#include <iostream>
#include <cstdlib>
using namespace std;

//[] //informujesz, ¿e zaczyna siê wyra¿enie lambda
//( /*definiujesz argumenty funkcji*/ )->/*tu okreœlasz zwracany typ*/
//{
//    //cia³o funkcji (zwane tak¿e cia³em wyra¿ania lambda)
//}( /*wartoœci argumentów z jakimi wyra¿enie lambda ma zostaæ wywo³ane*/ )

int funkcja()
{
    return 123;
}
int main ()
{
    cout << funkcja() << endl;
    // lambda
    cout << []() -> int {return 123;}() << endl;

    int zmienna = []() -> int {return 123;}();

    // przekazywanie argumentow
    cout << [](int a, int b) -> int {return a+b;}(10, 6) << endl;

    []()->void {cout << "lambda ktora zwraca void" << endl;}();

    // wskaznik funkcji
    auto pAdres =[]( int x, int y )->void { std::printf( "Wyrazenie lambda: %d + %d = %d\n", x, y, x + y ); };
    pAdres( 5, 6 );
    pAdres( 7, 8 );
    system("PAUSE");
    return 0;
}