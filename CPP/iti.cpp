#include <iostream>
using namespace std;
class pojazd
{
     protected:
             int masa;
             int _x, _y;
             int predkosc;
             int kierunek; // 0 - lewa 1 - w gore 2 - w prawo 3 - w dol
     public:
            pojazd()
            {
                    cout << "podaj mase" << endl;
                    cin >> masa;
                    cout << "podaj polozenie" << endl;
                    cin >> _x;
                    cin >> _y;
                    cout << "podaj predkosc" << endl;
                    cin >> predkosc;
                    cout << "podaj kierunek 0 - lewa 1 - w gore 2 - w prawo 3 - w dol" << endl;
                    do
                    {
                    cin >> kierunek;
                    }
                    while (kierunek < 0 or kierunek > 4);
            }
            void przyspiesz(int nowa_v) {predkosc = nowa_v;}
            void zmien_kierunek() 
            {
                 kierunek = 5;
                 cout << "podaj nowy kierunek 0 - lewa 1 - w gore 2 - w prawo 3 - w dol" << endl;
                    do
                    {
                    cin >> kierunek;
                    }
                    while (kierunek < 0 or kierunek > 4);
            }
            void jedz(int czas)
            {
                 if (kierunek == 0) nowe_wsp(_x-predkosc*czas,_y);
                 else if (kierunek == 1)  nowe_wsp(_x,_y+predkosc*czas);
                 else if (kierunek == 2)  nowe_wsp(_x+predkosc*czas,_y);
                 else  nowe_wsp(_x,_y-predkosc*czas);
            }
             int X() {return _x;}
             int Y() {return _y;}
             void nowe_wsp(int x, int y)
             {
                          _x = x;
                          _y = y;
             }
             int podaj_mase() {return masa;}
             
};
class quad : public pojazd
{
 private:
      int ryk_silnika;
      float promile_pasazerow;      
    public:
      quad()
      {
                cout << "podaj ryk silnika" << endl;
                cin >> ryk_silnika;
                cout << "podaj promilepasazerow" << endl;
                cin >> promile_pasazerow;
      }
      void staranuj_swistaka() {cout << "Staranowano swistaka, nie zagra juz na skrzypcach" << endl;}
      void rozjedz_ropuche() {cout << "Rozjechano ropuche, nie bedzie z niej ksiecia" << endl;}
      void podaj_alkohol_pasazerom() {promile_pasazerow += 0.1;}
      float stan_upojenia() {return promile_pasazerow;}
      int jaki_ryk_silnika() {return ryk_silnika;}
      
};
int main()
{
    quad chinski;
    chinski.przyspiesz(200);
    chinski.zmien_kierunek();
    chinski.jedz(20);
    cout << "chinski jest teraz w punkcie " << chinski.X() << " " << chinski.Y() << endl;
    chinski.podaj_alkohol_pasazerom();
    cout << "Odczyt alkomatu podczas badania stanu trzezwosci: " << chinski.stan_upojenia() << endl;
    chinski.rozjedz_ropuche();
    chinski.staranuj_swistaka();
    system("PAUSE");
    return 0;
}
