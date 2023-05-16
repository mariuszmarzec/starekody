#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    unsigned int l, m, l2, m2, p;
    char slash[1];
    cin >> l >> slash[0] >> m >> l2 >> slash[0] >> m2;
    if (l + m + l2 + m2 <= 4000000)
    {
           if (m == m2)
           {
                l += l2;  
           }
           else
           {
                l = (l*m2)+(l2*m);
                m *= m2;
           }
           if (l >= m) p = m;
           else p = l;
           while (p > 0)
           {
                 if (m%p == 0 and l%p == 0) break;
                 p--;
           }
           cout << l/p << "/" << m/p << endl;
    }
    getch();
    return 0;
}
