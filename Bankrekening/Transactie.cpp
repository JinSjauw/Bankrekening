#include "Transactie.h"

Transactie::Transactie(float aantal, std::string type, std::string datum)
{
	this->aantal = aantal;
	this->type = type;
	this->datum = datum;
}

Transactie::~Transactie()
{

}

float Transactie::getAantal()
{
	return this->aantal;
}

std::string Transactie::getType()
{
	return this->type;
}

std::string Transactie::getDatum()
{
	return this->datum;
}

