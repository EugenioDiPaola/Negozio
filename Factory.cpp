#include<vector> 
#include<string>
#include<iostream>

#include"Factory.h"
#include"ProdottoReale.h"

Factory::Factory(const std::string & CATEGORIA_PRODOTTI)
{
	categoria_prodotti = CATEGORIA_PRODOTTI;
}

Factory::~Factory()
{
	while(!catalogo.empty())
	{
		ProdottoReale * iter = catalogo.front();
		delete iter;
		catalogo.erase(catalogo.begin());
	}
}

std::vector<ProdottoReale *>::iterator Factory::begin()
{
	return catalogo.begin();
}

std::vector<ProdottoReale *>::iterator Factory::end()
{
	return catalogo.end();
}

std::vector<ProdottoReale *> & Factory::catalogoGet()
{
	return catalogo;
}

std::string Factory::categoria_prodottiGet()
{
	return categoria_prodotti;
}

void Factory::categoria_prodottiSet(std::string & CATEGORIA_PRODOTTI)
{
	categoria_prodotti = CATEGORIA_PRODOTTI;
}

void Factory::categoria_prodottiPrint()
{
	std::cout << categoria_prodotti << std::endl;
}
 
