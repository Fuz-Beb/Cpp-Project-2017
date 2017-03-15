#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CParse.h"
#include "element.h"
#include "natural.h"

class CMatrice
{
private:
	CMatrice pMATMatrice[][];

	unsigned int uiMATNbLignes;

	unsigned int uiMATNbColonnes;

	string sMATTypeMatrice;

	CParse cParse;
	CParse cParse;

public:
	void CMatrice();

	void ~CMatrice();

	void CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	void CMatrice(CMatrice MATMatrice);

	void MATModifierElement(unsigned int uiNbLignes, element eElement);

	element MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	CMatrice MATCalculerTransposee();

	CMatrice MATAfficherMatrice();

	CMatrice MATAdditionnerMatrices();

	CMatrice MATMultiplierMatrices();

	CMatrice MATMultiplierMConst(double dNombre);

	CMatrice MATDiviserMConst(double dNombre);

	CMatrice MATPPuissanceMatrices(double dNombre);

	CMatrice MATOperator=(CMatrice Matrice);

	void MATEcrireNbLignes(natural nNbLignes);

	unsigned int MATLireNbLignes();

	/**
	 *  
	 */
	void MATEcrireNbColonnes(unsigned int nNbColonnes);

	unsigned int MATLireNbColonnes();

	void MATAjouterColonnesM(unsigned int uiNbColonnes);

	void MATAjouterLignesM(unsigned int uiNbLignes);

	void MATSupprimerColonneM(unsigned int uiNumColonne);

	void MATSupprimerLigneM(unsigned int uiNumLigne);

};
#endif
