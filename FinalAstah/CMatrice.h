#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

template <class Type>
class CMatrice
{
private:
	Type pMATMATMatrice[][];

	unsigned int uiMATNbLignes;

	unsigned int uiMATNbColonnes;

	char * psMATTypeMatrice;


public:
	CMatrice();

	~CMatrice();

	CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	CMatrice(CMatrice<Type> MATMatrice);

	void MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement);

	Type MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	CMatrice<Type> MATCalculerTransposee();

	CMatrice<Type> MATAfficherMatrice();

	CMatrice<Type> MATAdditionnerMatrices();

	CMatrice<Type> MATMultiplierMatrices();

	CMatrice<Type> MATMultiplierMConst(double dNombre);

	CMatrice<Type> MATDiviserMConst(double dNombre);

	CMatrice<Type> MATPPuissanceMatrices(double dNombre);

	CMatrice<Type> MATOperator=(CMatrice<Type> MATMatrice);

	void MATEcrireNbLignes(unsigned int uiNbLignes);

	unsigned int MATLireNbLignes();

	void MATEcrireNbColonnes(unsigned int uiNbColonnes);

	unsigned int MATLireNbColonnes();

	void MATAjouterColonnesM(unsigned int uiNbColonnes);

	void MATAjouterLignesM(unsigned int uiNbLignes);

	void MATSupprimerColonneM(unsigned int uiNumColonne);

	void MATSupprimerLigneM(unsigned int uiNumLigne);

};
#endif
