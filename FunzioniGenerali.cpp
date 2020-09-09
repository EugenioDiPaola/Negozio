#include<iostream>
#include<string>
#include<cctype> 
#include<vector>

#include"FunzioniGenerali.h" 

void consultaCatalogo(Factory * FACTORY_PTR, char & UTENTE)
{
	std::cout << "*********CATALOGO*********" << std::endl << std::endl;
	std::vector <ProdottoReale *>::iterator it;
	for(it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
	{
		std::cout << "Codice: " << (*it)->codiceGet() << std::endl;
		std::cout << (*it)->nomeGet() << std::endl;
		(*it)->print();
		std::cout << std::endl;
	}
	UTENTE = 0;
	std::cout << "*************************" << std::endl << std::endl << std::endl;
}

void paga(std::vector<ProdottoReale *> * VECTOR_PTR, double & SPESA, char & UTENTE)
{
	std::cout << "--> Hai pagato " << SPESA << " Euro <--" << std::endl << "Ora il tuo carrello e' vuoto" << std::endl << std::endl;
	VECTOR_PTR->clear();
	SPESA = 0;
	UTENTE = 0;
}

void visualizzaCarrello(std::vector <ProdottoReale *> * CARRELLO, double SPESA, Factory * FACTORY_PTR)
{
	std::cout << "********CARRELLO********" << std::endl << std::endl;

	if(CARRELLO->size() == 0)
	{
		std::cout << "Carrello vuoto" << std::endl << std::endl;
		std::cout << "************************" << std::endl << std::endl;
	}

	else
	{
		for(std::vector<ProdottoReale *>::iterator i = CARRELLO->begin(); i != CARRELLO->end(); i++)
		{
			if((*i)->quantitaGet() != 0)
			{
				for(std::vector<ProdottoReale *>::iterator it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
				{
					if((*i)->codiceGet() == (*it)->codiceGet())
					{
						std::cout << "Codice: " << (*it)->codiceGet() << std::endl;
						std::cout << (*it)->nomeGet() << std::endl;
						(*it)->carrelloPrint();
						std::cout << "Quantita': " << (*i)->quantitaGet() << std::endl << std::endl;
					}
				}
			}
		}
	}

	if(SPESA != 0)
	{
		std::cout << "Spesa totale: " << SPESA << " Euro" << std::endl << std::endl;
		std::cout << "************************" << std::endl << std::endl;
	}
	if(SPESA == 0 && CARRELLO->size() != 0)
	{
		std::cout << "Carrello vuoto" << std::endl << std::endl;
		std::cout << "************************" << std::endl << std::endl;
	}
}

void compraArticoli(Factory * FACTORY_PTR, std::vector<ProdottoReale *> * VECTOR_PTR, double & spesa)
{
	char tipo;
	char tipo1;

	std::cout << "Che tipo di articolo vuoi comprare? \nP - Pupazzo \nM - Macchinina\nL - Lego" << std::endl;
	std::cin >> tipo;
	std::cout << std::endl;
	tipo1 = toupper(tipo);

	if(tipo1 != 'P' && tipo1 != 'M' && tipo1 != 'L')
	{
		std::cout << "!!! Lettera non valida !!!" << std::endl << std::endl;
		compraArticoli(FACTORY_PTR, VECTOR_PTR, spesa);
	}

	std::cout << "Articoli disponibili: " << std::endl << std::endl;
	std::vector <ProdottoReale *>::iterator it;
	for(it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
	{
		std::string nome;
		nome = (*it)->nomeGet();
		char nome1 = nome[0];
		if(tipo1 == nome1)
		{
			std::cout << "Codice: " << (*it)->codiceGet() << std::endl;
			(*it)->print();
			std::cout << std::endl;
		}
	}

	bool s = 0;
	do
	{
		std::cout << "Inserire il codice del prodotto da acquistare: " << std::endl;
		int codic = 0;
		codic = controllo();
		std::cout << std::endl << std::endl;

		for(it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
		{
			int codice = 0;
			int quant = 0;
			int n = 0;
			codice = (*it)->codiceGet();
			quant = (*it)->quantitaGet();
			int quant2;

			if(codic == codice)
			{
				do
				{
					std::string nome = (*it)->nomeGet();
					char nome1 = nome[0];
					if(tipo1 == nome1)
					{

						(*it)->carrelloPrint();
						std::cout << std::endl << "Sono disponibili " << quant << " pezzi del prodotto desiderato." << std::endl;
						std::cout << "Inserire la quantitata' che si desidera acquistare: " << std::endl;
						n = controllo();
						std::cout << std::endl;

						if(n <= quant && n > 0)
						{
							bool p = 0;
							std::vector<ProdottoReale *>::iterator i2;

							for(std::vector<ProdottoReale *>::iterator i = VECTOR_PTR->begin(); i != VECTOR_PTR->end(); i++)
							{
								if(codic == (*i)->codiceGet())
								{
									p = 1;
									i2 = i;
									quant2 = (*i)->quantitaGet();
									break;
								}
							}
							if(p == 1)
							{
								(*it)->quantitaSet(quant - n);
								spesa += (*it)->prezzoGet() * n;
								std::cout << "*** Totale spesa attuale: " << spesa << " Euro ***" << std::endl << std::endl;
								(*i2)->quantitaSet(quant2 + n);
								s = 1;
							}
							else
							{
								(*it)->quantitaSet(quant - n);
								spesa += (*it)->prezzoGet() * n;
								std::cout << "*** Totale spesa attuale: " << spesa << " Euro ***" << std::endl << std::endl;

								VECTOR_PTR->push_back(new ProdottoReale((*it)->prezzoGet(), n, (*it)->codiceGet()));
								s = 1;
							}
						}
						else
						{
							if(n == 0)
							{
								s = 1;
								break;
							}

							if(n > 0)
								std::cout << "!!! La quantitata' richiesta e' maggiore della disponibilita' !!!\n" << std::endl;
							if(n < 0)
								std::cout << "!!! Il valore inserito non e' valido !!!\n" << std::endl << std::endl;
						}
					}
					else
						std::cout << "!!! Il codice inserito non fa parte della categoria scelta !!!\n" << std::endl << std::endl;
				}
				while(n > quant || n < 0);
			}
		}

	}
	while(s == 0);
}

void rimuoviArticoli(Factory * FACTORY_PTR, std::vector <ProdottoReale *> * VECTOR_PTR, double & SPESA)
{
	int codelimina;
	int quantelimina;

	visualizzaCarrello(VECTOR_PTR, SPESA, FACTORY_PTR);

	bool k = 0;
	do
	{

		std::cout << "Inserisci il codice del prodotto da eliminare: " << std::endl;
		codelimina = controllo();


		if(VECTOR_PTR->size() == 1)
		{
			std::vector<ProdottoReale *>::iterator i = VECTOR_PTR->begin();
			int c = (*i)->codiceGet();

			if(c == codelimina)
			{
				bool j = 0;
				do
				{
					std::vector<ProdottoReale *>::iterator i = VECTOR_PTR->begin();
					std::cout << "Nel carrello sono presenti " << (*i)->quantitaGet() << " elementi." << std::endl << "Inserisci la quantitata' da eliminare: " << std::endl;
					std::cin >> quantelimina;
					if(quantelimina >= 0 && quantelimina <= (*i)->quantitaGet())
					{

						if(quantelimina == (*i)->quantitaGet())
						{
							for(std::vector<ProdottoReale *>::iterator it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
							{
								if((*i)->codiceGet() == (*it)->codiceGet())
								{
									int q = (*it)->quantitaGet();
									(*it)->quantitaSet(q + quantelimina);
								}
							}

							VECTOR_PTR->clear(); 
							SPESA = 0;
							k = 1;
							j = 1;
						}
						else
						{
							for(std::vector<ProdottoReale *>::iterator it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
							{
								if((*i)->codiceGet() == (*it)->codiceGet())
								{
									int q = (*it)->quantitaGet();
									(*it)->quantitaSet(q + quantelimina);
								}
							}
							int quantitataa = (*i)->quantitaGet();
							SPESA -= quantelimina * (*i)->prezzoGet();
							(*i)->quantitaSet(quantitataa - quantelimina);

							j = 1;
							k = 1;
						}
					}
					else
						std::cout << "!!! Quantita' inserita non valida !!!" << std::endl << std::endl;
				}
				while(j == 0);
				break;
			}
			else
				std::cout << "!!! Il codice inserito non corrisponde ad elementi del carrello !!!" << std::endl << std::endl;
		}
		else
		{
			for(std::vector<ProdottoReale *>::iterator i = VECTOR_PTR->begin(); i != VECTOR_PTR->end(); i++)
			{
				if((*i)->codiceGet() != codelimina)
				{
					while((*i)->codiceGet() != codelimina)
					{
						i++;
					}
				}

				if((*i)->codiceGet() == codelimina)
				{
					int quantitataa = (*i)->quantitaGet(); 
					double prezzoa = (*i)->prezzoGet();

					bool j = 0;
					do
					{
						std::cout << "Nel carrello sono presenti " << quantitataa << " pezzi\nInserisci la quantitata' da eliminare: ";
						quantelimina = controllo();
						std::cout << std::endl;

						if(quantelimina >= 0 && quantelimina <= quantitataa)
						{
							if(quantelimina == quantitataa) 
							{
								for(std::vector<ProdottoReale *>::iterator it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
								{
									if((*i)->codiceGet() == (*it)->codiceGet())
									{
										int q = (*it)->quantitaGet();
										(*it)->quantitaSet(q + quantelimina);
									}
								}

								(*i)->quantitaSet(0);
								SPESA -= quantelimina * prezzoa;

							}
							else
							{
								(*i)->quantitaSet(quantitataa - quantelimina);
								SPESA -= quantelimina * prezzoa;
								
								for(std::vector<ProdottoReale *>::iterator it = FACTORY_PTR->begin(); it != FACTORY_PTR->end(); it++)
								{
									if((*i)->codiceGet() == (*it)->codiceGet())
									{
										int q = (*it)->quantitaGet();
										(*it)->quantitaSet(q + quantelimina);
									}
								}
							}
							k = 1;
							j = 1;
						}
						else
							std::cout << "!!! La quantitata' inserita non corrisponde alla quantitata' nel carrello !!!" << std::endl << std::endl;
					}
					while(j == 0);
				}
				if(k == 0)
				{
					std::cout << "!!! Il codice inserito non corrisponde ad elementi del carrello !!!" << std::endl << std::endl;
					k = 1;
				}
				else break;
			}
		}
	} 
	while(k == 0);
}

void menuCompra(Factory * FACTORY_PTR, std::vector <ProdottoReale *> * VECTOR_PTR, std::vector <ProdottoReale *> CARELLO, double & SPESA, char & UTENTE)
{
	char utente2;
	do
	{
		//***MENU 2***
		std::cout << "Cosa vuoi fare?" << std::endl;
		std::cout << "1 - Aggiungi elemento al carrello\n2 - Rimuovi elemento dal carrello\n3 - Visualizza carrello\n4 - Ritorna al menu precedente" << std::endl;
		std::cin >> utente2;
		std::cout << std::endl;

		if(utente2 == '1')
		{
			compraArticoli(FACTORY_PTR, VECTOR_PTR, SPESA);
		}
		if(utente2 == '2')
		{
			rimuoviArticoli(FACTORY_PTR, VECTOR_PTR, SPESA);
		}
		if(utente2 == '3')
		{
			visualizzaCarrello(VECTOR_PTR, SPESA, FACTORY_PTR);
		}

		if(utente2 == '4') 
		{
			UTENTE = 0;
			break;
		}
	}
	while(utente2 != '4');
	UTENTE = 0;
}

void menumagazzino(Factory * FACTORY_PTR)
{	
	std::vector <ProdottoReale *> carrello(0);
	std::vector <ProdottoReale *> * vector_ptr;
	vector_ptr = &carrello;
	double spesa = 0;
	char utente;

	do
	{
		std::cout << ">>> Negozio di " << FACTORY_PTR->categoria_prodottiGet() << " <<<" << std::endl;
		std::cout << "1 - Consulta il catalogo\n2 - Compra articoli\n3 - Paga\n4 - Esci" << std::endl;
		std::cin >> utente;
		std::cout << std::endl;

		if(utente == '4')
		{
			if(spesa == 0) break;
			else
			{
				utente = 0;
				std::cout << "!!! Non hai ancora pagato !!!" << std::endl << std::endl;
			}
		}

		if(utente == '1')
		{
			consultaCatalogo(FACTORY_PTR, utente);
			std::cout << utente;
		}

		if(utente == '2')
		{
			menuCompra(FACTORY_PTR, vector_ptr, carrello, spesa, utente);
		}

		if(utente == '3')
		{
			paga(vector_ptr, spesa, utente);
		}
	}
	while(utente != '1' && utente != '2' && utente != '3' && utente != '4');
	return;
}

int controllo()
{
	int x;
	for(;;)
	{
		if(std::cin >> x)
		{
			break;
		}
		else
		{
			std::cout << std::endl << "!!! Valore non valido !!!" << std::endl << "Inserisci un valore valido: ";
			std::cin.clear();
			std::cin.ignore(20, '\n');
		}
	}
	return x;
}
