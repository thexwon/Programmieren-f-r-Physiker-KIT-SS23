#pragma once
#include <iostream>
using namespace std;

class ratio {
private:
	long zaehler, nenner;
	int euklid(long a, long b)
	{
		if (b == 0)
		{
			return a;
		}
		else
		{
			return euklid(b, a % b); // Rekursiver Aufruf der Methode
		}
	}


public:
	ratio(long z=0, long n=0) {
		zaehler = z;
		nenner = n;
	}
	long getz() {
		return zaehler;
	}
	long getn() {
		return nenner;
	}

	ratio kuerzen() {

		long n1 = nenner;
		long z1 = zaehler;

		long ggn = euklid(n1, z1);
		n1 /= ggn;
		z1 /= ggn;

		return ratio(z1,n1);
	}

	ratio operator + (ratio &r2) {
		ratio res;
		res.nenner = nenner * r2.nenner;
		res.zaehler = zaehler * r2.nenner + r2.zaehler * nenner;
		res = res.kuerzen();
		return res;
	}
/*	ratio operator<< (ratio r2) {
		cout << r2.zaehler << "/" << r2.nenner << endl;
	}
*/
	ratio operator - (ratio& r2) {
		ratio res;
		res.nenner = nenner * r2.nenner;
		res.zaehler = zaehler * r2.nenner - r2.zaehler * nenner;
		res = res.kuerzen();
		return res;
	}

	ratio operator * (ratio& r2) {
		ratio res;
		res.nenner = nenner * r2.nenner;
		res.zaehler = zaehler * r2.zaehler;
		res = res.kuerzen();
		return res;
	}

	ratio operator / (ratio& r2) {
		ratio res;
		res.nenner = nenner * r2.zaehler;
		res.zaehler = zaehler * r2.nenner;
		res = res.kuerzen();
		return res;
	}

	ratio unaryMinus() {
		return ratio(-zaehler, nenner);
	}

	void printRatio() {
		cout << zaehler << "/" << nenner << endl;
	}

	double calc() {
		double z = zaehler;
		double n = nenner;
		return z / n;
	}
	void printvalue() {
		cout << calc();
	}
};

void aufgabe23() {
	ratio r1(2, 15), r2(7, 5), r3(3, 7), r4(-1, 2), r5(1, 3), res;
	//res = r1 / r2 + r3 * (r4 + r5);
	r1 = r1 / r2;
	r2 = r3 * r4;
	r3 = r3 * r5;
	r3 = r3 + r2;
	r1 = r1 + r3;
	r1.printRatio();
	r1.printvalue();

}