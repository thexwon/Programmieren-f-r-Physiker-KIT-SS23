

#include <iostream>
#include <cstring>
using namespace std;

char to_upper(char c)
{
    if (c >= 'a' and c <= 'z') return char(c - 'a' + 'A');
    else return c;
}

int value_roman_char(char c)
{
    const int anzahl_rmn = 7;
    const char buchstabe[anzahl_rmn] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    const int  wert[anzahl_rmn] = { 1,   5,  10,  50, 100, 500, 1000 };

    for (int i = 0; i < anzahl_rmn; ++i) {
        if (to_upper(c) == buchstabe[i]) {
            return wert[i];
        }
    }
    cout << "Unbekannte römische Zahl: " << c << endl;
    return 0;
}

void aufgabe16()
{
    char rmn[100];
    cout << "Roemische Zahl eingeben: ";
    cin >> rmn;

    int sum = 0;
    int strlength = strlen(rmn);
    for (int i = 0; i < strlength; ++i)
    {
        int placeholder = value_roman_char(rmn[i]);
        if (i < strlength - 1) {
            if (placeholder < value_roman_char(rmn[i + 1])) {
                placeholder *= -1;
            }
        }
        sum += placeholder;
    }
    cout << "In arabischen Zahlen: " << sum << endl;
}
