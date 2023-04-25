#include <iostream>

using namespace std;

void aufgabe6() {
	double	epsilon = 1.0;
	while (1 != 1 + epsilon) {
		epsilon *= 0.5;
	}
	cout << epsilon * 2.0;
   
}
