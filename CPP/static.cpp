#include <iostream>
#include <cstdio>
using namespace std;
struct UCZEN
{
       static int piornik;
       void wrzuc() {piornik++;}
};
int UCZEN::piornik = 0;
int main()
{
    UCZEN ola;
    UCZEN kasia;
    cout << UCZEN::piornik << endl;
    ola.wrzuc();
    cout << kasia.piornik << endl;
    kasia.wrzuc();
    cout << kasia.piornik << endl;
    cin.ignore();
    getchar();
    return 0;
}
