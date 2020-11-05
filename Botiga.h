#pragma once
#include "Magatzem.h"
//#include <string>

/**
* Clase para gestionar las acciones y el estoc de cada una de las tiendas que pertenecen a la empresa.
* Las tiendas pueden solicitar a un almacen un pedido.
* Cuando solicitien un pedido "recojeran" de almacen aquellos objetos que puedan, con tal de cubrir su pedido.
* Moveran los objetos del almacen a su propio estoc interno, que estar� ordenado igual que el del almacen.
* Ademas, la tienda necesita saber su estoc total.
**/

class Botiga
{
public:
	Botiga(string nom, string codi) { m_nom = nom; m_codi = codi; }
	bool solicitaComanda(const Comanda& c, Magatzem& m);
	map<string, priority_queue<Bicicleta*>> getStockBotiga() const;
	void mostraCataleg();
	int calculaStockTotal();
	string getNom() const {return m_nom;}
	void setNom(const string& nom);
	string getCodi() const {return m_codi;}
	void setCodi(const string& codi);
private:
	string m_nom;
	string m_codi;


};
