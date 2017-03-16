
#include "CMatrice.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>



template <class Type>
CMatrice<Type>::CMatrice()
{
}

template <class Type>
CMatrice<Type>::~CMatrice()
{
}

template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
}

template <class Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & MATMatrice)
{
}

template <class Type>
void CMatrice<Type>::MATEcrireNbLignes(unsigned int uiNbLignes)
{
}

template <class Type>
unsigned int CMatrice<Type>::MATLireNbLignes()
{
	return 0;
}

template <class Type>
void CMatrice<Type>::MATEcrireNbColonnes(unsigned int uiNbColonnes)
{
}

template <class Type>
unsigned int CMatrice<Type>::MATLireNbColonnes()
{
	return 0;
}

 template <class Type>
 CMatrice<Type> CMatrice<Type>::MATCalculerTransposee()
{
	return 0;
}

template <class Type>
CMatrice<Type> CMatrice<Type>::MATAfficherMatrice()
{
	return 0;
}

template <class Type>
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrices(double dNombre)
{
	return 0;
}

template <class Type>
void CMatrice<Type>::MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement)
{
}

template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	return 0;
}

template <class Type>
void CMatrice<Type>::MATAjouterColonnesM(unsigned int uiNbColonnes)
{
}

template <class Type>
void CMatrice<Type>::MATAjouterLignesM(unsigned int uiNbLignes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonneM(unsigned int uiNumColonne)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerLigneM(unsigned int uiNumLigne)
{
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	return 0;
}
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator-(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(Type & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(Type & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator=(CMatrice<Type> & MATMatrice)
{
	return 0;
}
