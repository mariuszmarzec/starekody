#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(NULL));
    int a = rand()%6;
    cout << a << endl;
    cin.ignore();
    getchar();
    return 0;
}
/*
c c <0,b>
c = rand()%(b+1);

c c <a,b>
c = a +rand()%(b+1);

float
c c <a,b>
c = a +( (float) rand() / (RAND_MAX) ) * (b-a);

*/


