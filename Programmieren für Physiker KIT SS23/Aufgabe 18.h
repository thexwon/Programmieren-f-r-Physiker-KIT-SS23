#include <iostream>
using namespace std;



struct minsec{
	int min;
	int sec;

} minsec1, minsec2;

minsec setminsec(minsec minsec1) {
	cout << "set mins" << endl;
	cin >> minsec1.min;
	cout << "set secs" << endl;
	cin >> minsec1.sec;
	return minsec1;
}
void printminsec(minsec minsec1) {
	cout << minsec1.min << "min, " << minsec1.sec << "sec" << endl;
}

minsec addminsec(minsec minsec1, minsec minsec2) {
	int sec = (minsec1.sec + minsec2.sec);
	int min = minsec1.min + minsec2.min + sec/60;
	sec = sec % 60;
	minsec1.min = min;
	minsec1.sec = sec;
	return minsec1;

}

void aufgabe18() {
	minsec1 = setminsec(minsec1);
	minsec2 = setminsec(minsec2);
	printminsec(minsec1);
	printminsec(minsec2);
	cout << "Die Summe ist: ";
	minsec1 = addminsec(minsec1, minsec2);
	printminsec(minsec1);
	


}