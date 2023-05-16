#include <stdio.h>
using namespace std; /* Metoda wysokopoziomwa */
int main()
{
    FILE *fp; /* u¿ywamy metody wysokopoziomowej - musimy mieæ zatem identyfikator pliku, uwaga na gwiazdkê! */
    char tekst[] = "siema all\n";
    if ((fp=fopen("test.txt", "w"))==NULL) { /* w - pisanie; r - czytanie*/
        printf ("Nie mogê otworzyæ pliku test.txt do zapisu!\n");
    }
    fprintf (fp, "%s", tekst); /* zapisz nasz ³añcuch w pliku */
    fprintf (fp, "%s", tekst);
    fclose (fp); /* zamknij plik */
    getchar();
    return 0;
}
