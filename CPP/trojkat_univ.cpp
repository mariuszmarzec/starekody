#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
float dlugosc(int, int, int, int);
int main()
{
int a, b, c, d, e, f;
cin >> a >> b >> c >> d >> e >> f;
float x = dlugosc(a, b, c, d);
float y = dlugosc(a, b, e, f); //  - boki tr�jk�ta
float z = dlugosc(c, d, e, f);
float o = 0.5*(x+y+z);         // po�owa obwodu tr�jk�ta
cout << sqrt(o*(o-x)*(o-y)*(o-z)) << endl; // wz�r Herona
getch();
return 0;
}
float dlugosc(int q, int w, int e, int r)
{
      return sqrt(pow((q-w),2)+pow((e-r),2));
}
