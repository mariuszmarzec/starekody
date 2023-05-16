#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
// elewacja i azymut cos nie idzie
//=========================================================

// Deklaracja klasy Wektor3

class Wektor3
{
public:
	Wektor3( void );
	Wektor3( double x, double y, double z );
	Wektor3( const Wektor3 &w );

	double X( void ) { return _x; }
	double Y( void ) { return _y; }
	double Z( void ) { return _z; }

	Wektor3& Assign( double x, double y, double z );
	Wektor3& Assign( const Wektor3 &w );

	double Mod( void );
	double Azym( void );
	double Elev( void );

	Wektor3& Plus( const Wektor3 &w );
	Wektor3& Mult( double k );

	friend Wektor3 Plus( const Wektor3 &w1, const Wektor3 &w2 );
	friend Wektor3 Mult( double k, const Wektor3 &w );

	friend bool Eq( const Wektor3 &w1, const Wektor3 &w2 );
	friend bool Neq( const Wektor3 &w1, const Wektor3 &w2 );

private:
	double  _x, _y, _z;
};

//=========================================================

// Definicje konstruktorow, metod i funkcji zaprzyjaznionych

Wektor3::Wektor3( void )
{
	_x = _y = _z = 0.0;
}
//---------------------------------------------------------

Wektor3::Wektor3( double x, double y, double z )
{
	_x = x; _y = y; _z = z;
}
//---------------------------------------------------------

Wektor3::Wektor3( const Wektor3 &w )
{
    _x = w._x; _y = w._y; _z = w._z;
}

//---------------------------------------------------------

Wektor3& Wektor3::Assign( double x, double y, double z )
{
	_x = x; _y = y; _z = z;

	return *this;
}
//---------------------------------------------------------

Wektor3& Wektor3::Assign( const Wektor3 &w )
{
          _x = w._x; _y = w._y; _z = w._z;
          return *this;
}
//---------------------------------------------------------

double Wektor3::Mod( void )
{
       return sqrt(_x*_x+_y*_y+_z*_z);
}
//---------------------------------------------------------

double Wektor3::Azym( void )
{
      if (_y >= 0) return acos(_x/sqrt(_x*_x+_y*_y))*180/M_PI;
      return -acos((_x/sqrt(_x*_x+_y*_y)))*180/M_PI;
}
//---------------------------------------------------------

double Wektor3::Elev( void )
{
       return asin(_z/Mod())*180/M_PI;
}
//---------------------------------------------------------

Wektor3& Wektor3::Plus( const Wektor3 &w )
{
         _x += w._x; _y += w._y; _z += w._z;
         return *this;
}
//---------------------------------------------------------

Wektor3& Wektor3::Mult( double k )
{
         _x = k*_x; _y = k*_y; _z = k*_z;
}
//---------------------------------------------------------

Wektor3 Plus( const Wektor3 &w1, const Wektor3 &w2 )
{
        Wektor3 w((w1._x+w2._x),(w2._y+w1._y),(w2._z+w1._z));
        return w;
}
//---------------------------------------------------------

Wektor3 Mult( double k, const Wektor3 &w )
{
        Wektor3 w1(k*w._x,k*w._y,k*w._z);
        return w1;
}
//---------------------------------------------------------

bool Eq( const Wektor3 &w1, const Wektor3 &w2 )
{
     if (w1._x == w2._x and w1._y == w2._y and w1._z == w2._z) return true;
     return false;
}
//---------------------------------------------------------

bool Neq( const Wektor3 &w1, const Wektor3 &w2 )
{
     if (w1._x != w2._x or w1._y != w2._y or w1._z != w2._z) return true;
     return false;
}
//=========================================================

int main(int argc, char *argv[])
{
	Wektor3     w1( 1, 2, 3 );
	Wektor3     w3, w4, w5;
	double      ax, ay, az, k;

	cout << "Wektor w3 (x, y, z): ";
	cin >> ax >> ay >> az;
	w3.Assign( ax, ay, az );

	cout << "Wektor w4 (x, y, z): ";
	cin >> ax >> ay >> az;
	w4.Assign( ax, ay, az );

	cout << "Wspolczynnik k: ";
	cin >> k;

	Wektor3     w31( w3 );

	cout << fixed << setprecision( 3 ) << endl;
	cout << "Wektor w1 = ( " << w1.X( ) << ", " << w1.Y( ) << ", " <<
		w1.Z( ) << " )" << endl;
	cout << "Wektor w3 = ( " << w3.X( ) << ", " << w3.Y( ) << ", " <<
		w3.Z( ) << " )" << endl;
	cout << "Kopia  w3 = ( " << w31.X( ) << ", " << w31.Y( ) << ", " << 
		w31.Z( ) << " )" << endl;
	cout << "Wektor w4 = ( " << w4.X( ) << ", " << w4.Y( ) << ", " <<
		w4.Z( ) << " )" << endl << endl;

	w5.Assign( w3 );
	w5.Plus( w4 );
	cout << "Wektor w3+w4 = ( " << w5.X( ) << ", " << w5.Y( ) << ", " <<
		w5.Z( ) << " )" << endl;

	w5.Assign( Plus( w1, w3 ) );
	cout << "Wektor w1+w3 = ( " << w5.X( ) << ", " << w5.Y( ) << ", " <<
		w5.Z( ) << " )" << endl << endl;

	w5.Assign( w3 );
	w5.Mult( k );
	cout << "Wektor k*w3 = ( " << w5.X( ) << ", " << w5.Y( ) << ", " <<
		w5.Z( ) << " )" << endl ;

	w5.Assign( Mult( k, w4 ) );
	cout << "Wektor k*w4 = ( " << w5.X( ) << ", " << w5.Y( ) << ", " <<			w5.Z( ) << " )" << endl << endl ;

	cout << "Modul w3 = " << w3.Mod( ) << endl;
	cout << "Azymut w3 = " << w3.Azym( ) << endl;
	cout << "Elewacja w3 = " << w3.Elev( ) << endl << endl;

	cout << "w3==w4 " << ( Eq( w3, w4 ) ? "tak" : "nie" ) << endl << endl;
	cout << "w3!=w4 " << ( Neq( w3, w4 ) ? "tak" : "nie" ) << endl << endl;
    system("PAUSE");
	return 0;
}
