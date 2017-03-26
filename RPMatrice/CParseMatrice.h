#include <string.h>
#include "CParse.h"
#include "CMatrice.h"

#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

class CParseMatrice : public CParse
{
private:
	// Attributs
	unsigned int uiPAMNbLignes;
	unsigned int uiPAMNbColonnes;
	//CMatrice<double> MATMatrice;
	
	// Accesseurs
	inline unsigned int PAMLireNbLignes();
	inline void PAMAssignerNbLignes(char * sChaine);
	inline unsigned int PAMLireNbColonnes();
	inline void PAMAssignerNbColonnes(char * sChaine);
	
	// Methodes
	void PAMVerifierType();
	
public:
	CParseMatrice();
	CParseMatrice(CMatrice<double> MATParam);
	CMatrice<double> MATMatrice;
	//CMatrice<double> PAMRetournerMatrice();
	//CMatrice<double> PAMRetournerMatrice();
	void PAMAjouterMatrice(CMatrice<double> & MATParam);
	void PAMTraiterFichier(char * sChemin);
};

#endif