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
	string sPARTypeMatrice;

	unsigned int uiPARNbLignes;

	unsigned int uiPARNbColonnes;

	string sPARMatriceBuffer[];


public:
	void CParse();

	void ~CParse();

	void PARRemplirBuffer(unsigned int uiNbLignes);

	string PARLireBuffer();

	unsigned int PARLireNbLignes();

	unsigned int PARLireNbColonnes();

	void PAREcrireNbLigne(unsigned int uiNbLignes);

	void PAREcrireNbColonnes(unsigned int uiNbColonnes);

	/**
	 *  
	 */
	void PARLire();

	string PARLireTypeMatrice();

	void PAREcrireTypeMatrice(string sMessage);

};
#endif
