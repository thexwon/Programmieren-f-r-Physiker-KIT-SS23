#include <cstdlib>
#include <iostream>
using namespace std;


void swap(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

int Partition(double list[],int s,int t)

{
    double pivot = list[s]; //einfachster fall: pivot = erstes element
    int l = s;
    for (int i = s + 1; i <= t; i++)
        if (list[i] < pivot)
        {
            l++;
            swap(list[i], list[l]);
        }
    swap(list[s], list[l]);
    return l;
}
void QuickSort(double list[], const int s, const int t) {

    if (t <= s) { //keine elemente zum sortieren übrig
        return;
    }
    int pivotindex = Partition(list, s, t); // partionierung wie auf dem Blatt

    QuickSort(list, s, pivotindex - 1); //aufspaltung in zwei sortierte listen mit <=m
    QuickSort(list, pivotindex + 1, t); //>=m
}
void printlist(double list[], int size) {
        cout << endl;
        cout << "size of the list: " << size << endl;
        cout << "elements: ";
        for (int i = 0; i < size; ++i)
            cout << list[i] << "  ";
        cout << endl << endl;

}
void aufgabe21(){
    const int size = 20;
    double list[size];
    for (int i = 0; i < size; i++) {

        list[i] = double(rand()) / RAND_MAX;  //werte zwischen 0 und 1
    }
    cout << "randomly generated list:" << endl;
    printlist(list, size);
    cout << "what part of the list do you want to order? " << endl;
    cout << "enter start of ordering index" << endl;
    int s, t;
    cin >> s;
    cout << "enter end of ordering index" << endl;
    cin >> t;
    QuickSort(list, s, t);
    cout << "the list was sorted. Results: " << endl;
    printlist(list, size);

}






