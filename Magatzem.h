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

class Magatzem {
public:
	Magatzem() {};
	Magatzem(string nom, string codi) : m_nom(nom), m_codi(codi) {}
	Magatzem(const Magatzem& m) { m_nom = m.m_nom; m_codi = m.m_codi; };
	~Magatzem() {};

	//Sobrecargar operador para poder igualar dos objetos magatzem
	Magatzem& operator=(const Magatzem& m);

	void enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada);//Esta funcion es distinta en el pdf  void enmagatzemarComanda(vector<Bicicleta*>& paquet);
	float procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual);
	bool rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet);
	void generaFactura(bool paquetComplet, float costCorregit, Comanda& c);
	Bicicleta* agafaBicicletaAntiga(const string& model); //implementado
	void mostraCataleg();

	string getNom() const { return m_nom; }
	string getCodi() const { return m_codi; }
	void setNom(string nom) { m_nom = nom; }
	void setCodi(string codi) { m_codi = codi; }

	map<string, priority_queue<Bicicleta*>> getStock() const { return m_stock; }

private:
	string m_nom;
	string m_codi;
	map<string, priority_queue<Bicicleta*>> m_stock; //prioridad bici
};