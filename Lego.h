#ifndef LEGO_H
#define LEGO_H

#include"ProdottoReale.h"

class Lego : public ProdottoReale{
	std::string colore;
	short numero_pezzi;

public:
	Lego(std::string, short, double, int, int);

	virtual std::string nomeGet() const;
	virtual void print() const;
	virtual void carrelloPrint() const;
};

#endif