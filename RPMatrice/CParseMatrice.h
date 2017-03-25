#include <string.h>
#include "CParse.h"

#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

class CParseMatrice : public CParse
{
private:
	// Attributs
	unsigned int uiPAMNbLignes;
	unsigned int uiPAMNbColonnes;
	

	// Accesseurs
	inline unsigned int PAMLireNbLignes();
	inline void PAMAssignerNbLignes(char * sChaine);
	inline unsigned int PAMLireNbColonnes();
	inline void PAMAssignerNbColonnes(char * sChaine);

	// Methodes
	void PAMVerifierType();
	
public:
	void PAMTraiterFichier(char * sChemin);
};

#endif