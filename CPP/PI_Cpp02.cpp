#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#define	ROZM_TABL_MAX	1000

// Deklaracje (prototypy) w³asnych funkcji u¿ytych w programie

void WypelnTabl( int tabl[], int rozmTabl );

int MinIndex( int tabl[], int rozmTabl );
int MaxIndex( int tabl[], int rozmTabl );
double Srednia( int tabl[], int rozmTabl );

int CzytajInt( int min, int max );
void PiszTabl( int tabl[], int rozmTabl, int nKol );

int zamien(int& a, int& b);
void sortowanie(int tabl[], int rozmTabl);

//---------------------------------------------------------

int main(int argc, char *argv[])
{
	int		t[ROZM_TABL_MAX];
	int		ilLiczb, ilKolumn;
	int		idxMin, idxMax;
	double	sr;
	
// 1. 
    cout << "Ilosc elementow? ";
	ilLiczb = CzytajInt( 1, ROZM_TABL_MAX );
	WypelnTabl( t, ilLiczb );
	
// 2. 
    cout << "Ilosc kolumn? ";
	ilKolumn = CzytajInt( 1, 8 );

	cout << endl;
	PiszTabl( t, ilLiczb, ilKolumn );
	
	sr = Srednia( t, ilLiczb );
	idxMin = MinIndex( t, ilLiczb );
	idxMax = MaxIndex( t, ilLiczb );
	
// 3.
    cout << endl;
    cout << "Srednia = " << setprecision(1) << fixed << sr << endl;
    cout << "Element najmniejszy: TABL[ " << idxMin << " ] = " << t[idxMin] << endl;
    cout << "Element najwiekszy: TABL[ " << idxMax << " ] = " << t[idxMax] << endl;
    cout << endl;
    cout << "sortowanie rosnaco" << endl;
    sortowanie(t, ilLiczb);
    PiszTabl( t, ilLiczb, ilKolumn );
    cout << endl;
    system("PAUSE");
	return 0;
}

//---------------------------------------------------------

 
void WypelnTabl( int tabl[], int rozmTabl )
{
	int		ofs = RAND_MAX / 2;
	int		i;

	srand( (unsigned int)time( NULL ) );
	for( i = 0; i < rozmTabl; i++ )
		tabl[ i ] = rand( ) - ofs;

}

//---------------------------------------------------------

int MinIndex( int tabl[], int rozmTabl )
{
     int min = 0;
     for (int i = 1; i < rozmTabl; i++) if (tabl[min] > tabl[i]) min = i;
     return min;   
}
// 4. Uzupelnic

//---------------------------------------------------------

int MaxIndex( int tabl[], int rozmTabl )
{
    int max = 0;
    for (int i = 1; i < rozmTabl; i++) if (tabl[max] < tabl[i]) max = i;
    return max;
}
// 5. Uzupelnic

//---------------------------------------------------------

double Srednia( int tabl[], int rozmTabl )
{
       double suma = 0;
       for (int i = 0; i < rozmTabl; i++) suma += tabl[i];
       return suma/rozmTabl;
}
// 6. 

int CzytajInt( int min, int max )
{
    int liczba;
    do
    {
          cin >> liczba;
    }
    while (liczba < min or liczba > max);
    return liczba;
}
// 7. 


void PiszTabl( int tabl[], int rozmTabl, int nKol )
{
     for (int i = 0; i < rozmTabl; i++)
     {
         cout << setw(3) << i << "." << setw(6) << tabl[i];
         if ((0 == (i+1)%nKol and i != 0) or nKol == 1) cout << endl;
         else cout << " ";
     }
     if (rozmTabl%nKol != 0) cout << endl;
}
// 8. 
// NA BARDZO DOBRY
void sortowanie(int tabl[], int rozmTabl)
{
     for (int i = 0; i < rozmTabl; i++)
         for (int j = 0; j < rozmTabl-1; j++)
             if (tabl[j+1] < tabl[j]) zamien(tabl[j+1], tabl[j]);
}
int zamien(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
