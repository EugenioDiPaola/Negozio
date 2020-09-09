#include<iostream>
#include<string>

#include"Lego.h"

Lego::Lego(std::string COLORE, short NUMERO_PEZZI, double PREZZO, int QUANTITA, int CODICE) : ProdottoReale(PREZZO, QUANTITA, CODICE)
{
	colore = COLORE;
	numero_pezzi = NUMERO_PEZZI;
}

std::string Lego::nomeGet() const
{
	return "Lego";
}

void Lego::print() const
{
	std::cout << "Colore: " << colore << std::endl
		<< "Numero Pezzi: " << numero_pezzi << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl
		<< "Quantita': " << quantitaGet() << std::endl;
}

void Lego::carrelloPrint() const
{ 
	std::cout << "Colore: " << colore << std::endl
		<< "Numero Pezzi: " << numero_pezzi << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl;
}

