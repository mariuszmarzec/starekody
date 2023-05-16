#include <iostream>
#include <cstdio>
using namespace std;
void alf(char tablica[])
{
     for (int i = 0; tablica[i] != 0; i++)
         for (int j = 0; tablica[j] != 0; j++)
             if (tablica[j+1] != 0 and(int) tablica[j+1] < (int) tablica[j])
             {
                char temp = tablica[j+1];
                tablica[j+1] = tablica[j];
                tablica[j] = temp;
             }
}
int main()
{
    int r = 30;
    char tablica[r];
    cin >> tablica;
    alf(tablica);
    cout << tablica << endl;
    cin.ignore();
    getchar();
    return 0;
}
