#include <iostream>
#include <conio.h>
using namespace std;
int NWW(int, int);
int NWD(int, int);
int main()
{
    int N, i, nww = 1;
    cout << "NWW dla dowolnej ilosci liczb naturalnych." << endl;
    cin >> N;
    unsigned int* tablica = new unsigned int[N];
    for (i = 0; i < N; i++) cin >> tablica[i];
    i = 0;
    while (i < N)
    {
        nww = NWW(nww, tablica[i]);
        i++;
    }
    delete tablica;
    tablica = NULL;
    cout << "NWW = " << nww;
    getch();
    return 0;
}
int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
              a -= b;
        else if (a < b)
              b -= a;
    }
    return a;
}
int NWW(int a, int b)
{
    return a*b/NWD(a, b);
}
