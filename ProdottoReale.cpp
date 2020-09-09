#include<iostream>

#include"ProdottoReale.h"

ProdottoReale::ProdottoReale(double PREZZO, int QUANTITA, int CODICE) : prezzo(PREZZO), quantita(QUANTITA), codice(CODICE)
{}

std::string ProdottoReale::nomeGet() const
{
	return "prodotto reale";
}
int ProdottoReale::quantitaGet() const
{
	return quantita;
}
double ProdottoReale::prezzoGet() const
{
	return prezzo;
}
int ProdottoReale::codiceGet() const
{
	return codice;
}

void ProdottoReale::prezzoSet(double PREZZO)
{
	prezzo = PREZZO;
}
void ProdottoReale::quantitaSet(int QUANTITA)
{
	quantita = QUANTITA;
}
void ProdottoReale::codiceSet(int CODICE)
{
	codice = CODICE;
}

void ProdottoReale::print() const
{
	std::cout << "Prezzo: " << prezzo << " Euro" << std::endl
		<< "Quantita': " << quantita << std::endl;
}

void ProdottoReale::carrelloPrint() const
{
	std::cout << "Prezzo: " << prezzo << " Euro" << std::endl;
}

ProdottoReale::~ProdottoReale()
{}
