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
	unsigned int uiPARNbLignes;

	unsigned int uiPARNbColonnes;


private:
	unsigned int PARLireNbLignes();

	void PAREcrireNbLigne(unsigned int uiNbLignes);

	unsigned int PARLireNbColonnes();

	void PAREcrireNbColonnes(unsigned int uiNbColonnes);

public:
	void PARTraiterFichier(char * psChemin);

};
#endif
