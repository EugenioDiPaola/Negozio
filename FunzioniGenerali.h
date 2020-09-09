#ifndef FUNZIONI_H
#define FUNZIONI_H

#include"Factory.h"

void consultaCatalogo(Factory *, char &);
void paga(std::vector <ProdottoReale *> *, double &, char &);
void visualizzaCarrello(std::vector <ProdottoReale *> *, double, Factory *);
void compraArticoli(Factory *, std::vector <ProdottoReale *> *, double &);
void rimuoviArticoli(Factory *, std::vector <ProdottoReale *> *, double &);
void menuCompra(Factory *, std::vector <ProdottoReale *> *, std::vector <ProdottoReale *>, double &, char &);
void menumagazzino(Factory *);
int controllo();

#endif
