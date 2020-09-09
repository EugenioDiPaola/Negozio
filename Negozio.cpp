#include<string>

#include"FactoryGiocattoli.h"
#include"FunzioniGenerali.h"

int main()
{
	FactoryGiocattoli factorygiocattoli;

	FactoryGiocattoli * factorygiocattoli_ptr = &factorygiocattoli;

	menumagazzino(factorygiocattoli_ptr);

	return 0;
}
