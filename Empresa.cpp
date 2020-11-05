#include "Empresa.h"

bool Empresa::realitzaComanda(Comanda & c, Proveidor & p)
{
	Empresa l;
	
	bool trobat = false;

	trobat = p.procesaComanda(c, l.getMagatzem());

	return trobat;
}

string Empresa::generaCodiRus(const string & model)
{
	return string();
}

//Proveidor & Empresa::getProveidor()
//{
//	Proveidor p;
//	int codi;
//	codi=p.getCodiProveidor();
//
//	Proveidor a(codi);
//
//	return a;
//}
