#include "CMatrice.h"
#include "CException.h"

using namespace std;


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
	if (ppqMATMatrice == nullptr)
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
	unsigned int uiBoucle;

	for(uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
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
	unsigned int uiBoucle;

	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation mémoire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == nullptr)
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
	unsigned int uiBoucleLigne, uiBoucleColonne;
	
	CMatrice<Type> * ppqMATMatriceRetour = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

	for (uiBoucleLigne = 0; uiBoucleLigne < ppqMATMatriceRetour->uiMATNbLignes; uiBoucleLigne++)
		for (uiBoucleColonne = 0; uiBoucleColonne < ppqMATMatriceRetour->uiMATNbColonnes; uiBoucleColonne++)
			ppqMATMatriceRetour->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
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
Sortie : unsigned int
Entraine : retourne nombre de colonnes
*****************************/
template <class Type>
unsigned int CMatrice<Type>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template <class Type>
 CMatrice<Type> & CMatrice<Type>::MATCalculerTransposee()
{
	unsigned int uiBoucle1, uiBoucle2;

	CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(uiMATNbColonnes, uiMATNbLignes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucle2 = 0 ; uiBoucle2 < uiMATNbLignes ; uiBoucle2++)
			for (uiBoucle1= 0 ; uiBoucle1 < uiMATNbColonnes ; uiBoucle1++)
				MATNewMatrice->ppqMATMatrice[uiBoucle1][uiBoucle2] = ppqMATMatrice[uiBoucle2][uiBoucle1];
	
	return * MATNewMatrice;
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
 
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			cout << ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] << "\t";

		printf("\n");
	}
}


