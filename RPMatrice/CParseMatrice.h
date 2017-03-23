#ifndef C_PARSE_H
#define C_PARSE_H

#include <fstream>

class CParseMatrice
{
private:
	// Attributs
	unsigned int uiPARNbLignes;
	unsigned int uiPARNbColonnes;
	

	// Accesseurs
	inline unsigned int PAMLireNbLignes();
	inline void PAMAssignerNbLignes(char * sChaine);
	inline unsigned int PAMLireNbColonnes();
	inline void PAMAssignerNbColonnes(char * sChaine);

	// Methodes
	char * PAMLireType();
	
public:
	void PAMTraiterFichier();
};

#endif