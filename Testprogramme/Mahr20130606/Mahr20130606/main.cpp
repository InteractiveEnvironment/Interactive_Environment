#include <cassert>
#include <iostream>
#include "AusgangImpl.h"
#include "EingangImpl.h"
using namespace std;

struct Signal {};
struct Signal1 : Signal {};
struct Signal2 : Signal {};

int main()
{
    AusgangImpl<int> a1("a1");
    EingangImpl<int> e1("e1");
    cout << a1.text() << endl;
    cout << e1.text() << endl;
    e1.verbinden(a1);
    cout << e1.text() << endl;

    cout << "e1.type(): " << e1.typ.name() << endl;
    cout << "a1.type(): " << a1.typ.name() << endl;

    AusgangImpl<Signal1> a2("a2");
    EingangImpl<Signal2> e2("e2");
    cout << a2.text() << endl;
    cout << e2.text() << endl;    
    e2.verbinden(a2);
    cout << e2.text() << endl;    
   
    AusgangImpl<Signal1> a3("a3");
    EingangImpl<Signal1> e3("e3");
    cout << a3.text() << endl;
    cout << e3.text() << endl;    
    e3.verbinden(a3);
    cout << e3.text() << endl; 
    
    Signal1 signal1;
    a3.setzeDaten(&signal1);
    Signal1* d1 = a3.daten(); 
    assert(&signal1==d1); 
    Signal1* d2 = e3.daten(); 
    assert(&signal1==d2); 
    
    Ausgang* a4 = new AusgangImpl<Signal2>("a4");
    Eingang* e4 = new EingangImpl<Signal2>("e4");
    cout << a4->text() << endl;
    cout << e4->text() << endl;    
    e4->verbinden(*a4);
    cout << e4->text() << endl;
}
