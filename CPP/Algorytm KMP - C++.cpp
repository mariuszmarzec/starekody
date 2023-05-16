//www.Algorytm.org
//Algorytm Knutha-Morrisa-Pratta - wyszukiwanie wzorca
//(c)2001 Tomasz Lubinski

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#ifdef __cplusplus
  int max (int value1, int value2);
  int max(int value1, int value2)
  {return ( (value1 > value2) ? value1 : value2); }
#endif

int main(void)
{
    char wzorzec[100];
    char tekst[2000];
    int m,n,i,j,t;
    int P[100];//maksymalna dlugosc wzorca to 100 symboli
    printf("Podaj tekst\n");
    scanf("%s", tekst);
    printf("Podaj wzorzec\n");
    scanf("%s", wzorzec);
    n=strlen(tekst);
    m=strlen(wzorzec);
    printf("Indeksy poczatku wzorca w tekscie\n");
    
    //obliczenie tablicy P
    P[0]=0; P[1]=0; t=0;
    for (j=2; j<=m; j++)
    {
        while ((t>0)&&(wzorzec[t]!=wzorzec[j-1]))
              t=P[t];
        if (wzorzec[t]==wzorzec[j-1]) t++;
        P[j]=t;
    }
    
    //algorytm KMP
    i=1; j=0;
    while (i<=n-m+1)
    {
        j=P[j];
        while((j<m)&&(wzorzec[j]==tekst[i+j-1]))
           j++;
        if (j==m) printf("%d\n",i);
        i=i+max(1,j-P[j]);
    }
    getch();
    return 0;
}
