#include<string>

#include"FactoryGiocattoli.h"
#include"Pupazzo.h"
#include"Macchinina.h"
#include"Lego.h"

const std::string giocattoli_str = "giocattoli";

FactoryGiocattoli::FactoryGiocattoli() : Factory(giocattoli_str)
{
	this->catalogoGet().push_back(new Pupazzo("Balena", "Piccolo", 15.00, 50, 1));
	this->catalogoGet().push_back(new Pupazzo("Balena", "Grande", 25.00, 30, 2));
	this->catalogoGet().push_back(new Pupazzo("Pinguino", "Piccolo", 13.50, 43, 3));
	this->catalogoGet().push_back(new Pupazzo("Giraffa", "Grande", 35.00, 9, 4));
	this->catalogoGet().push_back(new Pupazzo("Lamborghini", "Medio", 49.99, 3, 5));
	this->catalogoGet().push_back(new Macchinina("Ferrari", "Rossa", 24.99, 53, 6));
	this->catalogoGet().push_back(new Macchinina("Betoniera", "Grigia", 20.00, 21, 7));
	this->catalogoGet().push_back(new Macchinina("Polizia", "Blu", 27.00, 30, 8));
	this->catalogoGet().push_back(new Macchinina("Mercedes", "Verde", 22.00, 60, 9));
	this->catalogoGet().push_back(new Lego("Giallo", 100, 19.99, 32, 10));
	this->catalogoGet().push_back(new Lego("Verde", 250, 24.99, 16, 11));
	this->catalogoGet().push_back(new Lego("Blu", 600, 35.00, 25, 12));
}
