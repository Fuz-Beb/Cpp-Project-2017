#include "CMatrice.h"
#include "CException.h"

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
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;

	ppqMATMatrice = (Type**) malloc (sizeof(Type*) * uiMATNbLignes); 
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqMATMatrice[0] = (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
	if (ppqMATMatrice[0] == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	MATInit();
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : L'objet est d�truit
*****************************/

// Pr�-condition : La lib�ration des pointeurs avant la suppression de la matrice est � la charge de l'utilisateur
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
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
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
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
	MATInit();
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
	unsigned int uiBoucleLigne, uiBoucleColonne, uiBoucle;

	uiMATNbLignes = MATMatrice.uiMATNbLignes;
	uiMATNbColonnes = MATMatrice.uiMATNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Affectation des valeurs
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
			ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
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
Sortie : unsigned int
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
	unsigned int uiBoucle1, uiBoucle2;

	CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbColonnes, uiMATNbLignes);

	for (uiBoucle2 = 0 ; uiBoucle2 < uiMATNbLignes ; uiBoucle2++)
		for (uiBoucle1= 0 ; uiBoucle1 < uiMATNbColonnes ; uiBoucle1++)
			MATNewMatrice.ppqMATMatrice[uiBoucle1][uiBoucle2] = ppqMATMatrice[uiBoucle2][uiBoucle1];
	
	return MATNewMatrice;
}


/*****************************
Methode : Mettre une matrice � la puissance
******************************
Entr�e : double dNombre
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Mise � la puissance de la matrice
*****************************/
template <class Type>
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrice(unsigned int uiNombre)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;
		int iExposant;

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		if (uiNombre == 0) {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = 1;
		}
		else {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++) {
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
					for (iExposant = uiNombre ; iExposant > 1 ; iExposant--)
						MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] *= ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
				}
		}

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
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
Methode : Lire l'�l�ment � l'endroit de la matrice
******************************
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : Type
Entraine : retourne l'element � l'endroit de la matrice
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
Methode : Initialise l'ensemble des valeurs de la matrice � la valeur 0
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�nant
Entraine : Mise � la valeur 0 � l'ensemble des cases de la matrice
*****************************/
 template <class Type>
 void CMatrice<Type>::MATInit()
 {
	 unsigned uiNbLignes, uiNbColonnes;

	 for(uiNbLignes = 1 ; uiNbLignes <= uiMATNbLignes ; uiNbLignes++)
		 for(uiNbColonnes = 1 ; uiNbColonnes <= uiMATNbColonnes ; uiNbColonnes++)
			 MATModifierElement(uiNbLignes, uiNbColonnes, 0);
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
 
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			cout << ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] << "\t";

		printf("\n");
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


/*****************************
Methode : Supprimer une/des colonnes � droite de la matrice
******************************
Entr�e : unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation selon suppression nb colonnes
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
Entr�e : unsigned int uiNbLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation selon suppression nb lignes
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
Methode : Ajouter une colonne � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et ajout d'une colonne
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
Methode : Ajouter une ligne � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et ajout d'une ligne
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
Methode : Supprimer une colonne � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et suppression d'une colonne
*****************************/

// Pr�-condition : La lib�ration des pointeurs avant la suppression de la colonne est � la charge de l'utilisateur
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
Methode : Supprimer unes ligne � un endroit pr�cis de la matrice
******************************
Entr�e : unsigned int uiNumLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : R�allocation et suppression d'une ligne
*****************************/

