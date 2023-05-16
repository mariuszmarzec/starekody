#include <iostream>
using namespace std;
int a = 0, b = 0;
void wysw_menu();
int NWD(int a, int b);
class przedzial
{
    private:
         int wtab;
         int* tablica;
    public:
        przedzial()
        {
            if (a > b)
            {
                int t_int = b;
                b = a;
                a = t_int;
            }
            wtab = (b-a)+1;
            tablica = new int[wtab];
            for (int i = 0, j = a; i < wtab and j <= b; j++, i++)
            {
                tablica[i] = j;  
            }
        }    
        void wyswietl()
        {
            for (int i = 0; i < wtab; i++)
                        cout << tablica[i] << endl;
        }
        float oblicz_srednia()
        {
            float suma = 0;
            for (int i = 0; i < wtab; i++) suma += tablica[i];
            return suma/static_cast<float>(wtab);
        }             
            
};
int main()
{
    char d;
    cin >> a >> b;
    przedzial liczby;
    while (d != 't')
    {
        wysw_menu();
        cin >> d;
        if (d == 'd')
                cout << NWD(a,b);
        else if (d == 'p')
                liczby.wyswietl();
        else if (d == 's')
                 cout << liczby.oblicz_srednia();
        cout << endl;
        cout << "t - zamknij" << endl << "n - pokaz_menu" << endl;
        cin >> d;
    }
    return 0;
}
void wysw_menu()
{
    cout << "d - NWD" << endl
     << "p - utworz przedzial" << endl
     << "s - oblicz srednia z przedzialu" << endl
      << "t - zamknij" << endl;
}
int NWD(int a, int b)
{
    while (a != 0)
    {
        if(a>b) a -= b;
        else if (b>a) b -= a;
        else return a;
    }    
}

