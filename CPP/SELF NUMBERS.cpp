#include <iostream>
#include <conio.h>
using namespace std; // program spr liczbê generatorów
int d(int); // SELF NUMBERS
int main()
{
    int n;
    cin >> n;
    if (n <= 1000000)
    {
        int x = 1, l = 0;
        while (x <= n)
        {
              if (d(x) == n) l++;
              x++;
        }
        cout << l << endl;
    }
    getch();
    return 0;
}
int d(int n)
{
    int a = n;
    while (n)
    {
          a += n%10;
          n = (n-(n%10))/10;
    }
    return a;
}
