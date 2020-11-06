#pragma once
#include <string>

#include "Botiga.h"
#include "Comanda.h"
#include "Magatzem.h"
#include "Proveidor.h"

int cont = 0;

/**
 *
* La clase empresa aglutina la inforamcion para gestionar la comunicacion del almacen con el proveedor, asi como las tiendas.
* La empresa se define por un conjunto de tiendas, un almacen y un proveedor.
* La empresa realizar� pedidos al provedor y recibira una notificacion indicando si el pedido ha llegado correctamente a almacen.
*
**/

class Empresa {

public:
	Empresa() {}
	Empresa(string name, int numBotigues, Magatzem& magatzemPrincipal, Proveidor& p) : m_name(name), m_numBotigues(numBotigues), m_magatzemPrincipal(magatzemPrincipal) {}
	Empresa(const Empresa& e) { m_name = e.m_name; m_numBotigues = e.m_numBotigues; m_magatzemPrincipal = e.m_magatzemPrincipal; m_proveidor = e.m_proveidor; } //implementar en magatzem el operador =
	string getName() const { return m_name; }
	Magatzem& getMagatzem() { return m_magatzemPrincipal; }
	vector<Botiga*>& getBotigues();
	void setProveidor(Proveidor& proveidor) { m_proveidor = proveidor; } //en Proveidor sobrecargar el  operador =
	Proveidor& getProveidor() { return m_proveidor; } //mirar si se puede devolver un objeto entero
	void afegeixBotiga(Botiga* b);
	static int getSeguentCodiRus() { cont++; return cont; };

	bool realitzaComanda(Comanda& c, Proveidor& p); //ya implementada
	static string generaCodiRus(const string& model);

private:
	string m_name;
	int m_numBotigues;
	Magatzem m_magatzemPrincipal;
	Proveidor m_proveidor;
	//vector<Botiga> m_botigues;
};