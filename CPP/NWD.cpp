#include <iostream>
using namespace std ;
int NWD(int a, int b) {
	while (a!=b) { 
		if (a>b) {
			a-=b;
		} 
		else {
			b-=a;
		} 
	}
	return a;
}
int main()
{
	int x, y;
	cout << "wpisz dwie liczby" << endl;
	cin >> x >> y;
	cout << "NWD liczb (" << x << ", " << y << ") = " << NWD(x, y);
	int koniec; std::cin >> koniec;
	return 0;
} 
