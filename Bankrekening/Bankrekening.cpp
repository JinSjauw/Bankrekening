#include "Bankrekening.h"

Bankrekening::Bankrekening(float saldo)
{
	this->saldo = saldo;
}

Bankrekening::~Bankrekening()
{

}

void Bankrekening::ProcessTransactie(Transactie* transactie)
{
	//Process transactie hier
	std::string type = transactie->getType();
	if(type == "-")
	{
		this->saldo -= transactie->getAantal();
	}
	else if (type == "+")
	{
		this->saldo += transactie->getAantal();
	}

	this->transactieHistorie.push_back(transactie);
	
}

void Bankrekening::getTransactieHistorie() const
{
	for(auto& i : transactieHistorie)
	{
		std::string type = i->getType();
		if(type == "-")
		{
			std::cout << "Afschrijving";
			std::cout << "-";
		}
		else if(type == "+")
		{
			std::cout << "Bijschrijving";
		}
		std::cout << " - Datum: " << i->getDatum() << std::endl;

		std::cout << "Aantal: " << i->getAantal() << std::endl;
	}
}

void Bankrekening::getResult()
{
		std::cout << "Bankrekening" << std::endl,
		std::cout << "Saldo: " << this->saldo << std::endl,
		this->getTransactieHistorie();
}

Bankrekening& Bankrekening::operator+(const float aantal)
{
	Transactie* transactie = new Transactie(aantal, "+", date::format("%F", std::chrono::system_clock::now()));
	ProcessTransactie(transactie);

	return *this;
}

Bankrekening& Bankrekening::operator-(const float aantal)
{
	Transactie* transactie = new Transactie(aantal, "-", date::format("%F", std::chrono::system_clock::now()));
	ProcessTransactie(transactie);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bankrekening& rekening)
{
	os << "Bankrekening" << std::endl << "-----------------" << std::endl
		<< "Saldo: " << rekening.saldo << std::endl << "Transacties" << std::endl
		<< "---------------" << std::endl;
	   rekening.getTransactieHistorie();

	return os;
}

