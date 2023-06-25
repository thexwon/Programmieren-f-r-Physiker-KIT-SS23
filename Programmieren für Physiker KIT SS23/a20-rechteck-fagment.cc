/*
 * Programmieren fuer Physiker, SS 2023, Blatt 8, Aufgabe 20
 *
 * Klasse fuer Rechteck
 */

#include <iostream>
using namespace std ;

// Zu implementieren: Klasse Rechteck mit den
// drei Methoden setze, rotation und bedeckt 
class rechteck {        
private: 
    double length;
    double width;
public:              
    void setze(double l, double w) {  
        length = l;
        width = w;
    }
    void rotation() {
      double temp = length;
        length = width;
        width = temp;
    }
    float getlength() {
        return length;
    }
    float getwidth() {
        return width;
    }

    bool bedeckt(rechteck r2) {
        
        if (length > r2.getlength() && width > r2.getwidth()) {

                return true;
        }
        return false;
    }


};

// gegebenes Hauptprogramm
int aufgabe20()
{
    cout << "Klasse fuer Rechtecke" << endl ;
    rechteck r1, r2 ;
    double w1, w2, l1, l2;
    cout << "Laenge und Weite fuer Rechteck 1";
    cin>> w1;
    cin >>l1;
    cout << "Laenge und Weite fuer Rechteck 2";
    cin >> w2;
    cin >> l2;
    r1.setze( w1,l1) ;
    r2.setze( w2,l2) ;
    
    cout << "Vor Rotation: " ;
    if (r1.bedeckt(r2)) cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    r2.rotation() ;

    cout << "Nach Rotation: " ;
    if (r1.bedeckt(r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    return 0 ;
}
