#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrice.h"


void CMatrice::CMatrice()
{
}

void CMatrice::~CMatrice()
{
}

void CMatrice::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
}

void CMatrice::CMatrice(CMatrice MATMatrice)
{
}

void CMatrice::MATModifierElement(unsigned int uiNbLignes, element eElement)
{
}

element CMatrice::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	return 0;
}

CMatrice CMatrice::MATCalculerTransposee()
{
	return 0;
}

CMatrice CMatrice::MATAfficherMatrice()
{
	return 0;
}

CMatrice CMatrice::MATAdditionnerMatrices()
{
	return 0;
}

CMatrice CMatrice::MATMultiplierMatrices()
{
	return 0;
}

CMatrice CMatrice::MATMultiplierMConst(double dNombre)
{
	return 0;
}

CMatrice CMatrice::MATDiviserMConst(double dNombre)
{
	return 0;
}

CMatrice CMatrice::MATPPuissanceMatrices(double dNombre)
{
	return 0;
}

CMatrice CMatrice::MATOperator=(CMatrice Matrice)
{
	return 0;
}

void CMatrice::MATEcrireNbLignes(natural nNbLignes)
{
}

unsigned int CMatrice::MATLireNbLignes()
{
	return 0;
}

void CMatrice::MATEcrireNbColonnes(unsigned int nNbColonnes)
{
}

unsigned int CMatrice::MATLireNbColonnes()
{
	return 0;
}

void CMatrice::MATAjouterColonnesM(unsigned int uiNbColonnes)
{
}

void CMatrice::MATAjouterLignesM(unsigned int uiNbLignes)
{
}

void CMatrice::MATSupprimerColonneM(unsigned int uiNumColonne)
{
}

void CMatrice::MATSupprimerLigneM(unsigned int uiNumLigne)
{
}
