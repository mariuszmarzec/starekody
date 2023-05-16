#include<iostream>
#include<cstdlib>
#define MAX 10
using namespace std;
struct lista
{
    int a;
    lista* next;
    lista* prev;
};
void sortowanie(lista tablica[], int W, int* index)
{
     int i, j, k, t;
     lista* el1;
     lista* el2;
     lista* temp;
     for (i = 0; i < *index; i++)
     {
         k = 0;
         while (tablica[k].prev != NULL and k < W) k++;
         el1 = &tablica[k];
         for (j = 0; j < (*index)-1; j++)
         {
             el2 = el1->next;
             if (el1->a > el2->a)
             {  
                 t = el1->a;
                 el1->a = el2->a;
                 el2->a = t;
             }
             el1 = el2;
         }
     }       
}
void dodaj(lista tablica[], int W, int* index)
{
    if (*index == W)
    {
        cout << "Nie mozna dodac nowego elementu. Lista jest pelna." << endl;
    }
    else
    {
        cout << "Podaj liczbe: ";
        cin >> tablica[*index].a;
        if (*index == 0)
        {
            tablica[*index].next = NULL;
            tablica[*index].prev = NULL;
        }
        else
        {
            tablica[(*index)-1].next = &tablica[*index];
            tablica[*index].prev = &tablica[(*index)-1];
            tablica[*index].next = NULL;
        }
        (*index)++;
        sortowanie(tablica, W, index);
    }
}
void wyswietl1(lista tablica[], int W, int* index) // wyswietlanie od poczatku
{
     if (*index != 0)
     {
         lista* temp;
         int i = 0;
         while (tablica[i].prev != NULL and i < W) i++;
         temp = &tablica[i];
         cout << temp->a << endl;
         temp = temp->next;
         while (temp)
         {
             cout << temp->a << endl;
             temp = temp->next;
         }
         delete temp;
     }
     else 
          cout << "Lista jest pusta." << endl;
}
void wyswietl2(lista tablica[], int W, int* index)// wyswietlanie od konca
{
     if (*index != 0)
     {
         lista* temp;
         int i = 0;
         while (tablica[i].next != NULL and i < W) i++;
         temp = &tablica[i];
         cout << temp->a << endl;
         temp = temp->prev;
         while (temp)
         {
             cout << temp->a << endl;
             temp = temp->prev;
         }
         delete temp;     
     }
     else 
          cout << "Lista jest pusta." << endl;
}
lista* znajdz(lista tablica[], int W, int* index, int element)
{
     int i;
     for (i = 0; i < W; i++)
         if (tablica[i].a == element)
         {
             *index = i;
             return &tablica[i];
         }
     return NULL;
}
void usuwanie(lista tablica[], int W, int* index, int element)
{
     lista* temp;
     lista* pretemp;
     lista* posttemp;
     int indextemp, i;
     if (temp = znajdz(tablica,W,&indextemp,element))
     {
     if (*index > 0)
     {
         if (temp->prev == NULL)
         {
             posttemp = temp->next;
             posttemp->prev = NULL;
         }
         else if (temp->next == NULL)
         {
             pretemp = temp->prev;
             pretemp->next = NULL;
         }
         else
         {
             pretemp = temp->prev;
             posttemp = temp->next;
             pretemp->next = posttemp;
             posttemp->prev = pretemp;
         }
         for (i = indextemp; i < (*index)-1 and i < W; i++) tablica[i] = tablica[i+1];
         }
         (*index)--;
         cout << "Usunieto." << endl;
     }
     else
         cout << "brak takiego elementu na liscie." << endl;
}
lista* pobierz(lista tablica[], int W, int element)
{
     lista* temp;
     int i = 0;
     while (tablica[i].prev != NULL and i < W) i++;
     temp = &tablica[i];
     i = 0;
     while (i != element-1)
     {
         temp = temp->next;
         i++;
     }
     return temp;
}
int main()
{
    lista tablica[MAX];
    lista* element;
    int index = 0, i;
    char c;
    int n;
    do
    {
         cout << "LISTA " << MAX << " ELEMENTOWA" << endl;
         cout << "1. Dodaj nowy element do listy" << endl;
         cout << "2. Wyswietl liste od poczatku" << endl;
         cout << "3. Wyswietl liste od tylu" << endl;
         cout << "4. Usun element z listy" << endl;
         cout << "5. Wyszukaj liczbe w liscie" << endl;
         cout << "6. Pobierz n-ty element z listy" << endl;
         cout << "q  wyjscie" << endl;
         cin >> c;
         cout << endl;
         cout << endl;
         switch (c)
         {
                case '1' :
                     dodaj(tablica, MAX, &index);
                     break;
                case '2' :
                     wyswietl1(tablica, MAX, &index);
                     break;
                case '3' :
                     wyswietl2(tablica, MAX, &index);
                     break;
                case '4' :
                     cout << "Jaka liczbe chcesz usunac? ";
                     cin >> n;
                     usuwanie(tablica, MAX, &index, n);
                     break;
                case '5' :
                     cout << "Jaka liczbe chcesz wyszukac? ";
                     cin >> n;
                     if (znajdz(tablica,MAX,&i,n)) cout << "Liczba " << n << " znajduje sie na liscie" << endl;
                     break;
                case '6' :
                     do
                     {
                         cout << "Ktory element chcesz pobrac w kolejnosci rosnacej, n musi byc od 1 do " << MAX << endl;
                         cin >> n;
                     }
                     while (n < 1 or n > MAX);
                     element = pobierz(tablica,MAX,n);
                     cout << "Pobrany element to " << element->a << endl;
                     break;
                default:
                break;
         }
         cout << endl;
         cout << endl;
    }
    while (c != 'q');
    return 0;
}
