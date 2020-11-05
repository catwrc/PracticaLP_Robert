#include <iostream>


#include "BicicletaCarretera.h"
#include "BicicletaInfantil.h"
#include "BicicletaMTB.h"
#include "Empresa.h"
#include "utils.h"

using namespace std;

void reposicioInical(int unitats)
{

	Magatzem m = Magatzem("Principal", "0001");
	Proveidor p = Proveidor(101);
	Empresa empresa = Empresa("Bicicletes AEM", 3, m, p);
	//Generar comanda inicial amb totes les unitiates necesaries per cobrir totes les botigues

	int unitatsPerTipus = int(empresa.getBotigues().size()) * unitats;

	Data d = Data(11, 9, 2020);
	lineaComanda inf_a{ TipusBicicleta::INFANTIL, unitatsPerTipus * 2, "A" };
	lineaComanda inf_b{ TipusBicicleta::INFANTIL, unitatsPerTipus, "B" };
	lineaComanda mtb_a{ TipusBicicleta::MTB, unitatsPerTipus * 2, "A" };
	lineaComanda mtb_b{ TipusBicicleta::MTB, unitatsPerTipus, "B" };
	lineaComanda ctr_a{ TipusBicicleta::CARRETERA, unitatsPerTipus * 2, "A" };
	lineaComanda ctr_b{ TipusBicicleta::CARRETERA, unitatsPerTipus, "B" };

	vector<lineaComanda> v = { inf_a,inf_b,mtb_a,mtb_b,ctr_a,ctr_b };
	Comanda c = Comanda(d, v);

	empresa.realitzaComanda(c, empresa.getProveidor());

	vector<pair<TipusBicicleta, int>> comandaBotiga;

	lineaComanda infBotiga{ TipusBicicleta::INFANTIL, unitats, "INF_A" };
	lineaComanda mtbBotiga{ TipusBicicleta::MTB, unitats, "MTB_A" };
	lineaComanda carBotiga{ TipusBicicleta::CARRETERA, unitats, "CTR_A" };

	lineaComanda infBotigaB{ TipusBicicleta::INFANTIL, unitats, "INF_B" };
	lineaComanda mtbBotigaB{ TipusBicicleta::MTB, unitats, "MTB_B" };
	lineaComanda carBotigaB{ TipusBicicleta::CARRETERA, unitats, "CTR_B" };

	vector<lineaComanda> vBotiga = { infBotiga, mtbBotiga, carBotiga, infBotigaB, mtbBotigaB, carBotigaB };

	Comanda cBotiga = Comanda((d + 10), vBotiga);

	//Cada botiga fa la comanda al magatzem de la reposicio inical.
	for (auto* b : empresa.getBotigues())
	{
		b->solicitaComanda(cBotiga, empresa.getMagatzem());
	}

}

int main(int argc, char* argv[])
{
	reposicioInical(10);

}