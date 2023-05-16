#include <iostream>
using namespace std ;
float min(float a, float b, float c) {
    float min;
    if (b > a and c > a) {
		min = a;
	}
	if (a > b and c > b) {
		min = b;
	}
	if (a > c and b > c) {
		min = c;
	}
	return min;
}
int main()
{
	float x, y, z;
	cout << "Wprowadz trzy liczby calkowite:" <<endl;
	cin >> x >> y >> z;
	cout << "Najmniejsza z tych liczb to: " << min(x,y,z) <<endl; 
	int koniec; std::cin >> koniec;
	return 0;
}
