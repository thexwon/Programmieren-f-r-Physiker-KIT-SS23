#include <iostream>
#include <iomanip> 

using namespace std;

void aufgabe8() {

    int zeile[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int zeiletmp[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    for (int n = 0; n < 10; n++) {
        copy(zeile, zeile + n, zeiletmp);
        zeile[0] = 1;
        zeile[n] = 1;
        for (int k = 1; k <= n - 1; k++) {
            zeile[k] = zeiletmp[k - 1] + zeiletmp[k];
        }
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                cout << setw(40 - 4 * n) << zeile[j];
            }
            else {
                cout << setw(8) << zeile[j];
            }
            
            if(j == n){
                cout << "\n";
            }
        }
    }
}
