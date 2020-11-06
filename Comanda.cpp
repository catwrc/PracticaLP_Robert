#include "Comanda.h"

Comanda::Comanda(const Data& dataComanda, vector<lineaComanda>& comanda) {
	m_dataComanda = dataComanda;
	for (int i = 0; i < m_comanda.size(); i++) {
		m_comanda[i].tipus = comanda[i].tipus;
		m_comanda[i].m_quantitat = comanda[i].m_quantitat;
		m_comanda[i].m_model = comanda[i].m_model;
	}
}

void Comanda::sumTotalBicicletes() {
	m_numBicicletes = 0;
	for (int i = 0; i < m_comanda.size(); i++) m_numBicicletes += m_comanda[i].m_quantitat;
}


float Comanda::getCostTotal() const {}