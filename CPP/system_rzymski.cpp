#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n, l = 0;
    cin >> n;
    while (n)
    {
          if (n >= 1000)
          {
                  cout << "M";
                  n -= 1000;  
          }
          else if (n >= 900)
          {
                  cout << "CM";
                  n -= 900;  
          }
          else if (n >= 500)
          {
                  cout << "D";
                  n -= 500;  
          }
          else if (n >= 400)
          {
                  cout << "CD";
                  n -= 400;  
          }
          else if (n >= 100)
          {
                  cout << "C";
                  n -= 100;  
          }
          else if (n >= 90)
          {
                  cout << "XC";
                  n -= 90;  
          }
          else if (n >= 50)
          {
                  cout << "L";
                  n -= 50;  
          }
          else if (n >= 40)
          {
                  cout << "XL";
                  n -= 40;  
          }
          else if (n >= 10)
          {
                  cout << "X";
                  n -= 10;  
          }
          else if (n >= 9)
          {
                  cout << "IX";
                  n -= 9;  
          }
          else if (n >= 5)
          {
                  cout << "V";
                  n -= 5;  
          }
          else if (n >= 4)
          {
                  cout << "IV";
                  n -= 4;  
          }
          else if (n >= 1)
          {
                  cout << "I";
                  n -= 1;  
          }
    }
    cout << endl;
    getch();
    return 0;
}
