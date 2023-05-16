#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int l, m;
    cin >> l >> m;
    cout << l << "/" << m << " = ";
    int p = 2, tm = m;
    while (p)
    {
        if ((l*p) - m >= 0 and tm != p)
        {
			if ((l*p) - m == 0)
			{
				cout << "1/" << p << endl;
				break;
			}
			else 
			{
				cout << "1/" << p;
				l = (l*p)-m;
				m *= p;
			}
			cout << " + ";
        }
        p++;
    }
    getch();
    return 0;
}
