#pragma once
#include "Transactie.h"
#include <list>
#include "date.h"

class Bankrekening
{
public:

	Bankrekening(float saldo);
	~Bankrekening();

	void ProcessTransactie(Transactie* newTransactie);
	void getTransactieHistorie() const;
	void getResult();

	Bankrekening& operator+(const float aantal);
	Bankrekening& operator-(const float aantal);

private:

	float saldo = 0;
	std::list<Transactie*> transactieHistorie;

	friend std::ostream& operator<<(std::ostream& os, const Bankrekening& rekening); 
};

