#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrice.h"


CMatrice::CMatrice()
{
}

CMatrice::~CMatrice()
{
}

CMatrice::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
}

CMatrice::CMatrice(CMatrice<Type> MATMatrice)
{
}

void CMatrice::MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement)
{
}

template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	return 0;
}

CMatrice<Type> CMatrice::MATCalculerTransposee()
{
	return 0;
}

CMatrice<Type> CMatrice::MATAfficherMatrice()
{
	return 0;
}

CMatrice<Type> CMatrice::MATAdditionnerMatrices()
{
	return 0;
}

CMatrice<Type> CMatrice::MATMultiplierMatrices()
{
	return 0;
}

CMatrice<Type> CMatrice::MATMultiplierMConst(double dNombre)
{
	return 0;
}

CMatrice<Type> CMatrice::MATDiviserMConst(double dNombre)
{
	return 0;
}

CMatrice<Type> CMatrice::MATPPuissanceMatrices(double dNombre)
{
	return 0;
}

CMatrice<Type> CMatrice::MATOperator=(CMatrice<Type> MATMatrice)
{
	return 0;
}

void CMatrice::MATEcrireNbLignes(unsigned int uiNbLignes)
{
}

unsigned int CMatrice::MATLireNbLignes()
{
	return 0;
}

void CMatrice::MATEcrireNbColonnes(unsigned int uiNbColonnes)
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
