#include <cassert>
#include <iostream>
#include <vector>
#include "AusgangImpl.h"
#include "EingangImpl.h"
#include "Block.h"
using namespace std;

struct Signal {};
struct Signal1 : Signal {};
struct Signal2 : Signal {};

class Block1 : public Block
{
private:

	AusgangImpl<int>* a1;
	AusgangImpl<float>* a2;
	int demoInt;
	float demoFloat;

public:

    enum Typ {INT, FLOAT};

	Block1(const string& name) : Block(name), demoInt(0), demoFloat(11.11)
	{
		a1 = new AusgangImpl<int>("a1");
		ausgangHinzufuegen(a1);

		a2 = new AusgangImpl<float>("a2");
		ausgangHinzufuegen(a2);
	}

	void naechsterSchritt()
	{
	    a1->setzeDaten(&demoInt);
		demoInt++;

		a2->setzeDaten(&demoFloat);
		demoFloat *= 2;
	}
};

class Block2 : public Block
{
private:

    EingangImpl<float>* e1;
	EingangImpl<int>* e2;

public:

    enum Typ {TYP1, TYP2};


	Block2(const string& name) : Block(name)
	{
		e1 = new EingangImpl<float>("e1");
		eingangHinzufuegen(e1);

		e2 = new EingangImpl<int>("e2");
		eingangHinzufuegen(e2);
	}

	void naechsterSchritt()
	{
	    cout << name() << " empfängt ";

		float* f = e1->daten();
		if(f!=nullptr)
		{
			cout << *f << " ";
		}
		else
		{
		    cout << " nullptr";
		}

		cout << " und ";

		int* i = e2->daten();
		if(i!=nullptr)
		{
			cout << *i;
		}
		else
		{
		    cout << " nullptr";
		}

		cout << endl;
	}
};

void demoBlock()
{
	Block1* b1 = new Block1("b1");
	Block2* b2 = new Block2("b2");

	const vector<Ausgang*> b1Ausgaenge = b1->ausgaenge();
	const vector<Eingang*> b2Eingaenge = b2->eingaenge();

	assert(b2Eingaenge[Block2::TYP2]->istKompatibel(*b1Ausgaenge[Block1::INT]));
	assert(!b2Eingaenge[Block2::TYP2]->istKompatibel(*b1Ausgaenge[Block1::FLOAT]));
	assert(!b2Eingaenge[Block2::TYP1]->istKompatibel(*b1Ausgaenge[Block1::INT]));
	assert(b2Eingaenge[Block2::TYP1]->istKompatibel(*b1Ausgaenge[Block1::FLOAT]));

	b2Eingaenge[Block2::TYP2]->verbinden(*b1Ausgaenge[Block1::INT]);
	b2Eingaenge[Block2::TYP1]->verbinden(*b1Ausgaenge[Block1::FLOAT]);

	cout << b1->text() << b2->text();

	for(int i=0; i<3; i++)
	{
		b1->naechsterSchritt();
		b2->naechsterSchritt();
	}

    delete b1;
	cout << b2->text();
	delete b2;
}

void demoPort()
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

    vector<Ausgang*> ausgaenge;
    ausgaenge.push_back(&a1);
    ausgaenge.push_back(&a2);
    ausgaenge.push_back(&a3);
    ausgaenge.push_back(a4);
    int i=0;
    for(Ausgang* a : ausgaenge)
    {
		cout << "Ausgang " << i++ << ": " << a->name() << endl;
	}
}

int main()
{
	//demoPort();
	demoBlock();
}
