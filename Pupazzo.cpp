#include<iostream>
#include<string>

#include"Pupazzo.h"

Pupazzo::Pupazzo(std::string ANIMALE, std::string DIMENSIONE, double PREZZO, int QUANTITA, int CODICE) : ProdottoReale(PREZZO, QUANTITA, CODICE)
{
	animale = ANIMALE;
	dimensione = DIMENSIONE;
}

std::string Pupazzo::nomeGet() const
{
	return "Pupazzo";
}


void Pupazzo::print() const
{
	std::cout << "Animale: " << animale << std::endl
		<< "Dimensione: " << dimensione << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl
		<< "Quantita': " << quantitaGet() << std::endl;
}

void Pupazzo::carrelloPrint() const
{
	std::cout << "Animale: " << animale << std::endl
		<< "Dimensione: " << dimensione << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl;
}
