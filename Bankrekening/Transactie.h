#pragma once
#include <string>
#include <iostream>

//This class should be a container for the transaction data
class Transactie
{
public:
	Transactie(float aantal, std::string type, std::string datum);
	~Transactie();
	
	float getAantal();
	std::string getType();
	std::string getDatum();

private:

	float aantal = 0;
	std::string type;
	std::string datum;
};

