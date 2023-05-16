#include <iostream>
using namespace std ;
int main()
{
	float a, b, c;
	cout << "Aby sprawdzic czy moze istniec trojkat o danych bokach wprowadz je.\n";
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > 0 and b > 0 and c > 0) {
		if ((a < b + c) and (b < a + c) and (c < a + b)) {
			cout << "Istnieje trojkat o bokach: " << a << ", " << b << ", " << c <<".";
		}
		else
			cout << "Taki trojkat nie istnieje.";
	}
	else
		cout << "Podane wielkosci musza byc rozne od zera.";
	int koniec; std::cin >> koniec;
	return 0;
} 
