#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

#include "CParse.h"
#include "CMatrice.h"
#include <string>

class CParseMatrice : private CParse
{
private:
	// Attributs
	unsigned int uiPAMNbLignes;
	unsigned int uiPAMNbColonnes;
	CMatrice<double> matPAMMatrice;
	
	// Accesseurs
	inline unsigned int PAMLireNbLignes();
	inline void PAMAssignerNbLignes();
	inline unsigned int PAMLireNbColonnes();
	inline void PAMAssignerNbColonnes();
	
	// Methodes
	void PAMVerifierType();
	
public:
	// Constructeur
	explicit CParseMatrice();

	// Methodes
	CMatrice<double> * PAMRetournerMatrice();
	void PAMTraiterFichier(char * sChemin);
};

#endif