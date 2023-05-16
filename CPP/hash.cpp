#include <iostream>
#include <conio.h>
using namespace std;
int hash(char* s)
{
    int h = 0;
    for(s; *s; s++)
    {
       h += (int)(*s);
    }
    return h;
}
int main()
{
    int i, W = 10;
    int tablica[10];
    for (i = 0; i < W; i++) tablica[i] = i;
    for (i = 0; i < W; i++) cout << i << endl;
    int index = hash("kurwa")%W;
    cout << index << " " << tablica[index];
    getch();
    return 0;    
}
/*
HASHOWANIE Z NETA

int hash(char* s)
{
        char* p;
        int g, h=0;
 
        for (p=s; (*p)!='\0'; p++)
        {
                h = (h<<4) + (*p);
                if (g=h&0xF0000000) 
                {
                        h = h^(g>>24); h=h^g;
                }
        }
 
        return h;
}

*/
