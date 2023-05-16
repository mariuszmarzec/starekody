#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    const int w = 500, w2 = 5;
    int i, k, l = 1, z;
    char mors[w];
    for (i = 0; i < w; i++) mors[i] = 0;
    cin.getline(mors, w);
    for (i = 0; i < w; i++)
    {
        if (mors[i] != '/' and mors[i] != 0)
        {
             k = i;
        }
        else
        {
            z = 0;
            l = 1;
            for (k, l; k >= 0 and mors[k] != '/'; k--, l *= 10)
            {
                if (mors[k] == '.') z += 2*l;
                else if (mors[k] == '-') z += 1*l;
            }
            switch (z)
            {
                case 21 : cout << "A"; break;
                case 1222 : cout << "B"; break;
                case 1212 : cout << "C"; break;
                case 122 : cout << "D"; break;
                case 2 : cout << "E"; break;
                case 2212 : cout << "F"; break;
                case 112 : cout << "G"; break;
                case 2222 : cout << "H"; break;
                case 22 : cout << "I"; break;
                case 2111 : cout << "J"; break;
                case 121 : cout << "K"; break;
                case 2122 : cout << "L";  break;
                case 11 : cout << "M"; break;
                case 12 : cout << "N"; break;
                case 111 : cout << "O"; break;
                case 2112 : cout << "P"; break;
                case 1121 : cout << "Q"; break;
                case 212 : cout << "R"; break;
                case 222 : cout << "S"; break;
                case 1 : cout << "T"; break;
                case 221 : cout << "U"; break;
                case 2221 : cout << "V"; break;
                case 211 : cout << "W"; break;
                case 1221 : cout << "X"; break;
                case 1211 : cout << "Y"; break;
                case 2211 : cout << "Z"; break;
                case 11111 : cout << "0"; break;
                case 21111 : cout << "1"; break;
                case 22111 : cout << "2"; break;
                case 22211 : cout << "3"; break;
                case 22221 : cout << "4"; break;
                case 22222 : cout << "5"; break;
                case 12222 :  cout << "6"; break;
                case 11222 : cout << "7"; break;
                case 11122 : cout << "8"; break;
                case 11112 : cout << "9"; break;
            }
        }
    }
    cout << endl;
    getch();
    return 0;
}
/*
*/
