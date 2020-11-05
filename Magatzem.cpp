#include "Magatzem.h"
#include <map>
#include "utils.h"
#include <fstream>
using namespace std;
bool Magatzem::rebreComanda(Comanda & c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet)
{
	bool trobat = false;
	
	vector<Bicicleta*>::iterator aux = paquet.begin();
	vector<lineaComanda> com;
	com = c.getLlistaComanda();

	vector<lineaComanda>::iterator lineacom = com.begin();


	priority_queue<Bicicleta*> nose;
	while (aux != paquet.end()) {

		if ((*aux)->getTipus == TipusBicicleta::INFANTIL) {

			BicicletaInfantil bi = BicicletaInfantil((*aux)->getModel, "Descripcio", 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(), (*aux)->getTipus(), randomBool());

			for (int i=0;i<(*lineacom).m_quantitat; i++)
				nose.push(new BicicletaInfantil(bi));
		}

		if ((*aux)->getTipus == TipusBicicleta::CARRETERA) {

			BicicletaCarretera bc = BicicletaCarretera((*aux)->getModel, string("Descripcio"), 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(), (*aux)->getTipus(), randomModalitatC(), randomBool());


			for (int i = 0; i < (*lineacom).m_quantitat; i++)
				nose.push(new BicicletaCarretera(bc));
		}

		if ((*aux)->getTipus == TipusBicicleta::MTB) {

			BicicletaMTB bmtb = BicicletaMTB((*aux)->getModel, "Descripcio", 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(),(*aux)->getTipus(), randomCategoria(), randomModalitat(), randomBool());

			for (int i = 0; i < (*lineacom).m_quantitat; i++)
				nose.push(new BicicletaMTB(bmtb));
		}

		aux++;
		lineacom++;
	}




	prioridad_bici.insert(pair< string, priority_queue<Bicicleta*>>("vALOR", nose));

	//Se tendria que poner las biciletas en unos contenedores sun el modelo de la bicicleta.


	if (dataRecepcioPaquet <= c.getDataEntregaPrevista()) {
		trobat = true;
	}

	
	return trobat;
}

void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda & c)
{
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
			cout << "Codi identificatiu :"<<m.getNom() << endl;
			cout << "Codi identificatiu :" << m.getNom() << endl;

			for (aux = lc.begin(); aux != lc.end(); aux++) {
				cout << (*aux).m_model << " * " << (*aux).m_quantitat << endl;
			}

			cout << "Preu final: " << c.getCostTotal() << endl;// otra opcion **cout << "Preu final: " << costCorregit << endl;**

			fitxer.close();
		}


}
