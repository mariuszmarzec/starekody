#include <iostream> // METODA NEWTONA NA SZUKANIE MIEJSCA ZEROWEGO
#include <cmath>
using namespace std;
float f(float x)
{
      return log(x);
}
float df(float x)
{
      return 1/x;
}
float alg_Newtona(float dokladnosc, float x0)
{
      float y, x = x0;
      do
      {
            y = x;
            x = x - f(x)/df(x);
      }
      while (fabs((x-y)/y) > dokladnosc);
      return x;
}
int main()
{
    cout << alg_Newtona(0.001, 0.25) << endl;
    system("pause");
    return 0;
}
