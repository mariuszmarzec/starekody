#include <fstream>
#include <string>
#include <cstdio>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int i = 0;
    int j = 0;
    int C = 5; // ilosc klas
    int N = 4;
    int W = 1000;
    int lower;
    int upper;
    FILE* plik = fopen("plik.txt", "w");

          for (i = 0; i < C; i++)
          {
              lower = rand()%((i+1)*15);
              upper = rand()%((i+1)*30);
              for (int k = 0; k < W; k++)
              {
                  fprintf(plik, "%d ", i+1);
                  for (j = 0; j < N; j++)
                  {
                      fprintf(plik, "%d ", lower+rand()%upper);
                  }              
                  fprintf(plik, "\n");
              }
          }
/*          for (i = 0; i < 10; i++)
          {
              lower = rand()%((1)*20);
              upper = rand()%((C)*30);

                  fprintf(plik, "%d ", 0);
                  for (j = 0; j < N; j++)
                  {
                      fprintf(plik, "%d ", lower+rand()%upper);
                  }              
                  fprintf(plik, "\n");
          }
*/    fclose(plik);
    return 0;
}
/* jawor 4
    srand(time(NULL));
    int i = 0;
    int W = 100000;
    int P = 28;
    int floor = 9;
    FILE* plik = fopen("plik.txt", "w");

          for (i = 0; i < W; i++)
              fprintf(plik, "%d %d\n", floor+rand()%P,floor+rand()%P);
    fclose(plik);
*/
/* jawor 1
    srand(time(NULL));
    char* wyraz;
    char c;
    int i = 0;
    int j;
    int W;
    int N = 200;
    FILE* plik = fopen("plik.txt", "w");
    while (i < N)
    {
          W = 1+rand()%10;
          wyraz = new char[W];
          wyraz = "";
          for (j = 0; j < W; j++)
              fprintf(plik, "%c", (char)(65+rand()%24));
              //wyraz[j] = (char)(65+rand()%24);
          fprintf(plik, "\n");
          delete[] wyraz;
          i++;
    }
*/
