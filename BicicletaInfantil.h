#pragma once

#include "Bicicleta.h"
#include <string>

/**
* BicicletaInfantil contine la inforacion relenavte para definir una bicicleta infantil.
*
**/
class BicicletaInfantil : public Bicicleta {
public:
	BicicletaInfantil() {}
	BicicletaInfantil(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, const bool& plegable) :
		Bicicleta(model, descripcio, temporada, talla, quadre, roda, fre, tipus), m_plegable(plegable) {}
	BicicletaInfantil(const BicicletaInfantil& bi) : Bicicleta(bi) { m_plegable = bi.m_plegable; }
	BicicletaInfantil* clone() { return new BicicletaInfantil(this*); }
	~BicicletaInfantil() {}

	bool getPlegable() const { return m_plegable; }
	void setPlegable(const bool& plegable) { m_plegable = plegable; }
	void setQuadre(const Quadre& quadre);
	void setFre(const Fre& fre) override;
	void setRoda(const Roda& roda) override;
	void setTipus(TipusBicicleta tipus) override;

protected:
	ostream& format(ostream& os) const override;

private:
	bool m_plegable;

};
