#include <fstream>

using namespace std;
void aufgabe11()
{
    float playnumber[8];
    float jumps[8][6];
    float maxjumps[8] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
    float bestjump = 0.0;
    fstream myfile("a11-weitsprung.txt", ios_base::in);
    
    for (int i = 0; i < 8; i++) {
    myfile >> playnumber[i] >> jumps[i][0] >> jumps[i][1] >> jumps[i][2] >> jumps[i][3] >> jumps[i][4] >> jumps[i][5];

    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            if (maxjumps[i] < jumps[i][j]) {
               
                maxjumps[i] = jumps[i][j];

            }
       }
    }
    
    for (int i = 0; i < 8; i++) {
        if (bestjump < maxjumps[i]) {
            bestjump = maxjumps[i];
        }
    }
    for (int i = 0; i < 8; i++) {

        cout << "Spielernummer: " << playnumber[i] << " Spruenge: ";
        for(int j =0; j<6; j++ ){
            cout << setw(8) << jumps[i][j] << " ";
        }
        cout << "Beste Weite: " <<setw(8)<< maxjumps[i]; 
        if (maxjumps[i] == bestjump) {
            cout  << "   Champion!";
        }
        cout << endl;
    }

    

}