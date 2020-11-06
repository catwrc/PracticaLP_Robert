#include "Magatzem.h"
#include <map>
#include "utils.h"
#include <fstream>
#include "Empresa.h"
using namespace std;

void Magatzem::enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada) {
	Empresa t;
	vector<Bicicleta*>::iterator aux = paquet.begin();

	while (aux != paquet.end()) {

		(*aux)->setCodiRus(t.generaCodiRus((*aux)->getModel())); // A cada elemento del vector Bicicleta le añadimos un codigo identificador con la funcion generaCodiRus()
		aux++;
	}
}
float Magatzem::procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual) {}

/*
	El magatzem guarda un contenedor con el modelo de la bici y una estructura
	ordenada por fecha de llegada de las bicicletas de este modelo (modelo!= tipo)
*/
bool Magatzem::rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet) { // está a medias
	bool trobat = false;

	vector<Bicicleta*>::iterator aux = paquet.begin;

	while (aux != paquet.end()) {
	
		if ((*aux)->getModel() == "A") {
		
			priority_queue<Bicicleta* > cuabiciA;
			
		
		}
		if ((*aux)->getModel() == "B") {

			priority_queue<Bicicleta* > cuabiciB;

		}
		aux++;
	
	}

	

}

/*
	Se genera la factura final para el proveedor incluyendo datos de la entidad (codi_empresa, nom, telef)
	que la genera conjunatmente con los datos de la comanda realizada (se guarda como comanda.txt)
*/
void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda& c) {
	Magatzem m;
	vector<lineaComanda> lc;
	lc = c.getLlistaComanda();
	vector<lineaComanda>::iterator aux = lc.begin();

	ofstream fitxer;
	// Variable per guardar el nom del fitxer
	string nomFitxer = "comanda.txt";
	fitxer.open(nomFitxer);

	if (fitxer.is_open()) {
		cout << "Resum comanda:" << endl;
		cout << "Dades Entitat responsable :" << endl;
		cout << "Codi identificatiu :" << m.getNom() << endl;
		cout << "Codi identificatiu :" << m.getNom() << endl;
		for (aux = lc.begin(); aux != lc.end(); aux++) {
			cout << (*aux).m_model << " * " << (*aux).m_quantitat << endl;
		}
		cout << "Preu final: " << c.getCostTotal() << endl;// otra opcion **cout << "Preu final: " << costCorregit << endl;**
		fitxer.close();
	}
}

Bicicleta* Magatzem::agafaBicicletaAntiga(const string& model) {
	/*map<string, priority_queue<Bicicleta*>>::iterator it = m_stock.find(model);
	if (it != m_stock.end()) return it->top();
	else cout << "Model not found." << endl; */
}

void Magatzem::mostraCataleg() {}
