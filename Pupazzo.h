#ifndef PUPAZZO_H
#define PUPAZZO_H

#include"ProdottoReale.h"

class Pupazzo : public ProdottoReale{
	std::string animale;
	std::string dimensione;

public:
	Pupazzo(std::string, std::string, double, int, int);

	virtual std::string nomeGet() const;
	virtual void print() const;
	virtual void carrelloPrint() const;
};

#endif 
