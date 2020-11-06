#pragma once
#include <vector>
#include "Bicicleta.h"
#include "Data.h"

/**
* Entrada que agrupa los datos de cada pedido. Contiene el tipo, la cantidad y el modelo.
**/
struct lineaComanda {
	TipusBicicleta tipus;
	int m_quantitat;
	string m_model;
};

/**
* Clase que almacena el pedido y los datos relacionados con �l.
* Una comanda debe de ser capaz de saber el totl de bicicletas pedidas, la fecha de entrega y el coste asociado a la misma.
**/
class Comanda {
public:
	Comanda() {}
	Comanda(const Data& dataComanda, vector<lineaComanda>& comanda); //implementado
	Comanda(const Comanda& c) {};
	~Comanda() {}

	int getTotalBicicletes() const { return m_numBicicletes; }
	Data getDataEntregaPrevista() const { return m_dataComanda; }
	float getCostTotal() const; //implementar en cpp
	vector<lineaComanda> getLlistaComanda() const { return m_comanda; }

	void sumTotalBicicletes(); //Función para sumar el total de bicis de la comanda
private:
	int m_numBicicletes;
	float m_costComanda;
	vector<lineaComanda> m_comanda;
	Data m_dataComanda; //data en la que es genera la comanda.
};
