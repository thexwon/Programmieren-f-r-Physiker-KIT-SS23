#include <fstream>
#include <iostream>
#include <string>
using namespace std;




inline void swaplines(double A[][10], double b[10], int size, int i, int k) {
    double temp;
    if (i + k < size) {
    for (int j = 0; j < size; j++) {

        temp = A[i][j];

        A[i][j] = A[i + k][j];
        A[i + k][j] = temp;

    }
    temp = b[i];
    b[i] = b[i + k];
    b[i + k] = temp;
    cout << "swapping lines" << endl;
}
}
inline void prepareLine(double A[][10], double b[10], int size, int i) {
    double factor = A[i][i];
    for (int j=0; j < size; j++) {
        A[i][j] = A[i][j] / factor;
    }
    b[i] = b[i] / factor;
    cout << "normalizing diagonal element to 1" << endl;


}
inline void addlines(double A[][10], double b[10], int size, int i) { //i ist die diagonale
    double faktor;
    for (int k = 1; k + i < size; k++){
        faktor = A[i + k][i];
        for (int j = 0; j < size; j++) {
            A[i + k][j] = A[i + k][j] - A[i][j] * faktor;
        }
        b[i + k] = b[i + k] - b[i] * faktor;
    }
    cout << "adding lines" << endl;

    
}
inline void showCurrentMatrix(double A[][10], double b[10], int size) {


    cout << "A*x = b" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(10) << A[i][j];
        }
        cout << " | " << setw(10) << b[i] << endl;
    }



}
inline void applyPivot(double A[][10], double b[10], int size, int i) { //nach größtem element der spalte suchen, dieses Element in die obere Zeile verschieben
 
    double max = A[i][i];
    for (int k = 0; i + k < size; k++) {
        if (max < A[i + k][i]) {
            max = A[i + k][i];
            swaplines(A, b, size, i, k);

        }

    }
    cout << "pivotpoint, max element: " << max<< endl;


}
inline void showResults(double A[][10], double b[10], int size) {
    cout << "diagonalizing matrix" << endl;
    for (int i = size - 1; i >= 0; i--) { //diagonal element
        double faktor;
        for (int k = 1; i - k >= 0; k++) {
            faktor = A[i - k][i];

            for (int j = size - 1; j >= 0; j--) {
                A[i - k][j] = A[i - k][j] - A[i][j] * faktor;
            }
            b[i - k] = b[i - k] - b[i] * faktor;
        }
        showCurrentMatrix(A, b, size);
    }
    cout << "final results" << endl;
    showCurrentMatrix(A, b, size);

}
inline void pivot(double A[][10], double b[10], int size) {
    for (int i = 0; i < size; i++) {
        int k = 0;
        while (A[i][i] == 0) {            //prüfen ob das aktuelle Diagonal element 0 ist, mit unterer zeile tauschen falls ja
            swaplines(A, b, size, i, k);
            showCurrentMatrix(A, b, size);
            k++;
            if (i + k == size - 1) {

                break;
            }
        }
        showCurrentMatrix(A, b, size);
        applyPivot(A, b, size, i);
        showCurrentMatrix(A, b, size);
        prepareLine(A, b, size, i);
        showCurrentMatrix(A, b, size);
        addlines(A, b, size, i);
        showCurrentMatrix(A, b, size);
    }
    showResults(A, b, size);
}
inline void gauss(double A[][10], double b[10], int size) {
    for (int i = 0; i < size; i++) { 
        int k = 0;
        while (A[i][i] == 0) {            //prüfen ob das aktuelle Diagonal element 0 ist, mit unterer zeile tauschen falls ja
            swaplines(A, b, size, i, k);
            showCurrentMatrix(A, b, size);
                k++;
                if (i+k == size - 1) {
                    cout << "diagonal elements 0; matrix not solveable";
                        break;
            }
        }
        prepareLine(A, b, size, i);
        showCurrentMatrix(A, b, size);
        addlines(A, b, size, i);
        showCurrentMatrix(A, b, size);
    }
    showResults(A, b, size);
}


void aufgabe13() {
    cout <<endl<<  "a13-test.txt, or a13-lgs1.txt, a13-lgs2.txt ?" << endl;
    string choice;
    cin >> choice;
    fstream myfile(choice, ios_base::in);
  /*  if (choice == 1) {
        cout << choice;
        fstream myfile("a13-lgs1.txt", ios_base::in);
    }
    if (choice == 2) {
        cout << choice;
        fstream myfile("a13-lgs2.txt", ios_base::in);
    }
    else {
        fstream myfile("a13-test.txt", ios_base::in);
    }
    */

    int size;
    myfile >> size;
    double A[10][10];
    double b[10];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            myfile >> A[i][j];
                                        }   
                  }
    for (int i = 0; i < size; i++) {
        myfile >> b[i];
    }
    showCurrentMatrix(A, b, size);
    cout << "Loesen mit Spaltenpivotisierung? (y/n)" << endl;
    char c;
    cin >> c;
    if (c == 'y') {
        cout << "y"<< endl;
        pivot(A, b,size);
    }
    else if (c == 'n') {
        cout << "n"<< endl;
        gauss(A, b, size);
    }
    else {
        cout << "invalid option"<< endl;
    }
}