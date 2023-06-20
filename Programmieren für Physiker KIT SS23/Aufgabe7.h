#include <iostream>
#include "cubicroot.h"

using namespace std;

void aufgabe7() {
	double a, b, c, d;
	cout << "Enter a>0 : " << endl;
	cin >> a;
	cout << "Enter b: " << endl;
	cin >> b;
	cout << "Enter c: " << endl;
	cin >> c;
	cout << "Enter d: " << endl;
	cin >> d;
	
	double p = (3 * a * c - pow(b, 2)) / (3 * pow(a, 2));
	double q = 2 * pow(b, 3) / (27 * pow(a, 3)) - (b * c) / (3 * pow(a, 2)) + d / a;
	double D = pow(q / 2, 2) + pow(p / 3, 3);

	double epsilon = 0.000000000001;
	if (abs(D) < epsilon) {
		D = 0;
		cout << "D rounded down to 0" << endl;
	}
	if (abs(q) < epsilon) {
			q = 0;
			cout << "q rounded down to 0" << endl;
	}
	if (D > 0.0 + epsilon){
		cout << "There is a single real root and two complex roots." << endl;
		cout << "The real solution is:";
		double D_1 = cubicroot((-q/2) + sqrt(D));
		double D_2 = cubicroot((-q / 2) - sqrt(D));
		double x_1 = D_1 + D_2 - b / (3 * a); /*sign error somewhere?*/
		cout << x_1 << endl;
	}
	else if (D == 0) {
		if (q == 0) {
			cout << "There is a triple real root: ";
			double x_1 = -b / (3 * a);
			cout << x_1 << endl;

		}
		else {
			cout << "There is double root x1 and a single root x2:" << endl;
			double x_1 = cubicroot(q / 2) - b / (3 * a);
			double x_2 = cubicroot(-4 * q) - b / (3 * a);
			cout << "x1: " << x_1 << "x2: " << x_2 << endl;
		}

	}
	else if (D < 0 - epsilon) {
		cout << "There are three single roots: " << endl;
		double h = acos(-(q / 2) * sqrt(-27 / pow(p, 3)));
		double x_1 = -sqrt(-4 * p / 3) * cos(h / 3 + 3.14 / 3) - b / (3 * a);
		double x_2 = -sqrt(-4 * p / 3) * cos(h / 3 - 3.14 / 3) - b / (3 * a);
		double x_3 = -sqrt(-4 * p / 3) * cos(h / 3) - b / (3 * a);
		cout << "x1: " << x_1 << "x2: " << x_2 << "x3: " << x_3 << endl;
	}
}
