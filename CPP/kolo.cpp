#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std ;
main()
{
	float r, d, p, o;
	float pi = 3.14159;
	cout << "Wpisz ile wynosi promien kola."
			"\n(pi = 3,14159)\n";
	cin >> r;
	if (r > 0) {
		d = 2*r;
		p = pi*pow(r, 2);
		o = 2*pi*r;
		cout << "promien = " << r
			 << "\nsrednica = " << d
			 << "\npole = " << p
			 << "\nobwod = " << o;
	}
	else
	cout << "promien > 0!!";
	int koniec; std::cin >> koniec;
	return 0;
} 
