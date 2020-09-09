#include<iostream>
#include<string>

#include"Macchinina.h"

Macchinina::Macchinina(std::string MODELLO, std::string COLORE, double PREZZO, int QUANTITA, int CODICE) : ProdottoReale(PREZZO, QUANTITA, CODICE)
{
	modello = MODELLO;
	colore = COLORE;
}

std::string Macchinina::nomeGet() const
{
	return "Macchinina";
}

void Macchinina::print() const
{
	std::cout << "Modello: " << modello << std::endl
		<< "Colore: " << colore << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl
		<< "Quantita': " << quantitaGet() << std::endl;
}

void Macchinina::carrelloPrint() const
{
	std::cout << "Modello: " << modello << std::endl
		<< "Colore: " << colore << std::endl
		<< "Prezzo: " << prezzoGet() << " Euro" << std::endl;
}
