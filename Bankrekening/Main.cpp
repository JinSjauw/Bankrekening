#include <iostream>
#include "BankRekening.h"

int main()
{
    Bankrekening geld(100);

    geld + 12;
    geld + 1000;
    geld - 399;

    std::cout << geld << std::endl;
}