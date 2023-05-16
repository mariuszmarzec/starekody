#include <iostream>
using namespace std;
int main()
{
cout << "Wprowadz liczby naturalne ktore beda stanowic przedzial liczb, w ktorym nastapi wyszukiwanie liczb pierwszych." << endl;
unsigned int a; cin >> a;
unsigned int b; cin >> b;
if (a < b) {
	cout << "Wyszukiwanie liczb pierwszych w przedziale <" << a << "," << b << ">." << endl;
	while (a <= b) {
		int liczba = 2;
		while (liczba <= a) {
			if (liczba == a) {
			cout << "- " << a << endl;
			}
			else if (a%liczba == 0) {
				break;
			}
			liczba++;
		}
		a++;
	}
}
else {
	cout << "Pierwsza wartosc musi byc mniejsza od drugiej.";
}
int koniec; std::cin >> koniec;
return 0;
} 
