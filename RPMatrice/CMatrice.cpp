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
			MATAjouterColonnesPrecis(uiBoucle + uiMATNbColonnes);
			uiMATNbColonnes++;

	} catch(CException & EXCObjet) {
		std::cerr << EXCObjet.EXCLectureMessage << ". Code d'erreur : " << EXCObjet.EXCLectureCode();
}
}

template <class Type>
void CMatrice<Type>::MATAjouterLignesFin(unsigned int uiNbLignes)
{
	// NON FONCTIONNEL A FINIR
	try {
		
	
	} catch(CException & EXCObjet) {
		std::cerr << EXCObjet.EXCLectureMessage << ". Code d'erreur : " << EXCObjet.EXCLectureCode();
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
void CMatrice<Type>::MATAjouterColonnesPrecis(unsigned int uiNumColonnes)
{
	try	{

		unsigned int uiBoucleDecalage = uiMATNbColonnes;

		for(unsigned int uiBoucle = 0, uiBoucle < uiMATNbLignes, uiBoucle++) {
			ppqMATMatrice[uiBoucle] =  (Type*) realloc(ppqMATMatrice[uiBoucle], sizeof(Type) * uiMATNbColonnes + 1);
			
			if (ppqMATMatrice[uiBoucle] == NULL)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		uiMATNbColonnes++;

		if(uiNumColonnes <= uiMATNbColonnes)
			for(unsigned int uiBoucle = 0, uiBoucle < uiMATNbLignes, uiBoucle++)
				MATModifierElement(uiBoucle, uiBoucleDecalage, MATLireElement(uiBoucle, uiBoucleDecalage - 1));

	} catch(CException & EXCObjet) {
		std::cerr << EXCObjet.EXCLectureMessage << ". Code d'erreur : " << EXCObjet.EXCLectureCode();
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
void CMatrice<Type>::MATAjouterLignesPrecis(unsigned int uiNumLignes)
{
	try	{

		ppqMATMatrice = (Type**) realloc(sizeof(Type*) * uiMATNbLignes + 1); // Allocation des lignes
	
		if (ppqMATMatrice == NULL)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

		uiMATNbLignes++;

		if(uiNumLignes <= uiMATNbLignes)
			for(unsigned int uiBoucle = 0, uiBoucle < uiMATNbLignes, uiBoucle++)
				MATModifierElement(uiBoucle, uiBoucleDecalage, MATLireElement(uiBoucle, uiBoucleDecalage - 1));

	} catch(CException & EXCObjet) {
		std::cerr << EXCObjet.EXCLectureMessage << ". Code d'erreur : " << EXCObjet.EXCLectureCode();
	}
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonnePrecis(unsigned int uiNumColonnes)
{
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

		MATVerifierDimension(MATMatrice.MATLireNbLignes(), MATMatrice.MATLireNbColonnes());
		
		// Test : Si la matrice contient autre chose que des valeurs num�riques alors exception

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.MATLireNbLignes(), MATMatrice.MATLireNbColonnes());
		if (MATNewMatrice == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < MATLireNbLignes() ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < MATLireNbColonnes() ; uiBoucleColonne++)
				MATNewMatrice->MATModifierElement(uiBoucleLigne + 1, uiBoucleColonne + 1, MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1) + MATMatrice.MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1));

		return *this;

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
	return 0;
}