/*****************************
Methode : Mettre une matrice à la puissance
******************************
Entrée : double dNombre
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Mise à la puissance de la matrice
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::MATPPuissanceMatrice(unsigned int uiNombre)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;
		int iExposant;

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		if (uiNombre == 0) {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
					MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = 1;
		}
		else {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++) {
					MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
					for (iExposant = uiNombre ; iExposant > 1 ; iExposant--)
						MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] *= ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
				}
		}
					
		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
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
void CMatrice<Type>::MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement)
{
	try {
		MATVerifierPortee(uiNumLigne, uiNumColonne);
		ppqMATMatrice[uiNumLigne - 1][uiNumColonne - 1] = tElement;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
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
 Type CMatrice<Type>::MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne)
{
	try {
		MATVerifierPortee(uiNumLigne, uiNumColonne);
		return ppqMATMatrice[uiNumLigne - 1][uiNumColonne - 1];
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une/des colonnes à la droite de la matrice
******************************
Entrée : unsigned int uiNbColonnes
Necessité : néant
Sortie : néant
Entraine : Réallocation selon ajout nb colonnes
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
Entrée : unsigned int uiNbLignes
Necessité : néant
Sortie : néant
Entraine : Réallocation selon ajout nb lignes
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


/*****************************
Methode : Supprimer une/des colonnes à droite de la matrice
******************************
Entrée : unsigned int uiNbColonnes
Necessité : néant
Sortie : néant
Entraine : Réallocation selon suppression nb colonnes
*****************************/
template <class Type>
void CMatrice<Type>::MATSupprimerColonneFin(unsigned int uiNbColonnes)
{
	try {
		unsigned int uiBoucle = 1;

		MATVerifierPortee(uiMATNbLignes, uiNbColonnes + 1);

		while(uiBoucle <= uiNbColonnes)
		{
			MATSupprimerColonnePrecis(uiMATNbColonnes);
			uiBoucle++;
		}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Supprimer une/des ligne en bas de la matrice
******************************
Entrée : unsigned int uiNbLignes
Necessité : néant
Sortie : néant
Entraine : Réallocation selon suppression nb lignes
*****************************/
template <class Type>
void CMatrice<Type>::MATSupprimerLigneFin(unsigned int uiNbLignes)
{
	try {
		unsigned int uiBoucle = 1;

		MATVerifierPortee(uiNbLignes + 1, uiMATNbColonnes);

		while(uiBoucle <= uiNbLignes)
		{
			MATSupprimerLignePrecis(uiMATNbLignes);
			uiBoucle++;
}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une colonne à un endroit précis de la matrice
******************************
Entrée : unsigned int uiNumColonnes
Necessité : néant
Sortie : néant
Entraine : Réallocation et ajout d'une colonne
*****************************/
 template <class Type>
void CMatrice<Type>::MATAjouterColonnePrecis(unsigned int uiNumColonne)
{
	try	{
		unsigned int uiBoucleColonne = 0, uiBoucleLigne = 0;

		if(uiNumColonne > uiMATNbColonnes + 1)
			throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");

		uiMATNbColonnes++;

		for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			ppqMATMatrice[uiBoucleLigne] =  (Type*) realloc(ppqMATMatrice[uiBoucleLigne], sizeof(Type) * uiMATNbColonnes);
			
			if (ppqMATMatrice[uiBoucleLigne] == nullptr)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		if(uiNumColonne < uiMATNbColonnes)
			for(uiBoucleColonne = uiMATNbColonnes ; uiBoucleColonne > uiNumColonne ; uiBoucleColonne--)
				for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
					ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 1] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 2];

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Ajouter une ligne à un endroit précis de la matrice
******************************
Entrée : unsigned int uiNumLignes
Necessité : néant
Sortie : néant
Entraine : Réallocation et ajout d'une ligne
*****************************/
 template <class Type>
void CMatrice<Type>::MATAjouterLignePrecis(unsigned int uiNumLigne)
{
	try	{
		unsigned int uiBoucleLigne, uiBoucleColonne;

		if (uiNumLigne > uiMATNbLignes + 1)
			throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");

		uiMATNbLignes++;

		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	
		if (ppqMATMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

		ppqMATMatrice[uiMATNbLignes - 1] = (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		
		if (ppqMATMatrice[uiMATNbLignes - 1] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");


		if (uiNumLigne < uiMATNbLignes)
			for(uiBoucleLigne = uiMATNbLignes ; uiBoucleLigne > uiNumLigne ; uiBoucleLigne--)
				for(uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
					ppqMATMatrice[uiBoucleLigne - 1][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne - 2][uiBoucleColonne];

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Supprimer une colonne à un endroit précis de la matrice
******************************
Entrée : unsigned int uiNumColonnes
Necessité : néant
Sortie : néant
Entraine : Réallocation et suppression d'une colonne
*****************************/
template <class Type>
void CMatrice<Type>::MATSupprimerColonnePrecis(unsigned int uiNumColonne)
{
	try	{

		unsigned int uiBoucleColonne = 0, uiBoucleLigne = 0;

		MATVerifierPortee(uiMATNbLignes, uiNumColonne);

		for(uiBoucleColonne = uiNumColonne ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 1] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			ppqMATMatrice[uiBoucleLigne] =  (Type*) realloc(ppqMATMatrice[uiBoucleLigne], sizeof(Type) * (uiMATNbColonnes - 1));
			
			if (ppqMATMatrice[uiBoucleLigne] == nullptr)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		uiMATNbColonnes--;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Supprimer unes ligne à un endroit précis de la matrice
******************************
Entrée : unsigned int uiNumLignes
Necessité : néant
Sortie : néant
Entraine : Réallocation et suppression d'une ligne
*****************************/
template <class Type>
void CMatrice<Type>::MATSupprimerLignePrecis(unsigned int uiNumLigne)
{
	try	{
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierPortee(uiNumLigne, uiMATNbColonnes);

		for(uiBoucleLigne = uiNumLigne; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
				for(uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
				ppqMATMatrice[uiBoucleLigne - 1][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * (uiMATNbLignes - 1));
	
		if (ppqMATMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

		uiMATNbLignes--;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Vérifier la portée de l'action dans la matrice
******************************
Entrée : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessité : néant
Sortie : néant
Entraine : (néant) ou (Exception DIMENSIONHORSPORTEE : les paramètres fournis sont incorrectes)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne)
{
	if (uiMATNbLignes < uiNumLigne || uiNumLigne == 0 || uiMATNbColonnes < uiNumColonne || uiNumColonne == 0)
		throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");
}

/*****************************
Methode : Vérifier la dimension de la matrice
******************************
Entrée : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessité : néant
Sortie : néant
Entraine : (néant) ou (Exception DIMENSIONINEGALE : les dimensions fournis ne correspondent pas à la matrice)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	if (uiMATNbLignes != uiNbLignes || uiMATNbColonnes != uiNbColonnes)
		throw CException(DIMENSIONINEGALE, "Dimension matrice inégale");
}

/*****************************
Methode : Surcharge operateur +
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
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

/*****************************
Methode : Surcharge operateur -
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator-(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] - MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur / par constante
******************************
Entrée : Type & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] * qMATparam;

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur *
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		if (uiMATNbColonnes != MATMatrice.uiMATNbLignes)
			throw CException(DIMENSIONINEGALE, "Dimension matrice inégale");

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] * MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur / par constante
******************************
Entrée : Type & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		if (qMATparam == 0)
			throw CException(DIVISIONPARZERO, "Divison par zéro impossible");

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] / qMATparam;

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur /
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> * MATNewMatrice = new CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
		if (MATNewMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++) {
				if (MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] == 0)
					throw CException(DIVISIONPARZERO, "Divison par zéro impossible");
				MATNewMatrice->ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] / MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
			}

		return *MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur =
******************************
Entrée : CMatrice<Type> & MATMatrice
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre à membre
*****************************/
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator=(CMatrice<Type> & MATMatrice)
{
	// Prendre en compte que si c'est un objet, il faut vider la matrice avant pour liberer la mémoire
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


/*****************************
Methode : Surcharge operateur * avec deux arguments
******************************
Entrée : Type qMATparam, CMatrice<Type> & MATparam
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur * (pour avoir la commutativité)
*****************************/
template <class Type>
CMatrice<Type> & operator*(Type qMATparam, CMatrice<Type> & MATparam)
{
	return MATparam * qMATparam;
}
