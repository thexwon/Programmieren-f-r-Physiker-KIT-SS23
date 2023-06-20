#include <iostream>

using namespace std;

void aufgabe5() {

    double N;
    double p = 1.0;
    double temp;
    cout << "Enter integer N to sum up to: ";
    cin >> N;

    for (N; N > 0; N--) {
        temp = p;
        p *=  N / (2.0*N + 1.0);
        p += 1.0;
        cout << p - temp << endl;
    }
    cout <<"p:" << p << endl;
    cout << "2p:" << 2 * p << endl;
}
