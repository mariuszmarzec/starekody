#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float a, b, c;
	cout << "Aby sprawdzic czy trojkat jest prostokatny wpisz miary bokow.\n";
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > 0 and b > 0 and c > 0) {
		if ((a < b + c) and (b < a + c) and (c < a + b)) {
			if (pow(c,2) == pow(a,2) + pow(b,2)) {
				cout << "Trojkat o bokach: " << a << ", " << b << ", " << c << " jest prostokatny.";
			}
			else {
				cout << "Trojkat o podanych bokach nie jest prostokatny.";
			}
		}
		else
			cout << "Taki trojkat nie istnieje.";
	}
	else
		cout << "Podane wielkosci musza byc rozne od zera.";
	int koniec; std::cin >> koniec;
	return 0;
} 
