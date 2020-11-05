#pragma once
#include <map>
#include <queue>
#include <string>

#include "Comanda.h"


/**
* La clase Magatzem gestiona el estoc de la empresa antes de ser enviado a tiendas.
* En el almacen se pasan controles de calidad para notificar a la empresa del estado en el que llega el pedido.
* El almacen tambien genera la factura final en funcion del estado con el que llega el pedido.
* 
**/

class Magatzem
{
public:
	Magatzem();
	Magatzem(string nom, string codi) { m_nom = nom; m_codi= codi; }
	void enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada);
	float procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual);
	bool rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet);
	void generaFactura(bool paquetComplet, float costCorregit, Comanda& c);
	Bicicleta* agafaBicicletaAntiga(const string& model);
	void mostraCataleg();

	string getNom() const { return m_nom; };
	void setNom(string nom) { m_nom = nom; };
	string getCodi() const { return m_codi; };
	void setCodi(string codi) { m_codi = codi; };
	map<string, priority_queue<Bicicleta*>> getStock() const { return prioridad_bici; };
	
private:

	string m_nom;
	string m_codi;
	map<string, priority_queue<Bicicleta*>> prioridad_bici;

};
