#include "Proveidor.h"
#include <iostream>
#include <time.h> 
#include "utils.h"

using namespace std;

Data Proveidor::generaDataEnviament(Data dataprevista, int diesmaxim)
{
	int valor_random;
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	 valor_random= (-diesmaxim) + rand() % ((diesmaxim + 1) - (-diesmaxim));

	 

	Comanda c;

	Data d = c.getDataEntregaPrevista();

	return d + valor_random;

}

bool Proveidor::procesaComanda(Comanda c, Magatzem & m)
{
	bool trobat = false;
	vector<Bicicleta*> vector_bici;
	
	vector<lineaComanda> com;
	com = c.getLlistaComanda();

	vector<lineaComanda>::iterator aux = com.begin();

	
	while (aux != com.end()) {

		if ((*aux).tipus == TipusBicicleta::INFANTIL) {

			BicicletaInfantil bi = BicicletaInfantil((*aux).m_model, "Descripcio", 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(), (*aux).tipus, randomBool());
			
			for(int i=0;i<(*aux).m_quantitat;i++)
			vector_bici.push_back(new BicicletaInfantil(bi));
		}

		if ((*aux).tipus == TipusBicicleta::CARRETERA) {

			BicicletaCarretera bc = BicicletaCarretera((*aux).m_model, string("Descripcio"), 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(), (*aux).tipus, randomModalitatC(), randomBool());


			for (int i = 0; i < (*aux).m_quantitat; i++)
				vector_bici.push_back(new BicicletaCarretera(bc));
		}

		if ((*aux).tipus == TipusBicicleta::MTB) {
		
			BicicletaMTB bmtb = BicicletaMTB((*aux).m_model, "Descripcio", 2020, randomTalla(), randomQuadre(), randomRoda(), randomFre(), (*aux).tipus, randomCategoria(), randomModalitat(), randomBool());
		
			for (int i = 0; i < (*aux).m_quantitat; i++)
				vector_bici.push_back(new BicicletaMTB(bmtb));
		}

		aux++;
	}
	

	
	
	Proveidor p;
	Data data = p.generaDataEnviament(c.getDataEntregaPrevista,10 );
	trobat= m.rebreComanda(c, vector_bici, data);

	return trobat;

	//std::forward_lis<Estudiant>::iterator aux = m_estudiants.begin;
}
