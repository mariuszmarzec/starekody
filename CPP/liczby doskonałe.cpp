#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
cout << "Liczby doskonale z przedzialu (1, 10000>" << endl;
int n = 2;
while (n <= 1000000000) {
	int mianownik = 1;
	int suma = 0;
	while (mianownik < n) {
		if (n%mianownik == 0) {
			suma += mianownik;
		}
		if (suma == n and mianownik+1 == n) {
			cout << n << endl;
		}
		mianownik++;
	}
n++;
}
getch();
return 0;
}
