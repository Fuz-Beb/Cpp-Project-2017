#include "CMatrice.h"
#include "CException.h"

// A supprimer
#include <iostream>
using namespace std;


/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice()
{
	ppqMATMatrice = (Type**)malloc(0);
	if (ppqMATMatrice == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
}


/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : L'objet est d�truit
*****************************/
template <class Type>
CMatrice<Type>::~CMatrice()
{
	unsigned int uiBoucle;

	for(uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
		delete[] ppqMATMatrice[uiBoucle];

	delete[] ppqMATMatrice;
}

/*****************************
Constructeur � deux arguments
******************************
Entr�e : unsigned int - code d'erreur, char * - message d'erreur
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	unsigned int uiBoucle;

	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	for (uiBoucle = 0; uiBoucle < uiMATNbColonnes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�/recopi�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & MATMatrice)
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	
	CMatrice<Type> * ppqMATMatriceRetour = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

	for (uiBoucleLigne = 0; uiBoucleLigne < ppqMATMatriceRetour->uiMATNbLignes; uiBoucleLigne++)
		for (uiBoucleColonne = 0; uiBoucleColonne < ppqMATMatriceRetour->uiMATNbColonnes; uiBoucleColonne++)
			ppqMATMatriceRetour->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
}

/*****************************
Methode : Ecrire nombre de lignes
******************************
Entr�e : unsigned int uiNbLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : modification nombre de lignes
*****************************/
template <class Type>
void CMatrice<Type>::MATEcrireNbLignes(unsigned int uiNbLignes)
{
	uiMATNbLignes = uiNbLignes;
}

/*****************************
Methode : Lire nombre de lignes
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : retourne nombre de lignes
*****************************/
template <class Type>
unsigned int CMatrice<Type>::MATLireNbLignes()
{
	return uiMATNbLignes;
}

/*****************************
Methode : Ecrire nombre de colonnes
******************************
Entr�e : unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : modification nombre de colonnes
*****************************/
template <class Type>
void CMatrice<Type>::MATEcrireNbColonnes(unsigned int uiNbColonnes)
{
	uiMATNbColonnes = uiNbColonnes;
}

/*****************************
Methode : Lire nombre de colonnes
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : retourne nombre de colonnes
*****************************/
template <class Type>
unsigned int CMatrice<Type>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template <class Type>
 CMatrice<Type> CMatrice<Type>::MATCalculerTransposee()
{
	return 0;
}


/*****************************
Methode : Afficher la matrice � l'�cran
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : L'affichage � l'�cran de la matrice
*****************************/
 template <class Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;

	// Verifier si c'est un objet alors ne pas afficher

	/*if(typeid(Type).name() != typeid(double).name() && typeid(Type).name() != typeid(float).name() && typeid(int).name() != typeid(char).name() && typeid(Type).name() != typeid(string).name())
		cout << "test : " << typeid(Type).name();*/
	printf("Affichage de la matrice :\n");
 
 
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++) {
			cout << ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] << "\t";
		}

		printf("\n");
	}
}

template <class Type>
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrice(double dNombre)
{
	return 0;
}

