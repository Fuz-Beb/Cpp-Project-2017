#include "CMatrice.h"

template <class Type>
CMatrice<Type>::CMatrice()
{
	ppqMATMatrice = (Type**)malloc(0);
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	/*psMATTypeMatrice = new char[20];
	strcpy(psMATTypeMatrice, Type);*/
}

template <class Type>
CMatrice<Type>::~CMatrice()
{
}

template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = new Type*[uiMATNbLignes]; // Allocation des lignes
	for (unsigned int eBoucle = 0; eBoucle < uiMATNbColonnes; eBoucle++) // Allocation des colonnes
		ppqMATMatrice[eBoucle] = new Type[uiMATNbColonnes];

	/*psMATTypeMatrice = new char[20];
	strcpy(psMATTypeMatrice, Type);*/
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
void CMatrice<Type>::MATEcrireTypeMatrice(char * sTypeMatrice)
{
}

template <class Type>
char * CMatrice<Type>::MATLireTypeMatrice()
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
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrice(double dNombre)
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
