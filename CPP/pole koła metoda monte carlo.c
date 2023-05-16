#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define N 1000000000
int main()
{
    double x, y, pi;
    int i, l = 0;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        x = (float)rand()/RAND_MAX;
        y = (float)rand()/RAND_MAX;
        if (x*x+y*y<=1)
        l++;
    }
    pi = (float)l*4/N;
    printf("%lf\n", pi);
    printf("wartosc tablicowa PI = %lf\n", M_PI);
    system("PAUSE");
	return 0;
}

