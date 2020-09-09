#include<iostream>

#include"Prodotto.h"

std::string Prodotto::nomeGet() const
{
	return "prodotto";
}

void Prodotto::print() const
{
	std::cout << "printprodotto" << std::endl;
}

