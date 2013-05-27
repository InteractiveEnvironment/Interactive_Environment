#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "summieren.h"
#include "subtrahieren.h"
#include "dividieren.h"
#include "multiplizieren.h"

//========================================================================


int main( ){


    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp( new testApp());


    summieren sum;
    subtrahieren sub;
    dividieren div;
    multiplizieren multi;
    float z1;
    float z2;
    float z3;
    float z4;
    int berechnung1;
    int berechnung2;
    int berechnung3;
    float ergebnis1;
    float ergebnis2;
    float ergebnis3;
    bool richtigeZahl = false;


    cout << "Bitte Zahl 1 eingeben: ";
    cin >> z1;
    cout << "Bitte Zahl 2 eingeben: ";
    cin >> z2;
    cout << "Zahl 1: " << z1 << "\n" << "Zahl 2: " << z2 << "\n\n";


    cout << "Summieren = 1\n";
    cout << "Subtrahieren = 2\n";
    cout << "Dividieren = 3\n";
    cout << "Multiplizieren = 4\n";
    cout << "Bitte Berechung fuer Block 1 wählen: ";
    cin >> berechnung1;


    while(richtigeZahl == false){
        if (berechnung1 == 1){
            ergebnis1 = sum.getParameter(z1, z2);
            cout << "\nBlock1: " << z1 << " + " << z2 << " = " << ergebnis1;
            richtigeZahl = true;
        }else if (berechnung1 == 2){
            ergebnis1 = sub.getParameter(z1, z2);
            cout << "\nBlock1: " << z1 << " - " << z2 << " = " << ergebnis1;
            richtigeZahl = true;
        }else if (berechnung1 == 3){
            while (z2 == 0){
                    cout << "Es ist nicht möglich durch 0 zu dividieren. Bitte Zahl != 0 eingeben: ";
                    cin >> z2;
            }
            ergebnis1 = div.getParameter(z1, z2);
            cout << "\nBlock1: " << z1 << " / " << z2 << " = " << ergebnis1;
            richtigeZahl = true;
        }else if (berechnung1 == 4){
            ergebnis1 = multi.getParameter(z1, z2);
            cout << "\nBlock1: " << z1 << " * " << z2 << " = " << ergebnis1;
            richtigeZahl = true;
        } else{
            cout << "\nBitte eine Zahl zwischen 1 und 4 eingeben: ";
            cin >> berechnung1;
            richtigeZahl = false;
        }
    }

    richtigeZahl = false;
    cout << "\n\nBitte Zahl 3 eingeben: ";
    cin >> z3;
    cout << "Bitte Zahl 4 eingeben: ";
    cin >> z4;
    cout << "Zahl 1: " << z3 << "\n" << "Zahl 2: " << z4 << "\n\n";


    cout << "\nSummieren = 1\n";
    cout << "Subtrahieren = 2\n";
    cout << "Dividieren = 3\n";
    cout << "Multiplizieren = 4\n";
    cout << "Bitte Berechung fuer Block 2 wählen: ";
    cin >> berechnung2;


    while (richtigeZahl == false){
        if (berechnung2 == 1){
            ergebnis2 = sum.getParameter(z3, z4);
            cout << "\nBlock2: " << z3 << " + " << z4 << " = " << ergebnis2;
            richtigeZahl = true;
        } else if (berechnung2 == 2){
            ergebnis2 = sub.getParameter(z3, z4);
            cout << "\nBlock2: " << z3 << " - " << z4 << " = " << ergebnis2;
            richtigeZahl = true;
        } else if (berechnung2 == 3){
            while (z4 == 0){
                    cout << "Es ist nicht möglich durch 0 zu dividieren. Bitte Zahl != 0 eingeben: ";
                    cin >> z4;
            }
            ergebnis2 = div.getParameter(z3, z4);
            cout << "\nBlock2: " << z3 << " / " << z4 << " = " << ergebnis2;
            richtigeZahl = true;
        } else if (berechnung2 == 4){
            ergebnis2 = multi.getParameter(z3, z4);
            cout << "\nBlock2: " << z3 << " * " << z4 << " = " << ergebnis2;
            richtigeZahl = true;
        }else{
            cout << "\nBitte eine Zahl zwischen 1 und 4 eingeben: ";
            cin >> berechnung2;
            richtigeZahl = false;
        }
    }

    richtigeZahl = false;
    cout << "\nSummieren = 1\n";
    cout << "Subtrahieren = 2\n";
    cout << "Dividieren = 3\n";
    cout << "Multiplizieren = 4\n";
    cout << "Bitte Berechung für Block 3 wählen: ";
    cin >> berechnung3;

     while (richtigeZahl == false){
        if (berechnung3 == 1){
            ergebnis3 = sum.getParameter(ergebnis1, ergebnis2);
            cout << "\nBlock3: " << ergebnis1 << " + " << ergebnis2 << " = " << ergebnis3;
            richtigeZahl = true;
        } else if (berechnung3 == 2){
            ergebnis3 = sub.getParameter(ergebnis1, ergebnis2);
            cout << "\nBlock3: " << ergebnis1 << " - " << ergebnis2 << " = " << ergebnis3;
            richtigeZahl = true;
        } else if (berechnung3 == 3){
        ergebnis3 = div.getParameter(ergebnis1, ergebnis2);
            cout << "\nBlock3: " << ergebnis1 << " / " << ergebnis2 << " = " << ergebnis3;
            richtigeZahl = true;
        } else if (berechnung3 == 4){
            ergebnis3 = multi.getParameter(ergebnis1, ergebnis2);
            cout << "\nBlock3: " << ergebnis1 << " * " << ergebnis2 << " = " << ergebnis3;
            richtigeZahl = true;
        }else{
            cout << "\nBitte eine Zahl zwischen 1 und 4 eingeben: ";
            cin >> berechnung3;
            richtigeZahl = false;
        }
    }
    cout << "\nDas Ergebnis ist: " << ergebnis3<< "\n";

}
