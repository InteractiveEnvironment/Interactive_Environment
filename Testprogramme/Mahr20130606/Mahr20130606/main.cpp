#include <cassert>
#include <iostream>
#include "AusgangImpl.h"
#include "EingangImpl.h"
using namespace std;

int main()
{
    AusgangImpl<int> a1("a1");
    EingangImpl<int> e1("e1");
    cout << a1.text() << endl;
    cout << e1.text() << endl;
    e1.verbinden(a1);
    cout << e1.text() << endl;

    cout << "e1.name(): " << e1.typ.name() << endl;
    cout << "a1.name(): " << a1.typ.name() << endl;

    AusgangImpl<int> a2("a2");
    EingangImpl<float> e2("e2");
    cout << a2.text() << endl;
    cout << e2.text() << endl;
    e2.verbinden(a2);
    cout << e2.text() << endl;

    AusgangImpl<float> a3("a3");
    EingangImpl<float> e3("e3");
    cout << a3.text() << endl;
    cout << e3.text() << endl;
    e3.verbinden(a3);
    cout << e3.text() << endl;

    float signal1;
    a3.setzeDaten(&signal1);
    float* d1 = a3.daten();
    assert(&signal1==d1);
    float* d2 = e3.daten();
    assert(&signal1==d2);

    Ausgang* a4 = new AusgangImpl<Signal2>("a4");
    Eingang* e4 = new EingangImpl<Signal2>("e4");
    cout << a4->text() << endl;
    cout << e4->text() << endl;
    e4->verbinden(*a4);
    cout << e4->text() << endl;

}
