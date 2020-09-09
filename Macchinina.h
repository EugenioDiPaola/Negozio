#ifndef MACCHININA_H
#define MACCHININA_H

#include"ProdottoReale.h"

class Macchinina : public ProdottoReale{
	std::string modello;
	std::string colore;

public:
	Macchinina(std::string, std::string, double, int, int);

	virtual std::string nomeGet() const;
	virtual void print() const;
	virtual void carrelloPrint() const;
};

#endif
