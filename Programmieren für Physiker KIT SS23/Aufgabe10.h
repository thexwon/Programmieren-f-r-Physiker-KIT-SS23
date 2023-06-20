#include <iostream>

using namespace std;

void aufgabe10() {
	long a_1;
	long a;
	long amax;
	cout << "Enter a value for a_1: ";
	cin >> a;
	a_1 = a;
	amax = a;

	int n = 0;

	do{
		n++;
		if(a % 2 == 0){
			a = a / 2;
		}
		else {
			a = 3 * a + 1;
		}
		cout << "Schrittzahl: " << n << " a_n = " << a << endl;
		if (a > amax) {
			amax = a;
		}


	} while (a != 1);

	cout <<"Startzahl: " << a_1 << " Schrittanzahl: " << n << " groesstes a_n: " << amax << endl;

}