#include <iostream>
#include <cstdio>
using namespace std;
int main()           
{
    int i;
    for (i = 0; i < 256; i++) cout << i << " " << static_cast<char>(i) << endl;
    system("PAUSE");
	return 0;
}
