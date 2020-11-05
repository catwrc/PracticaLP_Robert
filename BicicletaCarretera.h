#pragma once

#include "Bicicleta.h"

enum class ModalitatC {
	AERO,
	GRANFONDO,
	GRAVEL,
	RENDIMIENTO,
};

/**
* BicicletaCarretera contine la inforacion relenavte para definir una bicicleta de carretera.
* 
**/
class BicicletaCarretera: public Bicicleta
{
public:
	BicicletaCarretera(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, ModalitatC modalitat, bool electrica) { Bicicleta(model, descripcio, temporada, talla, quadre, roda, fre, tipus); m_modalitat = modalitat; m_electrica = electrica;}

	//BicicletaCarretera(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, ModalitatC modalitat, bool electrica) { Bicicleta(model, descripcio, temporada, talla, quadre, roda, fre, tipus); }
	~BicicletaCarretera();
	void setModalitat(const ModalitatC& modalitat) { m_modalitat = modalitat; }
	ModalitatC getModalitat() const { return m_modalitat; }

	void setElectricaC(const bool& electrica) { m_electrica = electrica; }
	bool getElectrica() const { return m_electrica; }
	void setRoda(const Roda& roda) override;
	void setTipus(TipusBicicleta tipus) override;

protected:
	ostream& format(ostream& os) const override;
private:

	ModalitatC m_modalitat;
	bool m_electrica;


};

