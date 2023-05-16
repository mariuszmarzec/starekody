#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main()
{
	float a, b, c;
	cout << "Program oblicza rownania kwadratowe w postaci:"<< endl << "ax^2 + bx + c = 0" << endl
		 << "Aby obliczyc rownanie kwadratowe wprowadz wspolczynniki wedlug kolejnosci." << endl;
	cin >> a >> b >> c;
	if (a != 0) {
		float delta = pow(b, 2)-4*a*c;
		if (delta > 0) {
			float x1 = (-b-sqrt(delta))/(2*a);
			float x2 = (-b+sqrt(delta))/(2*a);
			cout << "delta = " << delta << endl << "delta > 0" << endl << "x1 = " << x1 << endl << "x2 = "
				 << x2 << endl;
		}
		else if (delta == 0) {
			float x3 = -b/(2*a);
			cout << "delta = " << delta << endl << "delta = 0" << endl << "x1 = " << x3;
		}
		else {
			cout << "delta = " << delta << endl << "delta < 0" << endl << "rownanie sprzeczne.";
		}
	}
	else
		cout << "Wspolczynnik a musi byc rozny od zera.";
	getch();
	return 0;
}
