#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "natural.h"
#include "CParse.h"
#include "element.h"

class CMatrice
{
private:
	CMatrice tMATMatrice[][];

	natural uiMATNbLignes;

	natural uiMATNbColonnes;

	string sMATTypeMatrice;

	CParse cParse;
	CParse cParse;

public:
	void CMatrice();

	void ~CMatrice();

	void CMatrice(natural uiNbLignes, natural uiNbColonnes);
	dsfdsfsdfsdfs;
	void CMatrice(CMatrice Matrice);

	void MATModifierElement(natural uiNbLignes, natural uiNbColonnes, element eElement);

	element MATLireElement(natural uiNbLignes, natural uiNbColonnes);

	CMatrice MATCalculerTransposee();

	CMatrice MATAfficherMatrice();

	CMatrice MATAdditionnerMatrices();

	CMatrice MATMultiplierMatrices();

	CMatrice MATMultiplierMConst(double dNombre);

	CMatrice MATDiviserMConst(double dNombre);

	CMatrice MATPPuissanceMatrices(double dNombre);

	CMatrice MATOperator=(CMatrice Matrice);

	void MATEcrireNbLignes(natural nNbLignes);

	natural MATLireNbLignes();

	/**
	 *  
	 */
	void MATEcrireNbColonnes(natural nNbColonnes);

	natural MATLireNbColonnes();

	void MATAjouterColonnesM(natural uiNbColonnes);

	void MATAjouterLignesM(natural uiNbLignes);

	void MATSupprimerColonneM(natural uiNumColonne);

	void MATSupprimerLigneM(natural uiNumLigne);

};
#endif
