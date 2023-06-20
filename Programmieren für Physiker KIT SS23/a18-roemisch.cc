

#include <iostream>
#include <cstring>
using namespace std ;

char to_upper(char c)
{
    if (c>='a' and c<='z') return char(ch-'a'+'A') ; 
    else return c;
}

int value_roman_char( char c) 
{
    const int anzahl_rmn = 7 ;
    const char buchstabe[anzahl_rmn] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    const int  wert[anzahl_rmn]  = {  1,   5,  10,  50, 100, 500, 1000};

    for (int i = 0; i < anzahl_rmn; ++i) {
        if (to_upper(c) == buchstabe[i]) {
        return value[i];
    }
    }
    cout << "Unbekannte römische Zahl: " << c << endl ;
    return 0 ; 
}

int main()
{
    char rmn[100];
    cout << "Roemische Zahl eingeben: ";
    cin >> rmn;

    int sum = 0;
    int strlen = strlen(rmn);
    for (int i = 0; i < strlen; ++i)
    {
        int placeholder = value_roman_char(rmn[i]);
        if (i < len - 1) {
            if (placeholder < value_roman_char(rmn[i + 1])) {
                placeholder *= -1;
    }
}
	    sum += placeholder ;
    }
    cout << "In arabischen Zahlen: " << sum << endl ;
}
