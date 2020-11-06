#pragma once

#include <string>
#include "BicicletaInfantil.h"
#include "BicicletaCarretera.h"
#include "BicicletaInfantil.h"
#include "BicicletaMTB.h"
#include "Data.h"


/**
* Enumeraciones necesarias para la creacion de bicicletas.
* Los valores son necesarios para poder realizar un control de errores eficiente.
* Si algun constructor recibe un parametro "ileagal" debeis establecer como valor por defecto
* el valor permitido mas peque�o del enum.
*
**/

enum class TipusBicicleta
{
	INFANTIL = 100,
	MTB = 200,
	CARRETERA = 250
};

enum class Fre
{
	DISC = 0,
	RIM = 1,
};

enum class Quadre
{
	ALUMINI = 0,
	CARBONO = 1,
};

enum class Roda
{
	RODA_26 = 0,
	RODA_27 = 1,
	RODA_29 = 2,
	RODA_14 = 3,
	RODA_20 = 4,
	RODA_700 = 5,
};


enum class Talla
{
	XS = 0,
	S = 1,
	M = 2,
	L = 3,
	XL = 4,
};


/**
* Bicicleta es una clase que contiene toda la informacion relevante para definir una bicicleta generica.
*
**/
class Bicicleta {
public:

	Bicicleta() {}
	Bicicleta(const string& model, const string& descripcio, int temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, const TipusBicicleta& tipus) :
		m_model(model), m_descripcio(descripcio), m_temporada(temporada), m_talla(talla), m_quadre(quadre), m_roda(roda), m_fre(fre), m_tipus(tipus) {}
	Bicicleta(const Bicicleta& b) { m_model = b.m_model; m_descripcio = b.m_descripcio; m_temporada = b.m_temporada; m_talla = b.m_talla; m_quadre = b.m_quadre; m_roda = b.m_roda; m_fre = b.m_fre; m_tipus = b.m_tipus; }
	virtual Bicicleta *clone() { return new Bicicleta(*this); }
	virtual ~Bicicleta() {}

	string getModel() const { return m_model; }
	string getDescripcio() const { return m_descripcio; }
	string getCodiRus() const { return m_codiRus; }
	int getTemporada() const { return m_temporada; }
	Talla getTalla() const { return m_talla; }
	Quadre getQuadre() const { return m_quadre; }
	Roda getRoda() const { return m_roda; }
	Fre getFre() const { return m_fre; }
	TipusBicicleta getTipus() const { return m_tipus; }
	Data getDataEntrada() const { return m_dataEntrada; } //No se si esta bien

	virtual void setModel(const string& model) final { m_model = model; }
	virtual void setDescripcio(const string& descripcio) final;
	virtual void setCodiRus(const string& codiRus) final;
	virtual void setTemporada(const int& temporada) final;
	virtual void setTalla(const Talla& talla) final;
	virtual void setRoda(const Roda& roda);
	virtual void setQuadre(const Quadre& quadre);
	virtual void setFre(const Fre& fre);
	virtual void setTipus(TipusBicicleta tipus);
	virtual void setPreu(TipusBicicleta cost);
	virtual float getPreu() const;
	void setDataEntrada(Data d) { m_dataEntrada = d; }

	bool operator<(const Bicicleta &b1) const;

protected:
	string m_model;
	string m_descripcio;
	int m_temporada;
	Talla m_talla;
	Quadre m_quadre;
	Roda m_roda;
	Fre m_fre;
	TipusBicicleta m_tipus;

private:
	string m_codiRus;
	float m_preu;
	Data m_dataEntrada;
};