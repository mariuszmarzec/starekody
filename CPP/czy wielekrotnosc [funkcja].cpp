#include <iostream>
using namespace std;
void czy_wielokrotnosc(int a,int b) {
	if (b%a == 0)
		cout << "liczba " << a << " jest wielokrotnoscia liczby " << b << ".";
	else
        cout << "liczba " << a << " nie jest wielokrotnoscia liczby " << b << ".";
}

int main()
{
	int x, y;
	cout << "Aby sprawdzic czy dana liczba jest wielokrotnoscia drugiej wprowadz je.\n";
	cin >> x;
	cin >> y;
	czy_wielokrotnosc(x, y);
	int koniec; std::cin >> koniec;
	return 0;
}
