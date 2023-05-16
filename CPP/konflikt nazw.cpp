#include <iostream>
namespace moja{ int k=5; }
using namespace std;
using namespace moja; // spowoduje konflikt nazw gdy w int main nie ma deklaracji zmiennej k
int k=7;
// :: przykrycie lokalnej zmiennej przez globalna
int main()
{
    int k = 3;
    cout << k << endl;
    system("PAUSE");
    return 0;
}
