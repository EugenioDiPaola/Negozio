#ifndef FACTORY_H 
#define FACTORY_H

#include<vector>
#include<string>

#include"ProdottoReale.h"

class Factory
{
	std::vector<ProdottoReale *> catalogo;
	std::string categoria_prodotti = "senza categoria";

public:
	Factory();
	Factory(const std::string &);
	virtual ~Factory();
	
	std::vector <ProdottoReale *> ::iterator begin();
	std::vector <ProdottoReale *> ::iterator end();

	std::vector<ProdottoReale *> & catalogoGet();
	std::string categoria_prodottiGet();

	void categoria_prodottiSet(std::string &);

	void categoria_prodottiPrint();
};
#endif 
