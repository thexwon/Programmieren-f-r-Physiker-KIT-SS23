/*
 * Programmieren fuer Physiker, SS 2023, Blatt 7, Aufgabe 17
 *
 * Permutationen in lexikographischer Ordnung generieren
 * (Fragment, zu ergaenzen)
 */

#include <iostream>
using namespace std ;

// die Funktionen next_permutation und swap sind zu ergaenzen

void swap(char wort[], int  l, int  k, int size) {

    int temp = wort[l];
        wort[l] = wort[k];
        wort[k] = temp;
      
        reverse(wort + k +1 , wort + size);
            
}

bool next_permutation(char wort[], int size) {
    int k = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (wort[i] < wort[i + 1]) {
            k = i;
            break;
        }
    }
        if (k == -1) {
            return false;
        }
        else {
            int l = -1;
            for (int i = size; i >= 0; i--) {
                if (wort[k] < wort[i]) {
                    l = i;
                    break;
                }
              
            }
            swap(wort, l, k, size);
            return true;




        }
    }

int aufgabe17()
{
    // Beispieldatensatz, muss sortiert vorliegen
    const int size=6 ;
    char wort[size] = { 'A','E','E','E','F','K'};

    cout << "Generierung aller Permutationen" << endl << endl ;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0 ;      // zaehle die Permutationen
    do
    {




	++anzperm ;
	cout << "Nr: " << anzperm << "  " ;
	for( int i=0; i<size; i++)
	    cout << wort[i] << " " ;
	cout << endl ;
    }
    while (next_permutation(wort, size))  ;

    cout << "Anzahl der Permutationen: " << anzperm << endl ; //n! ohne wiederholungen, n!/(w1!*w2!*...ws!) bei wiederholungen von s gruppen: binomialkoeffizient

    return 0 ;
}