// Pr�-condition : La lib�ration des pointeurs avant la suppression de la ligne est � la charge de l'utilisateur
template <class Type>
void CMatrice<Type>::MATSupprimerLignePrecis(unsigned int uiNumLigne)
{
	try	{
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierPortee(uiNumLigne, uiMATNbColonnes);

		for(uiBoucleLigne = uiNumLigne; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
				for(uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
				ppqMATMatrice[uiBoucleLigne - 1][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		uiMATNbLignes--;

		delete ppqMATMatrice[uiMATNbLignes];

		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * uiMATNbLignes);
	
		if (ppqMATMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : V�rifier la port�e de l'action dans la matrice
******************************
Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : (n�ant) ou (Exception DIMENSIONHORSPORTEE : les param�tres fournis sont incorrectes)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne)
{
	if (uiMATNbLignes < uiNumLigne || uiNumLigne == 0 || uiMATNbColonnes < uiNumColonne || uiNumColonne == 0)
		throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");
}

/*****************************
Methode : V�rifier la dimension de la matrice
******************************
Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : (n�ant) ou (Exception DIMENSIONINEGALE : les dimensions fournis ne correspondent pas � la matrice)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	if (uiMATNbLignes != uiNbLignes || uiMATNbColonnes != uiNbColonnes)
		throw CException(DIMENSIONINEGALE, "Dimension matrice in�gale");
}

/*****************************
Methode : Surcharge operateur +
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/

// Pr�-condition : N�cessite la pr�sence de la surcharge de l'op�rateur + pour une matrice contenant des objets
template <class Type>
CMatrice<Type> CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] + MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur -
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/

// Pr�-condition : N�cessite la pr�sence de la surcharge de l'op�rateur - pour une matrice contenant des objets
template <class Type>
CMatrice<Type> CMatrice<Type>::operator-(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] - MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur / par constante
******************************
Entr�e : Type & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/

// Pr�-condition : N�cessite la pr�sence de la surcharge de l'op�rateur * pour une matrice contenant des objets
template <class Type>
CMatrice<Type> CMatrice<Type>::operator*(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] * qMATparam;

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur *
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/
// Pr�-condition : N�cessite la pr�sence de la surcharge de l'op�rateur * pour une matrice contenant des objets
template <class Type>
CMatrice<Type> CMatrice<Type>::operator*(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne, uiBoucleResult;

		if (uiMATNbColonnes != MATMatrice.uiMATNbLignes)
			throw CException(DIMENSIONINEGALE, "Dimension matrice in�gale");

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			for (uiBoucleColonne = 0 ; uiBoucleColonne < MATMatrice.uiMATNbColonnes ; uiBoucleColonne++) {
				for (uiBoucleResult = 0 ; uiBoucleResult < uiMATNbColonnes ; uiBoucleResult++) {
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] += ppqMATMatrice[uiBoucleLigne][uiBoucleResult] * MATMatrice.ppqMATMatrice[uiBoucleResult][uiBoucleColonne];
				}
			}
		}

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}

/*****************************
Methode : Surcharge operateur / par constante
******************************
Entr�e : Type & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/

// Pr�-condition : N�cessite la pr�sence de la surcharge de l'op�rateur / pour une matrice contenant des objets
template <class Type>
CMatrice<Type> CMatrice<Type>::operator/(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		if (qMATparam == 0)
			throw CException(DIVISIONPARZERO, "Divison par z�ro impossible");

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] / qMATparam;

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


/*****************************
Methode : Surcharge operateur =
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur en question membre � membre
*****************************/

// Pr�-condition : La lib�ration des pointeurs sur la matrice de destination est � la charge de l'utilisateur
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

/*****************************
Methode : Surcharge de l'op�rateur de diff�rence entre deux matrices
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Recherche de diff�rence entre les deux matrices
*****************************/
template <class Type>
bool CMatrice<Type>::operator!=(CMatrice<Type> & MATMatrice)
{
	unsigned int uiNbLignes, uiNbColonnes;

	if (uiMATNbLignes != MATMatrice.uiMATNbLignes || uiMATNbColonnes != MATMatrice.uiMATNbColonnes)
		return true;

	for (uiNbLignes = 0 ; uiNbLignes < uiMATNbLignes ; uiNbLignes++)
		for (uiNbColonnes = 0 ; uiNbColonnes < uiMATNbColonnes ; uiNbColonnes++) {
			if (ppqMATMatrice[uiNbLignes][uiNbColonnes] != MATMatrice.ppqMATMatrice[uiNbLignes][uiNbColonnes])
				return true;
		}
	return false;
}

/*****************************
Methode : Surcharge operateur * avec deux arguments
******************************
Entr�e : Type qMATparam, CMatrice<Type> & MATparam
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur * (pour avoir la commutativit�)
*****************************/
template <class Type>
CMatrice<Type> operator*(Type qMATparam, CMatrice<Type> & MATMatrice)
{
	return MATMatrice * qMATparam;
}
