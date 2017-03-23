#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

#include <fstream>

class CParseMatrice
{
private:
	// Attributs
	static unsigned int uiPARNbLignes;
	static unsigned int uiPARNbColonnes;
	

	// Accesseurs
	static inline unsigned int PAMLireNbLignes();
	static inline void PAMAssignerNbLignes(char * sChaine);
	static inline unsigned int PAMLireNbColonnes();
	static inline void PAMAssignerNbColonnes(char * sChaine);

	// Methodes
	static char * PAMLireType();
	
public:
	//static void PAMTraiterFichier(char * sChemin);
};

#endif