#ifndef PRODOTTOREALE_H
#define PRODOTTOREALE_H

#include<vector>
#include"Prodotto.h"

class ProdottoReale : public Prodotto{
	double prezzo;
	int quantita;
	int codice;

public:
	ProdottoReale(double = 0, int = 0, int = 0);

	virtual ~ProdottoReale();

	void prezzoSet(double);
	void quantitaSet(int);
	void codiceSet(int);

	virtual std::string nomeGet() const;
	double prezzoGet() const;
	int quantitaGet() const;
	int codiceGet() const;

	virtual void print() const;
	virtual void carrelloPrint() const;
};

#endif
