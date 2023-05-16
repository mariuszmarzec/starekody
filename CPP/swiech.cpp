#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#define N 10
using namespace std;
namespace myspace
{
class samochod;
class ciezarowy;
class czolg;
class baza;
// KLASA POJAZD
class pojazd
{
      protected:
              float x;
              int masa;
              float v;
              string marka;

      public:
            class silnik
            {
                private:
                        int moc;
                        float przyspieszenie;
                        int v_max;
                public:
                        silnik();
                        void dane();
                        float predkosc_max();
                        float a();
            };
             string podaj_nazwe();
             virtual void opcje() = 0;
             virtual void specjalne() = 0;
             virtual void ruch() = 0;
             virtual void specyfikacja() = 0;
};
//KLASA PROGRAM
class program
{
      private:
              int l;
              pojazd* tablica[N];
              baza* wskbaza;
      public:
             program();
             void edycja_bazy();
             void usun_pojazd(int);
             void progmain();
             void wypisz_pojazdy();
             void tworzenie_aut();
};
//KLASA BAZA MAREK
class baza
{
      friend class samochod;
      friend class ciezarowy;
      private:
              vector <string> marki;
              string plik_nazwa;
              bool zapisz();
      public:
             baza (const string&);
             void zaladuj();
             void wyswietl();
             void dodaj();
             void usun();
             bool czy_jest(const string&);
};
// KLASA PACZKA
class paczka
{
      private:
              string zawartosc;
              int masa;
      public:
             paczka(string, int);
             void wrzuc();
             int podaj_mase();
             string co_w_paczce();
             friend paczka operator + (const paczka&, const paczka&);
             friend ostream & operator << (ostream&, const paczka&);
             paczka& operator = (const paczka&);    
};

// KLASA SAMOCHOD
class samochod : public pojazd
{
      protected:
            baza* wskbaza_marek;
            silnik* wsksilnik;
      public:
            samochod(baza& baza_marek);
            string pobierz();
            void opcje();
            void specjalne();
            void ruch();
            void specyfikacja();
            ~samochod();
            
};
// KLASA SAMOCHOD
class ciezarowy : public samochod
{
      private:
              int towar_max;
              int towar;
              vector <paczka> paczki;
      public:
            ciezarowy(baza& baza_marek);
            void opcje();
            void specjalne();
            void ruch();
            void specyfikacja();
            ~ciezarowy();
};
// KLASA CZOLG
class czolg : public pojazd
{
      private:
              int nachylenie;
      public:
                czolg();
                void opcje();
                void specjalne();
                void ruch();
                void specyfikacja();
};
//FUNKCJE BAZA MAREK
baza::baza(const string& nazwa_pliku)
{
    plik_nazwa = nazwa_pliku;
    zaladuj();
}
void baza::zaladuj()
{
    fstream plik;
    string bufor;
    plik.open(plik_nazwa.c_str(), ios::in);
    if(plik.good())
    {
        while(!plik.eof())
        {
            getline(plik,bufor);
            if (bufor != "")
               marki.push_back(bufor);
        }
        if (marki.size() == 0)
           marki.push_back("domyslna");
    plik.close();
    }
    else
    {
        cout<<"Nie moge zaladowac pliku baza.txt"<<endl;
    }
}
void baza::wyswietl()
{
     int i ,w = marki.size();
     for (i = 0; i < w; i++) cout << i << ". "<< marki[i] << endl;
}
void baza::dodaj()
{
     string nowa;
     cout << "Podaj nazwe nowej marki: " << endl;
     cin >> nowa;
     if (!czy_jest(nowa))
     {
         marki.push_back(nowa);
         if (zapisz())
            cout << "Zapisano nowa marke." << endl;
         else
         {
             marki.pop_back();
             cout << "Nie powiodlo sie dodanie nowej marki do bazy." << endl;
         }
     }
     else
         cout << "Ta marka juz istnieje." << endl;
}
bool baza::zapisz()
{
    fstream plik;
    int i, w;
    plik.open(plik_nazwa.c_str(), ios::out);
    if (plik.good())
    {
        w = marki.size();
        for (i = 0; i < w; i++)
        plik << marki[i] << endl;
    }
    else return false;
    return true;
}
bool baza::czy_jest(const string& marka)
{
    int i, w = marki.size();
    for (i = 0; i < w; i++)
        if (marki[i] == marka) return true;
    return false;
}
void baza::usun()
{
     int i, n, w = marki.size();
     vector <string> temp = marki;
     wyswietl();
     cout << "Podaj indeks marki ktora chcesz usunac:" << endl;
     do
     {
         cin >> n;
     }
     while (n < 0 or n > w);
     marki.clear();
     for (i = 0; i < w; i++)
         if (n != i) marki.push_back(temp[i]);
     if (marki.size() == 0)
         marki.push_back("domyslna");
     zapisz();
     cout << "usunieto element z bazy marek" << endl;
}
// FUNKCJE KLASY POJAZD
string pojazd::podaj_nazwe()
{
       return marka;
}
// FUNKCJE KLASY SAMOCHOD
samochod::samochod(baza& baza_marek)
{
   x = 0;
   v = 0;
   string model;
   wskbaza_marek = &baza_marek;
   marka = pobierz();
   cout << "Podaj model:" << endl;
   cin >> model;
   marka += " "+model;
   cout << "Podaj mase samochodu w kg (> 0):" << endl;
   do
   {
        cin >> masa;
   }
   while (masa <= 0);;
   wsksilnik = new silnik;
}
void samochod::opcje()
{
     cout << endl;
     cout << "1. Wymiana silnika" << endl;
     cout << "2. Pokaz specyfikacje" << endl;
     cout << "3. Przejedz sie" << endl;
     cout << "4. Wroc do magazynu" << endl;
     cout << endl;
}
void samochod::specyfikacja()
{
     cout << endl;
     cout << "Samochod" << endl;
     cout << marka << endl;
     cout << "masa - " << masa << endl;
     wsksilnik->dane();
}
string samochod::pobierz()
{
     int n, w = wskbaza_marek->marki.size();
     wskbaza_marek->wyswietl();
     cout << "Podaj indeks wybranej marki:" << endl;
     do
     {
         cin >> n;
     }
     while (n < 0 or n > w);
     return wskbaza_marek->marki[n];
}
void samochod::ruch()
{
     char z;
     int t;
     int i;
     float vt;
     float a = wsksilnik->a();
     do
     {
         cout << endl;
         cout << marka << " jest na " << x << " metrze toru" << endl;
         cout << "obecna predkosc = " << v << "m/s" << endl << endl;
         cout << "1. wcisnij pedal gazu" << endl;
         cout << "2. zwalniaj" << endl;
         cout << "3. jedz ze stala predkoscia" << endl;
         cout << "4. wyjdz z samochodu" << endl;
         cin >> z;
         if (z != '4')
         {
             do
             {
                 cout << "Podaj w sekundach jak dlugo tak bedziesz jechac t > 0" << endl;
                 cin >> t;
             }
             while (t <= 0);
             switch (z)
             {
                    case '1' :
                         i = 1;
                         vt = v;
                         while (vt < wsksilnik->predkosc_max() and i <= t)
                         {
                               vt = a*i;
                               i++;
                         }
                         x += v*i + a*i*i/2;
                         if (vt > wsksilnik->predkosc_max())
                         {
                             v =  wsksilnik->predkosc_max();
                             t -= i;
                             x += v*t;
                         }
                         else
                         {
                             v = vt;
                         }
                         break;
                    case '2' :
                         i = 1;
                         vt = v;
                         while (vt > 0 and i <= t)
                         {
                               vt -= a/2*i;
                               i++;
                         }
                         --i;
                         x += v*i- a/2*i*i/2;
                         v = 0;
                         break;
                    case '3' :
                         x += v*t;
                         break;
                    default:
                         break;
             }
         }
     }
     while (z != '4');
     v = 0;
     x = 0;
}
void samochod::specjalne()
{
     char z;
     do
     {
          cout << endl;
          cout << "Wymiana silnika" << endl;
          cout << "czy na pewno chcesz wymienic silnik?(t/n)" << endl;
          cin >> z;
          if (z == 't')
          {
                cout << "Usunieto stary silnik" << endl;
                wsksilnik = NULL;
                wsksilnik = new silnik;
                cout << "Wlozono nowy silnik" << endl;
                z = 'n';
          }
     }
     while (z != 'n');
}
samochod::~samochod()
{
    delete wskbaza_marek;
    delete wsksilnik;
}
//FUNKCJE KLASY PACZKA
paczka::paczka(string zawartosc_towaru = "", int masa_towaru = 0) : zawartosc(zawartosc_towaru), masa(masa_towaru)
{
}
void paczka::wrzuc()
{
     cout << "Co znajduje sie w paczce" << endl;
     cin >> zawartosc;
     cout << "Podaj wage" << endl;
     cin >> masa;
}
int paczka::podaj_mase()
{
    return masa;
}
string paczka::co_w_paczce()
{
    return zawartosc;
}
paczka operator+(const paczka& paczka1, const paczka& paczka2)
{
    string zawartosc = paczka1.zawartosc == paczka2.zawartosc ? paczka1.zawartosc : paczka1.zawartosc+" i "+paczka2.zawartosc;
    return paczka(zawartosc, paczka1.masa+paczka2.masa);
}
ostream & operator << (ostream &wyjscie, const paczka & paczka1)
{
       return wyjscie << "Zawartosc: " <<paczka1.zawartosc << endl << "Masa: " <<paczka1.masa << endl;
}
paczka& paczka::operator = (const paczka& paczka1)
{
       zawartosc = paczka1.zawartosc;
       masa = paczka1.masa;
       return *this;
}
// FUNKCJE KLASY SILNIK
samochod::silnik::silnik()
{
   cout << "Podaj moc silnika w koniach mechanicznych (> 0):" << endl;
   do
   {
        cin >> moc;
   }
   while (moc <= 0);
   cout << "Podaj w ile do 100 km/h rozpedzi sie samochod z tym silnikiem (> 0):" << endl;
   do
   {
        cin >> przyspieszenie;
   }
   while (przyspieszenie <= 0);
   przyspieszenie = 1000/ (36*przyspieszenie);
   cout << "Podaj predkosc maxymalna km/h (> 0):" << endl;
   do
   {
        cin >> v_max;
   }
   while (v_max <= 0);
   v_max = v_max*1000/3600;
}
void samochod::silnik::dane()
{
     cout << "moc - " << moc << "KM" << endl;
     cout << "przyspieszenie - " << przyspieszenie << " m/s^2" << endl;
     cout << "predkosc max - " << v_max << " m/s" << endl;
}
float samochod::silnik::predkosc_max()
{
    return v_max;
}
float samochod::silnik::a()
{
      return przyspieszenie;
}
//FUNKCJE KLASY CIEZAROWY
ciezarowy::ciezarowy(baza& baza_marek) : samochod(baza_marek)
{
   towar = 0;
   cout << "Podaj maksymalny ciezar towaru w kg (> 0):" << endl;
   do
   {
        cin >> towar_max;
   }
   while (towar_max <= 0);
}
void ciezarowy::opcje()
{
     cout << endl;
     cout << "1. Zaladuj" << endl;
     cout << "2. Pokaz specyfikacje" << endl;
     cout << "3. Przejedz sie" << endl;
     cout << "4. Wroc do magazynu" << endl;
     cout << endl;
}
void ciezarowy::ruch()
{
     char z;
     float t;
     float i;
     float vt;
     float a;
     do
     {
         cout << endl;
         cout << marka << " jest na " << x << " metrze toru" << endl;
         cout << "obecna predkosc = " << v << "m/s" << endl << endl;
         cout << "Kazde dodatkowe 500 kg towaru obniza przyspieszenie ciezarowki o 5%" << endl;
         cout << "waga towaru " << towar <<"/" << towar_max << endl;
         cout << "1. wcisnij pedal gazu" << endl;
         cout << "2. zwalniaj" << endl;
         cout << "3. jedz ze stala predkoscia" << endl;
         cout << "4. wypakuj/wpakuj towar" << endl;
         cout << "5. wyjdz z samochodu" << endl;     
         if (towar != 0)
            a -= (wsksilnik->a())*towar/500/20;
         else
             a = wsksilnik->a();
         if (a < 0)
         {
             a = 0;
             cout << "Zbyt duze obciazenie, przyspieszenie spada do 0" << endl;
         }
         if (towar > towar_max)
         {
             cout << "Przekroczono limit ladownosci, auto nie pojedzie" << endl;
             v = 0;
         }
         cin >> z;
         if (z != '5' and z != '4')
         {
             do
             {
                 cout << "Podaj w sekundach jak dlugo tak bedziesz jechac t > 0" << endl;
                 cin >> t;
             }
             while (t <= 0);
             switch (z)
             {
                    case '1' :
                         i = 1;
                         vt = v;
                         while (vt < wsksilnik->predkosc_max() and i <= t)
                         {
                               vt = a*i;
                               i++;
                         }
                         --i;
                         x += v*i + a*i*i/2;
                         if (vt > wsksilnik->predkosc_max())
                         {
                             v =  wsksilnik->predkosc_max();
                             t -= i;
                             x += v*t;
                         }
                         else
                         {
                             v = vt;
                         }
                         break;
                    case '2' :
                         i = 1;
                         vt = v;
                         while (vt > 0 and i <= t)
                         {
                               vt -= a/2*i;
                               i++;
                         }
                         --i;
                         x += v*i - a/2*i*i/2;
                         v = 0;
                         break;
                    case '3' :
                         x += v*t;
                         break;
                    default:
                         break;
             }
         }
         else if (z == '4')
            specjalne();
     }
     while (z != '5');
     v = 0;
     x = 0;
}
void ciezarowy::specyfikacja()
{
     cout << endl;
     cout << "Samochod ciezarowy" << endl;
     cout << marka << endl;
     cout << "masa - " << masa << endl;
     cout << "waga / maksymalna waga towaru" << towar << "/" << towar_max << endl;
     wsksilnik->dane();
}
void ciezarowy::specjalne()
{
     int z;
     char c;
     paczka* temp;
     do
     {
         cout << endl;
         cout << "Wypakunek z " << marka << endl;
         cout << "waga towaru " << towar << "/" << towar_max << endl;
         cout << "Pamietaj ze wrzucona paczka na poczatku zostanie przylozona nowymi" << endl;
         cout << endl;
         cout << "1. Wrzuc paczke" << endl;
         cout << "2. wyrzuc paczke" << endl;
         cout << "3. wyjdz" << endl;
         cin >> z;
         switch (z)
         {
                case 1 :
                     
                     temp = new paczka();
                     temp->wrzuc();
                     towar += temp->podaj_mase();
                     paczki.push_back(*temp);
                     cout << "Dodano nowa paczke." << endl;
                     cout << *temp;
                     cout << endl;
                     delete temp;
                     break;
                case 2 :
                     if (paczki.size() > 0)
                     {
                         cout << "Czy chcesz usunac paczke?" << endl;
                         cout << paczki[paczki.size()-1];
                         cout << endl;
                         cout << "t - tak, n - nie" << endl;
                         do
                           cin >> c;
                         while (c != 't' and c != 'n');
                         if (c == 't')
                         {
                             towar -= paczki[paczki.size()-1].podaj_mase();
                             paczki.pop_back();
                             cout << "Usunieto " << endl;
                         }
                     }
                     else
                     {
                         cout << "Brak paczek do usunieca, wcisnij cokolwiek by wyjsc" << endl;
                         getch();
                     }
                     break;
                default:
                     break;
         }
     }
     while (z != 3);
}
ciezarowy::~ciezarowy()
{
    delete wskbaza_marek;
    delete wsksilnik;
}
// KLASA CZOLG
czolg::czolg()
{
    x = 0;
    nachylenie = 45;
    cout << "Podaj nazwe czolgu:" << endl;
    cin >> marka;
    cout << "Podaj mase czolgu w kg (> 0):" << endl;
    do
    {
        cin >> masa;
    }
    while (masa < 0);
    cout << "Podaj predkosc czolgu (> 0):" << endl;
    do
    {
        cin >> v;
    }
    while (v <= 0);
    v = v*1000/3600;
}
void czolg::opcje()
{
     cout << endl;
     cout << "1. Strzelaj" << endl;
     cout << "2. Pokaz specyfikacje" << endl;
     cout << "3. Przejedz sie" << endl;
     cout << "4. Wroc do magazynu" << endl;
     cout << endl;
}
void czolg::specjalne()
{
     int c;
     float m;
     do
     {
        cout << endl;
        cout << "Strzelanie z czolgu "<< marka << endl; 
        cout << "pozycja " << x << " nachylenie lufy " << nachylenie << " stopni" << endl;  
        cout << "1. zmien kat nachylenia" << endl;
        cout << "2. wystrzel" << endl;
        cout << "3. wyjscie" << endl;
        cin >> c;
        switch (c)
        {
               case 1 :
                    cout << "Podaj kat nachylenia lufy (0 < a < 90)" << endl;
                    cin >> nachylenie;
                    cout << "Nowe nachylenie" << endl;
                    break;
               case 2 :
                    m = x + 400*400*2*sin(2*3.14*static_cast<float>(nachylenie)/180);
                    cout << "Pocisk wystrzelony z " << x << " metra dolecial na odleglosc " << m << " metrow" << endl;
                    break;
               default:
                    break;
        }
     }
     while (c != 3);
}
void czolg::ruch()
{
     int z;
     int t;
     do
     {
         cout << endl;
         cout << marka << " jest na " << x << " metrze toru" << endl;
         cout << "Porusza sie z stala predkoscia = " << v << "m/s" << endl << endl;
         cout << "1. jedz" << endl;
         cout << "2. cofnij sie" << endl;
         cout << "3. strzelaj" << endl;
         cout << "4. wyjdz z czolgu" << endl;
         cin >> z;
         if (z != 4 and z != 3)
         {
               cout << "Podaj czas jazdy: " << endl;
               cin >> t;
               switch (z)
               {
                      case 1 :
                           x += v*t;
                           break;
                      case 2 :
                           x -= v*t;
                           break;
                      default:
                           break;
               }
         } 
         else if (z == 3)
         {
              specjalne();
         }
     }
     while (z != 4);
}
void czolg::specyfikacja()
{
    cout << endl;
    cout << "Czolg" << endl;
    cout << marka << endl;
    cout << "masa - " << masa << endl;
    cout << "Nachylenie lufy w stopniach" << nachylenie << endl;
}
// FUNKCJE KLASY PROGRAM
program::program()
{
   l = 0;               
   wskbaza = new baza("baza.txt");
}
void program::progmain()
{
     char c;
     int z;
     int n;
     do
     {
         cout << endl << endl;
         cout << "MAGAZYN" << endl;
         if (l == 0)
            cout << "Magazyn jest pusty" << endl;
         else
             wypisz_pojazdy();
         cout << "0. Edytuj baze marek" << endl;
         cout << "1. Dodaj pojazd" << endl;
         cout << "2. Usun pojazd" << endl;
         cout << "3. Uzyj pojazd" << endl;
         cout << "q. Wyjdz" << endl; 
         c = getch();
         switch (c)
         {
                case '0' :
                     edycja_bazy();
                     break;
                case '1' :
                     if (l == N-1)
                     {
                        cout << "Magazyn jest pe³ny, wcisnij cokolwiek by wyjsc." << endl;
                        getch();
                     }
                     else
                         tworzenie_aut();
                     break;
                case '2' :
                     if (l == 0)
                     {
                        cout << "Magazyn jest pusty, klinij cokolwiek by wyjsc." << endl;
                        getch();
                     }
                     else
                     {
                         wypisz_pojazdy();
                         cout << "Wpisz nr indeksu pojazdu, ktory ma byc usuniety" << endl;
                         do
                         {
                              cin >> n;
                         }
                         while (n < 0 or n > l);
                         usun_pojazd(n);
                         cout << "usunieto";                    
                     }
                     break;
                case '3' :
                     cout << "Wpisz nr indeksu pojazdu, ktorego chcesz uzyc" << endl;
                     do
                     {
                          cin >> n;
                     }
                     while (n < 0 or n > l);
                     do
                     {
                         tablica[n]->opcje();
                         cin >> z;
                         switch (z)
                         {
                                case 1:
                                     tablica[n]->specjalne();
                                     break;
                                case 2:
                                     tablica[n]->specyfikacja();
                                     break;
                                case 3:
                                     tablica[n]->ruch();
                                     break;
                                default:
                                     break;
                         }
                     }
                     while (z != 4);
                     break;
                default:
                     break;
         }
         cout << endl << endl;
     }
     while (c != 'q');
}
void program::wypisz_pojazdy()
{
     int i;
     for (i = 0; i < l; i++)
         cout << i << ". " << tablica[i]->podaj_nazwe() << endl;
}
void program::tworzenie_aut()
{
     int z;
     do
     {
         cout << endl;
         cout << "TWORZENIE POJAZDU" << endl;
         cout << "Wybierz rodzaj pojazdu" << endl;
         cout << "1. Samochod" << endl;
         cout << "2. Ciezarowka" << endl;
         cout << "3. czolg" << endl;
         cout << "4. Wyjdz" << endl; 
         cin >> z;
         switch (z)
         {
                case 1 :                    
                     tablica[l++] = new samochod(*wskbaza);
                     cout << "utworzono" << endl;
                     break;
                case 2 :
                     tablica[l++] = new ciezarowy(*wskbaza);
                     cout << "utworzono" << endl;                     
                     break;
                case 3 :
                     tablica[l++] = new czolg;
                     cout << "utworzono" << endl;
                     break;
                default:
                     break;
         }
         cout << endl;
     }
     while (z != 4);    
}
void program::usun_pojazd(int x)
{
     if (x != N-1) 
     {
         int i;
         for (i = x; i < N-1 and i <= l; i++)
         {
             tablica[i] = tablica[i+1];
         }
     }
     l--;
}
void program::edycja_bazy()
{
     int z;
     do
     {
         cout << endl;
         cout << "EDYCJA BAZY" << endl;
         cout << endl;
         wskbaza->wyswietl();
         cout << endl;
         cout << "1. dodaj nowy element" << endl;
         cout << "2. usun element bazy" << endl;
         cout << "3. Wyjdz" << endl; 
         cin >> z;
         switch (z)
         {
                case 1 :
                     wskbaza->dodaj();             
                     break;
                case 2 :
                     wskbaza->usun();             
                     break;
                default:
                     break;
         }
         cout << endl;
     }
     while (z != 3);      
}

}
using namespace myspace;
int main()
{
    program prog; 
    prog.progmain();
    return 0;
}
/*
 // Przyklad uzycia przeciazonych operatorow dla classy paczka wkleic do main w celu uzycia
    paczka murzyny("murzyny", 400);
    paczka wodkie("wodkie", 550);
    paczka paka = murzyny + murzyny;
    paka = paka + wodkie;
    paczka paka2 = paka;
    cout << paka2;

*/
