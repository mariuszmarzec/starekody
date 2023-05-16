#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    const int w = 250;
    int i;
    char lac[w];
    cin.getline(lac, w);
    for (i = 0; lac[i]; i++)
    {
        if ( lac[i] == 'A' or lac[i] == 'a') cout << ".-";
        else if (lac[i] == 'B' or lac[i] == 'b') cout << "-...";
        else if (lac[i] == 'C' or lac[i] == 'c') cout << "-.-.";
        else if (lac[i] == 'D' or lac[i] == 'd') cout << "-..";
        else if (lac[i] == 'E' or lac[i] == 'e') cout << ".";
        else if (lac[i] == 'F' or lac[i] == 'f') cout << "..-.";
        else if (lac[i] == 'G' or lac[i] == 'g') cout << "--.";
        else if (lac[i] == 'H' or lac[i] == 'h') cout << "....";
        else if (lac[i] == 'I' or lac[i] == 'i') cout << "..";
        else if (lac[i] == 'J' or lac[i] == 'j') cout << ".---";
        else if (lac[i] == 'K' or lac[i] == 'k') cout << "-.-";
        else if (lac[i] == 'L' or lac[i] == 'l') cout << ".-..";
        else if (lac[i] == 'M' or lac[i] == 'm') cout << "--";
        else if (lac[i] == 'N' or lac[i] == 'n') cout << "-.";
        else if (lac[i] == 'O' or lac[i] == 'o') cout << "---";
        else if (lac[i] == 'P' or lac[i] == 'p') cout << ".--.";
        else if (lac[i] == 'Q' or lac[i] == 'q') cout << "--.-";
        else if (lac[i] == 'R' or lac[i] == 'r') cout << ".-.";
        else if (lac[i] == 'S' or lac[i] == 's') cout << "...";
        else if (lac[i] == 'T' or lac[i] == 't') cout << "-";
        else if (lac[i] == 'U' or lac[i] == 'u') cout << "..-";
        else if (lac[i] == 'V' or lac[i] == 'v') cout << "...-";
        else if (lac[i] == 'W' or lac[i] == 'w') cout << ".--";
        else if (lac[i] == 'X' or lac[i] == 'x') cout << "-..-";
        else if (lac[i] == 'Y' or lac[i] == 'y') cout << "-.--";
        else if (lac[i] == 'Z' or lac[i] == 'z') cout << "--..";
        else if (lac[i] == '0') cout << "-----";
        else if (lac[i] == '1') cout << ".----";
        else if (lac[i] == '2') cout << "..---";
        else if (lac[i] == '3') cout << "...--";
        else if (lac[i] == '4') cout << "....-";
        else if (lac[i] == '5') cout << ".....";
        else if (lac[i] == '6') cout << "-....";
        else if (lac[i] == '7') cout << "--...";
        else if (lac[i] == '8') cout << "---..";
        else if (lac[i] == '9') cout << "----.";
        cout << "/";
    }
    cout << endl;
    getch();
    return 0;
}
