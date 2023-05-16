
// #include <string>
#include <iostream>
using namespace std;
template <class T>
class Dane 
{
private :
	T *wsk_tabl;
	int rozmiar, nr_elem;

public :
	Dane( int Podaj_Rozmiar );   // konstruktor
	~Dane();                     // destruktor

	void dodaj( T Ax );
	T usun( void );
	int czy_brak_danych( void );
	int czy_zapeln( void );
	void akcja(void);
};

/* -------------------------------------------------------- */
template <class T>
Dane<T>::Dane( int Podaj_Rozmiar )        // definicja konstruktora
{
	rozmiar = (Podaj_Rozmiar < 1) ? 1 : Podaj_Rozmiar;
	wsk_tabl = new T[rozmiar];
	nr_elem = 0;
}

template <class T>
Dane<T>::~Dane()
{
	delete [] wsk_tabl;
}
template <class T>
void Dane<T>::dodaj( T x )
{
	if( !czy_zapeln() ) 
	{
		wsk_tabl[nr_elem++] = x;
		cout << "dodano " << x <<  endl;
	}
	else
		cout << "Pamiec zapelniona " <<  endl; 
	cout << endl;
}
template <class T>
T Dane<T>::usun( void )
{
	if( !czy_brak_danych() ) 
		return wsk_tabl[--nr_elem];
	else
		return 0;
}
template <class T>
int Dane<T>::czy_brak_danych( void )
{
	return nr_elem == 0;
}
template <class T>
int Dane<T>::czy_zapeln( void )
{
	return nr_elem == rozmiar;
}
template <class T>
void Dane<T>::akcja(void)
{
	T x; 
	int j, koniec = 0;
	char c;

	while ( !koniec ) 
	{
		cout << "Wybierz:  + (dodaj)  - (usun)   = (wyswielt)   Q (wyjdz)" << endl;
		printf( "%c Dana(%d) ", czy_brak_danych() ? 'B' : czy_zapeln() ? 'P' : ' ', nr_elem );
 
		cin >> c;        //    scanf("%c", &c);
		switch( c ) 
		{
			case '+' : 
				cout << "Wprowadz liczbe:   " ;
				cin >> x;   // scanf( "%d", &x);
				dodaj(x);
			break;
		 
			case '-' : 
				if( !czy_brak_danych() ) 
				{
					x = usun();
					cout << "usunieto " << x << endl << endl; 
				}
				else
					cout << "Brak danych" << endl << endl;
			break;

			case '=' : 
				if( !czy_brak_danych() )  
				{
					cout << "Dane w pamieci: ";
					for (j = 0; j < nr_elem; j++) 
					cout << wsk_tabl[j] << "   "; 
				}
				else
					cout << "Brak danych" << endl;
				cout << endl << endl; 
			break; 
         
			case 'Q' :
			case 'q' : 
				koniec = 1;
			break;
		}
	}
}
/* -------------------------------------------------------- */

int main(int argc, char *argv[])
{
  Dane<char> tablica( 3 );
  tablica.akcja();
  return 0;
}

