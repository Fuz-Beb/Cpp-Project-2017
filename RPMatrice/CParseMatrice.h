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
	inline void PAMEcrireNbLigne(unsigned int uiNbLignes);
	inline unsigned int PAMLireNbColonnes();
	inline void PAMEcrireNbColonnes(unsigned int uiNbColonnes);

	// Methodes
	char * PAMLireType();
	void PAMAssignerNbLignes(char * sChaine);
	void PAMAssignerNbColonnes(char * sChaine);
public:
	void PAMTraiterFichier();
};

#endif