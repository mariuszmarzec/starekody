#include <stdio.h>
using namespace std; /* Metoda wysokopoziomwa */
int main()
{
    FILE *fp; /* u�ywamy metody wysokopoziomowej - musimy mie� zatem identyfikator pliku, uwaga na gwiazdk�! */
    char tekst[] = "siema all\n";
    if ((fp=fopen("test.txt", "w"))==NULL) { /* w - pisanie; r - czytanie*/
        printf ("Nie mog� otworzy� pliku test.txt do zapisu!\n");
    }
    fprintf (fp, "%s", tekst); /* zapisz nasz �a�cuch w pliku */
    fprintf (fp, "%s", tekst);
    fclose (fp); /* zamknij plik */
    getchar();
    return 0;
}
