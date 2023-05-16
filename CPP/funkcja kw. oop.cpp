#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
class funkcja
{
    private:
        float a, b, c, delta;
    public:
        funkcja()
        {
            cout << "Wprowadz wspolczynniki a, b, c" << endl;
            cin >> a >> b >> c;
        }
        void oblicz_delte(float a,float b,float c) { delta = (b*b)-(4*a*c); }
        void oblicz()
        {
            oblicz_delte(a, b, c);
            if (delta > 0)
            {
                cout << "delta = " << delta << endl << "delta > 0" << endl << "x1 = " << (-b-sqrt(delta))/(2*a) 
                << endl << "x2 = " << (-b+sqrt(delta))/(2*a) << endl;
            }
            else if (delta == 0)
            {
                cout << "delta = " << delta << endl << "delta = 0" << endl << "x = " << -b/(2*a) << endl;
            }
            else
            {
                cout << "delta = " << delta << endl << "delta < 0" << endl << "brak rozwiazan." << endl;
            }
        }
};
int main()
{
    funkcja rownanie;
    rownanie.oblicz();
    cin.ignore();
    getchar();
    return 0;
}
