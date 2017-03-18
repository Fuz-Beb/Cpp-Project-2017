#include "CMatrice.h"
#include "CException.h"


/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
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
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : L'objet est détruit
*****************************/
template <class Type>
CMatrice<Type>::~CMatrice()
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
		delete[] ppqMATMatrice[uiBoucle];

	delete[] ppqMATMatrice;
}

/*****************************
Constructeur à deux arguments
******************************
Entrée : unsigned int - code d'erreur, char * - message d'erreur
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation mémoire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	for (unsigned int eBoucle = 0; eBoucle < uiMATNbColonnes; eBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[eBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[eBoucle] == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
}

/*****************************
Constructeur de recopie
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé/recopié
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & MATMatrice)
{
	CMatrice<Type> ppqMATMatriceRetour = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
	
	unsigned int uiBoucleColonne;

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < ppqMATMatriceRetour.uiMATNbLignes; uiBoucleLigne++)
		for (uiBoucleColonne = 0; uiBoucleColonne < ppqMATMatriceRetour.uiMATNbColonnes; uiBoucleColonne++)
			ppqMATMatriceRetour.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
}

/*****************************
Methode : Ecrire nombre de lignes
******************************
Entrée : unsigned int uiNbLignes
Necessité : néant
Sortie : néant
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
Entrée : néant
Necessité : néant
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
Entrée : unsigned int uiNbColonnes
Necessité : néant
Sortie : néant
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
Entrée : néant
Necessité : néant
Sortie : néant
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
Methode : Afficher la matrice à l'écran
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : L'affichage à l'écran de la matrice
*****************************/
 template <class Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;

	printf("Affichage de la matrice :\n");
 
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLigne ; uiBoucleLigne++) {
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
Methode : Modifier l'élèment à l'endroit de la matrice
******************************
Entrée : unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement
Necessité : néant
Sortie : néant
Entraine : Modification de l'élèment
*****************************/
template <class Type>
void CMatrice<Type>::MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement)
{
	try {
		MATVerifierPortee(uiNbLignes, uiNbColonnes);
		ppqMATMatrice[uiNbLignes - 1][uiNbColonnes - 1] = tElement;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}
}

/*****************************
Methode : Lire l'élèment à l'endroit de la matrice
******************************
Entrée : unsigned int uiNbLignes, unsigned int uiNbColonnes
Necessité : néant
Sortie : Type
Entraine : retourne l'element à l'endroit de la matrice
*****************************/
template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	try {
		MATVerifierPortee(uiNbLignes, uiNbColonnes);
		return ppqMATMatrice[uiNbLignes - 1][uiNbColonnes - 1];
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}
}

template <class Type>
void CMatrice<Type>::MATAjouterColonnesFin(unsigned int uiNbColonnes)
{
	// NON FONCTIONNEL A FINIR
		/*ppqMATMatrice[uiMATNbColonnes + uiNbColonnes] =  (Type*) realloc(ppqMATMatrice[uiMATNbColonnes + uiNbColonnes], sizeof(Type) * uiMATNbColonnes + uiNbColonnes);
		if (ppqMATMatrice[uiMATNbColonnes + uiNbColonnes] == NULL)
			throw new CException(ECHECALLOCATION, "Echec de la reallocation");*/
}

template <class Type>
void CMatrice<Type>::MATAjouterLignesFin(unsigned int uiNbLignes)
{
	// NON FONCTIONNEL A FINIR
	/*ppqMATMatrice = (Type**) realloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == NULL)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");*/
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonneFin(unsigned int uiNbColonnes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerLigneFin(unsigned int uiNbLignes)
{
}

 template <class Type>
void CMatrice<Type>::MATAjouterColonnesPrecis(unsigned int uiNumColonnes)
{
}

 template <class Type>
void CMatrice<Type>::MATAjouterLignesPrecis(unsigned int uiNumLignes)
{
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
Methode : Vérifier la dimension de la matrice
******************************
Entrée : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessité : néant
Sortie : néant
Entraine : (néant) ou (Exception DIMENSIONHORSPORTEE : les paramètres fournis sont incorrectes)
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
		throw CException(DIMENSIONINEGALE, "Dimension matrice inégale");
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	try {
		MATVerifierDimension(MATMatrice.MATLireNbLignes(), MATMatrice.MATLireNbColonnes());
		// Traitement Ajout
	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
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
