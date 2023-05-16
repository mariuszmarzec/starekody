#include<stdio.h>
#include<math.h>
int main()
{
    int i=-1;
    double a = 1, k, s = 1;
    printf("Podaj koniec: ");
    scanf("%lf", &k);
    do
    {
           s *= a;
           i++;
           printf("Podaj a%d: ", i+1);
           scanf("%lf",&a);
           while((10 > a || a > 999) && a != k)
           {
               printf("UWAGA!! Podana liczba musi byæ z przedzialu <10,999>\nPodaj a%d: ", i+1);
               scanf("%lf",&a);
           }
    }
    while(a != k);
    s = pow(s,(1./i));
    printf("srednia geometryczna = %lf\n", s);
    system("PAUSE");
	return 0;
}
