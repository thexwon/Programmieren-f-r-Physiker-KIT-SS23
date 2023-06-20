#include <iostream>
using namespace std;
void aufgabe4a()
{
    int N;
    int p = 1;
    cout << "Enter integer N to sum up to: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        p *= (2 * i + 1);
        cout << p <<"\n";
    }


}
void aufgabe4b()
{

    int N;
    float p = 0;
    cout << "Enter integer N to sum up to: ";
    cin >> N;

    for (int i = N; i <= 2*N; i++) {
        for (int j = 1; j <= i; j++) {
            p += 1.0 / (i * j);
                                     }
                                }
    cout << "the double sum yields " << p;
}