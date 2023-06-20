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
    float length;
    float width;
public:              
    void setze(float l, float w) {  
        length = l;
        width = w;
    }
    void rotation() {
      float temp = length;
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
    cout << "Klasse für Rechtecke" << endl ;
    rechteck r1, r2 ;
    int w1, w2, l1, l2;
    cout << "Länge und Weite für Rechteck 1 \n";
    cin>> w1;
    cin >>l1;
    cout << "Länge und Weite für Rechteck 2\n";
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
