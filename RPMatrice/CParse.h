#ifndef C_PARSE_H
#define C_PARSE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class CParse
{
private:
	// Attributs
	unsigned int uiPARNbLignes;
	unsigned int uiPARNbColonnes;

	// Accesseurs
	inline unsigned int PARLireNbLignes();
	inline void PAREcrireNbLigne(unsigned int uiNbLignes);
	inline unsigned int PARLireNbColonnes();
	inline void PAREcrireNbColonnes(unsigned int uiNbColonnes);

public:
	// Méthode
	void PARTraiterFichier(char * psChemin);
};
#endif
