#pragma once
#include <vector>
#include "Ausgang.h"
#include "Eingang.h"
//using namespace std;

class Block
{
private:

	string _name;
	vector<Eingang*> eingang;
	vector<Ausgang*> ausgang;

protected:

	void eingangHinzufuegen(Eingang* e)
	{
		eingang.push_back(e);
	}

	void ausgangHinzufuegen(Ausgang* a)
	{
		ausgang.push_back(a);
	}

public:

	Block(const string& name) : _name(name)
	{
	}

	virtual ~Block()
	{
		for(Eingang* e : eingang)
		{
			e->trennen();
			delete e;
		}

		for(Ausgang* a : ausgang)
		{
			delete a;
		}
	}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void trigger() = 0;

	const vector<Eingang*> eingaenge() const
	{
		return eingang;
	}

	const vector<Ausgang*> ausgaenge() const
	{
		return ausgang;
	}

	virtual std::string name() const
	{
		return _name;
	}

	std::string text() const
	{
		std::stringstream s;

		s << "Block " << name() << "\nEingaenge:\n";
		for(Eingang* e : eingang)
		{
			s << e->text() << endl;
		}
		s << "Ausgänge:\n";
		for(Ausgang* a : ausgang)
		{
			s << a->text() << endl;
		}

		return s.str();
	}
};
