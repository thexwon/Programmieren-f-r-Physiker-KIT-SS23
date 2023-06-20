// Kubische Splines

#include <iostream>
#include <fstream>
using namespace std;



void aufgabe15(){
	char filename[30];
	const int size = 12;
	double x[size];
	double y[size];

	cout << "Einzulesende Datei eingeben" << endl;
	cin >> filename;

	fstream myfile(filename, ios_base::in);
	for (int i = 0; i < size; i++) {
		myfile >> x[i] >> y[i];
		cout << setw(8) <<"x_" << i << " = " <<setw(10) << x[i] <<"      " <<setw(8)<< "y_" << i << " = "<<setw(10) << y[i] <<endl;

	}
	cout << "Anzahl der Punkte: " << size << endl;
	double lambda[size];
	double mu[size];
	double d[size];

	for (int j = 1; j < size-1; j++) {
		lambda[j] = (x[j + 1] - x[j]) / (x[j + 1] - x[j - 1]);
		mu[j] = (x[j] - x[j - 1]) / (x[j + 1] - x[j - 1]);
		d[j] = (6 / (x[j + 1] - x[j - 1])) * ((y[j + 1] - y[j]) / (x[j + 1] - x[j]) - (y[j] - y[j - 1]) / (x[j] - x[j - 1]));


	}
	lambda[0] = 0;
	mu[size - 1] = 0;
	d[0] = 0;
	d[size - 1] = 0;
	mu[0] = 2;
	double f;
	for (int i = 1; i < size; i++) {
		f = -mu[i] / mu[i - 1];
		mu[i] = 2 + f * lambda[i - 1];
		d[i] = d[i] + f * d[i - 1];
	}
	double M[size];
	M[size-1] = d[size-1] / mu[size-1];
	for (int i = size - 2; i >= 0; i--) {
		M[i] = (d[i] - lambda[i] * M[i + 1])/mu[i];
	}

	double alpha[size];
	double beta[size];
	double gamma[size];
	double delta[size];
	cout << "Ergebnisse: " << endl;
	for (int i = 0; i < size-1; i++) {
		alpha[i] = y[i];
		beta[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]) - (2 * M[i] + M[i + 1]) / (6) * (x[i + 1] - x[i]);
		gamma[i] = M[i] / 2;
		delta[i] = (M[i + 1] - M[i]) / (6*(x[i + 1] - x[i]));
		cout << setw(10) << alpha[i] << "  " << setw(10) << beta[i] << "  " << setw(10) << gamma[i] << "  " << setw(10) << delta[i] << "  " << endl;
	}

	ofstream efile("a15-spline-values.txt");

	for (double xSpline = x[0]; xSpline <= x[size - 1];
		xSpline += (x[size - 1] - x[0]) / 300.0)
	{
		int j = size - 1; 
		while (j >= 1 and xSpline < x[j]) --j;

		double delta_x = xSpline - x[j];
		double ySpline =
			alpha[j] + beta[j] * delta_x + gamma[j] * delta_x * delta_x + delta[j] * delta_x * delta_x * delta_x;
		cout << "xSpline = " << setw(6) << xSpline << "    " << "ySpline = " << setw(10) << ySpline << endl;
		efile <<xSpline << ";"<< ySpline << endl;
	}
	efile.close();
	cout << "Interpolierte Punkte in Datei a15-spline-values.txt abgelegt." << endl;





}
