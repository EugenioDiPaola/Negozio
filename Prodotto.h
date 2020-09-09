#ifndef PRODOTTO_H
#define PRODOTTO_H

#include<vector>
#include<string>

class Prodotto{
public:
	virtual std::string nomeGet() const = 0;

	virtual void print() const = 0;
};

#endif
