#pragma once

#include "Bicicleta.h"
#include <string>


enum class Categoria {
	RIGIDA = 0,
	DOBLE = 1,
};

enum class Modalitat {
	DESCENS = 0,
	ENDURO = 1,
	RALLY = 2,
	TRAIL = 3,
};

/**
* BicicletaMTB contine la inforacion relenavte para definir una bicicleta MTB.
*
**/

class BicicletaMTB : public Bicicleta {
public:
	BicicletaMTB() {}
	BicicletaMTB(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, Categoria categoria, Modalitat modalitat, bool electrica) :
		Bicicleta(model, descripcio, temporada, talla, quadre, roda, fre, tipus), m_categoria(categoria), m_modalitat(modalitat), m_electrica(electrica) {}
	BicicletaMTB(const BicicletaMTB& bm) : Bicicleta(bm) { m_categoria = bm.m_categoria; m_modalitat = bm.m_modalitat; m_electrica = bm.m_electrica; }
	BicicletaMTB* clone() { return new BicicletaMTB(*this); }
	~BicicletaMTB() override;

	void setCategoria(const Categoria& categoria);
	Categoria getCategoria() const;
	void setModalitat(const Modalitat& modalitat);
	Modalitat getModalitat() const;
	void setElectrica(const bool& electrica);
	bool getElectrica() const;
	void setRoda(const Roda& roda) override;
	void setFre(const Fre& fre) override;
	void setTipus(TipusBicicleta tipus) override;

protected:
	ostream& format(ostream& os) const override;
private:
	Categoria m_categoria;
	Modalitat m_modalitat;
	bool m_electrica;

};