/*****************************
Methode : Modifier l'�l�ment � l'endroit de la matrice
******************************
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement
Necessit� : n�ant
Sortie : n�ant
Entraine : Modification de l'�l�ment
*****************************/
template <class Type>
void CMatrice<Type>::MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement)
{
	try {
		MATVerifierPortee(uiNbLignes, uiNbColonnes);
		ppqMATMatrice[uiNbLignes - 1][uiNbColonnes - 1] = tElement;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Lire l'�l�ment � l'endroit de la matrice
******************************
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : Type
Entraine : retourne l'element � l'endroit de la matrice
*****************************/
template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	try {
		MATVerifierPortee(uiNbLignes, uiNbColonnes);
		return ppqMATMatrice[uiNbLignes - 1][uiNbColonnes - 1];
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une/des colonnes � la droite de la matrice
******************************
Entr�e : unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation selon ajout nb colonnes
*****************************/
template <class Type>
void CMatrice<Type>::MATAjouterColonnesFin(unsigned int uiNbColonnes)
{
	try {
		unsigned int uiBoucle = 1;
		while(uiBoucle <= uiNbColonnes)
		{
			MATAjouterColonnePrecis(uiMATNbColonnes + 1);
			uiBoucle++;
		}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une/des lignes en bas de la matrice
******************************
Entr�e : unsigned int uiNbLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation selon ajout nb lignes
*****************************/
template <class Type>
void CMatrice<Type>::MATAjouterLignesFin(unsigned int uiNbLignes)
{
	try {
		unsigned int uiBoucle = 1;
		while(uiBoucle <= uiNbLignes)
		{
			MATAjouterLignePrecis(uiMATNbLignes + 1);
			uiBoucle++;
		}
	
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
}
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonneFin(unsigned int uiNbColonnes)
{

}

template <class Type>
void CMatrice<Type>::MATSupprimerLigneFin(unsigned int uiNbLignes)
{
}

/*****************************
Methode : Ajouter une/des colonnes � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et ajout d'une colonne
*****************************/
 template <class Type>
void CMatrice<Type>::MATAjouterColonnePrecis(unsigned int uiNumColonnes)
{
	try	{

		unsigned int uiBoucleDecalage = uiMATNbColonnes, uiBoucle;

		for(uiBoucle = 0 ; uiBoucle < uiMATNbLignes ; uiBoucle++) {
			ppqMATMatrice[uiBoucle] =  (Type*) realloc(ppqMATMatrice[uiBoucle], sizeof(Type) * uiMATNbColonnes + 1);
			
			if (ppqMATMatrice[uiBoucle] == NULL)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		if(uiNumColonnes <= uiMATNbColonnes)
			for(uiBoucle = 0 ; uiBoucle < uiMATNbLignes ; uiBoucle++)
				MATModifierElement(uiBoucle, uiBoucleDecalage, MATLireElement(uiBoucle, uiBoucleDecalage - 1));

		uiMATNbColonnes++;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une/des lignes � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et ajout d'une ligne
*****************************/
 template <class Type>
void CMatrice<Type>::MATAjouterLignePrecis(unsigned int uiNumLignes)
{
	try	{

		unsigned int uiBoucleDecalage = uiMATNbLignes, uiBoucle;

		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * uiMATNbLignes + 1); // Allocation des lignes
	
		if (ppqMATMatrice == NULL)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

		if(uiNumLignes <= uiMATNbLignes)
			for(uiBoucle = 0 ; uiBoucle < uiMATNbColonnes ; uiBoucle++)
				MATModifierElement(uiBoucleDecalage, uiBoucle, MATLireElement(uiBoucleDecalage - 1, uiBoucle));

		uiMATNbLignes++;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonnePrecis(unsigned int uiNumColonnes)
{
	try	{

		unsigned int uiBoucleDecalage = uiNumColonnes, uiBoucleColonne, uiBoucleLigne, uiBoucle;

		if(uiNumColonnes > uiMATNbColonnes)
			throw CException(ACTIONHORSPORTEE, "Echec de la suppression");

		else
			for(uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucle++)
					MATModifierElement(uiBoucleLigne, uiBoucleDecalage + uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleDecalage + uiBoucleColonne + 1));

		for(uiBoucle = 0 ; uiBoucle < uiMATNbLignes ; uiBoucle++) {
			ppqMATMatrice[uiBoucle] =  (Type*) realloc(ppqMATMatrice[uiBoucle], sizeof(Type) * uiMATNbColonnes - 1);
			
			if (ppqMATMatrice[uiBoucle] == NULL)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		uiMATNbColonnes--;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

template <class Type>
void CMatrice<Type>::MATSupprimerLignePrecis(unsigned int uiNumLignes)
{
}

/*****************************
Methode : V�rifier la dimension de la matrice
******************************
Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : (n�ant) ou (Exception DIMENSIONHORSPORTEE : les param�tres fournis sont incorrectes)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierPortee(unsigned int uiNumLignes, unsigned int uiNumColonnes)
{
	if (uiMATNbLignes < uiNumLignes || uiNumLignes == 0 || uiMATNbColonnes < uiNumColonnes || uiNumColonnes == 0)
		throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");
}

template <class Type>
void CMatrice<Type>::MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	if (uiMATNbLignes != uiNbLignes || uiMATNbColonnes != uiNbColonnes)
		throw CException(DIMENSIONINEGALE, "Dimension matrice in�gale");
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		
		// Test : Si la matrice contient autre chose que des valeurs num�riques alors exception

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		if (MATNewMatrice == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] + MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
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
	// Prendre en compte que si c'est un objet, il faut vider la matrice avant pour liberer la m�moire
	unsigned int uiBoucleLigne, uiBoucleColonne;

	if (uiMATNbLignes < MATMatrice.uiMATNbLignes)
		MATAjouterLignesFin(MATMatrice.uiMATNbLignes - uiMATNbLignes);
		
	else if (uiMATNbLignes > MATMatrice.uiMATNbLignes)
		MATSupprimerLigneFin(uiMATNbLignes - MATMatrice.uiMATNbLignes);
	
	if (uiMATNbColonnes < MATMatrice.uiMATNbColonnes)
		MATAjouterColonnesFin(MATMatrice.uiMATNbColonnes - uiMATNbColonnes);

	else if (uiMATNbColonnes > MATMatrice.uiMATNbColonnes)
		MATSupprimerColonneFin(uiMATNbColonnes - MATMatrice.uiMATNbColonnes);
	
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
	
	return *this;
}
