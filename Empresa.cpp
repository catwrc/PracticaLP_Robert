
#include "Empresa.h"


//Magatzem& Empresa::getMagatzem() {}


vector<Botiga*>& Empresa::getBotigues() {}


//Proveidor& Empresa::getProveidor() {} 

void Empresa::afegeixBotiga(Botiga* b) {}







//La empresa realiza una comanda. Se retorna true si la comanda esta completa. 
//Esta función llamará a procesaComanda de la clase Proveidor para que complete la comanda solicitada
bool Empresa::realitzaComanda(Comanda& c, Proveidor& p) {
	Empresa l;
	bool completa = false;
	completa = p.procesaComanda(c, l.getMagatzem());
	return completa;
}

string Empresa::generaCodiRus(const string & model)
{
	string str = to_string(getSeguentCodiRus());

	return model + str;
}
