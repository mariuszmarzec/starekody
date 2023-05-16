#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double log_a(double a, double x)
{
       return log(x) / log(a);
}
void dec2bin(int x)
{
     const int w = (int) ceil(log_a(2,x-1));
     int tab[w], i = 0;
     while (x)
     {
           tab[i] = x%2;
           x = (x-(x%2))/2;
           i++;
     }
     i = w-1;
     while (i >= 0)
     {
           cout << tab[i];
           i--;
     }
}
int main()
{
    int x;
    cin >> x;
    dec2bin(x);
    cout << endl;
    cin.ignore();
    getchar();
    return 0;
}
/*
L = k^n - 1
L - liczba
k - podstawa ci¹gu            n = log(k, L - 1) 
n - liczba cyfr
*/
