#include "CParseMatrice.h"
#include "CException.h"
#include "CMatrice.h"
#include "CParse.h"
#include <string>

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParseMatrice::CParseMatrice()
{
	MATMatrice = CMatrice<double>();
}

/*****************************
Constructeur de confort
******************************
Entrée : char * sChemin
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParseMatrice::CParseMatrice(CMatrice<double> MATParam)
{
	MATMatrice = CMatrice<double>(MATParam);
}

CMatrice<double> * CParseMatrice::PAMRetournerMatrice()
{
	CMatrice<double> * pMatriceRetourner = new CMatrice<double>(MATMatrice);

	return pMatriceRetourner;
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
unsigned int CParseMatrice::PAMLireNbLignes()
{
	return uiPAMNbLignes;
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParseMatrice::PAMAssignerNbLignes(char * sChaine)
{
	char * sRetour = nullptr;
	
	sRetour = PARSubString(sChaine, 9, strlen(sChaine) - 9);

	if(sRetour == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	uiPAMNbLignes = atoi(sRetour);

	if(uiPAMNbLignes < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");
	
	delete(sChaine);
	delete(sRetour);
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
unsigned int CParseMatrice::PAMLireNbColonnes()
{
	return uiPAMNbColonnes;
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParseMatrice::PAMAssignerNbColonnes(char * sChaine)
{
	char * sRetour = nullptr;
	
	sRetour = PARSubString(sChaine, 11, strlen(sChaine) - 11);

	if(sRetour == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	uiPAMNbColonnes = atoi(sRetour);

	if(uiPAMNbColonnes < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");
	
	delete(sChaine);
	delete(sRetour);
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParseMatrice::PAMVerifierType() 
{
	char * sBuffer = nullptr, * sRetour = nullptr;

	sBuffer = PARLireLigne();

	sRetour = PARSubString(sBuffer, 12, 6);

	delete(sBuffer);

	if(strcmp(sRetour, "double") != 0) {
		delete(sRetour);
		throw CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");
	}

	delete(sRetour);
}

/*****************************
Methode : 
******************************
Entrée : 
Necessité : néant
Sortie : néant
Entraine : 
*****************************/
/*CMatrice<double> CParseMatrice::PAMRetournerMatrice()
{
	CMatrice<double> * MATRetour = CMatrice<double>(MATMatrice);

	return MATRetour;
}*/

/*****************************
Methode : 
******************************
Entrée : 
Necessité : néant
Sortie : néant
Entraine : 
*****************************/
void CParseMatrice::PAMAjouterMatrice(CMatrice<double> & MATParam)
{
	MATMatrice = CMatrice<double>(MATParam);
}

/*****************************
Methode : Traiter fichier
******************************
Entrée : 
Necessité : néant
Sortie : néant
Entraine : 
*****************************/
void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = NULL;

	// Mise en place de l'ouverture du fichier
	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	// Vérification qu'on va bien lire une matrice double
	PAMVerifierType();

	// Lecture et écriture attribut du nombre de ligne
	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbLignes(sBuffer);

	// Lecture et écriture attribut du nombre de colonne
	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbColonnes(sBuffer);
	
	// Lire une ligne dans le vide (ligne inutile Matrice=[)
	sBuffer = CParse::PARLireLigne();
	delete(sBuffer);

	// Boucles pour lire et créer une CMatrice

	// Buffer d'un élément spécifique ex : ligne 1 colonne 1
	char * sBufferDouble = nullptr;

	// Variables d'indice de boucles
	unsigned int uiMaxColonne = 0, uiBoucleBuffer = 0, uiIndiceLigne = 1, uiIndiceColonne = 1, uiBoucleBufferDouble = 0;
	
	// Création d'une CMatrice selon sa taille lu
	//CMatrice<double> pMATMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
	MATMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
		
	// Boucle TQ concernant le nombre de ligne à lire
	while(uiIndiceLigne <= uiPAMNbLignes) {
		uiMaxColonne = uiPAMNbColonnes; // Remise du compteur de colonne à la taille par souhaité (utile dans le cas d'espace)

		sBuffer = PARLireLigne(); // Remplissage du buffer par rapport à la ligne actuel

		// Boucle TQ concernant le nombre de colonne à lire (gère les espaces en trop)
		while(uiBoucleBuffer < uiMaxColonne) {
			
			// Permet de vérifier si il y a des espaces entre les éléments
			if(sBuffer[uiBoucleBuffer] != ' ') { 

				// Permet de gérer le cas où l'élement à une dizaine, centaine...
				if(sBufferDouble != nullptr) {
					sBufferDouble = PARConcatenateString(sBufferDouble, PARSubString(sBuffer, uiBoucleBuffer, 1)); // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
				}

				// Dans le cas où le second buffer d'élèment est vide, alors j'en créer un.
				else {
					sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
				}
				
				// Incrémentation de l'indice du second buffer (dans le cas où dizaine, centaine...)
				uiBoucleBufferDouble++;

				// On vérifie s'il y a une dizaine, centaine... où si on s'arrete et on modifie l'élement dans la CMatrice
				if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t') {
					//pMATMatrice.MATModifierElement(uiIndiceLigne, uiIndiceColonne, stof(sBufferDouble));
					MATMatrice.MATModifierElement(uiIndiceLigne, uiIndiceColonne, stof(sBufferDouble));

					sBufferDouble = nullptr;
					free(sBufferDouble);
					uiIndiceColonne++;
				}

				// Sinon on recommence une boucle pour aller concatener la dizaine, centaine...
				else {
					uiMaxColonne++;
				}
					
			}

			// En cas d'espace en trop ex : 2    4 5 ; Je continue à parcourir en ignorant
			else {
				uiMaxColonne++;
			}

			// Permet de naviguer dans les colonnes du buffer
			uiBoucleBuffer++;
			
		}

		// Libérer le buffer général pour éviter les fuites
		free(sBuffer);

		// Remise par défaut des variables pour recommencer une boucle
		uiIndiceColonne = 1;
		uiBoucleBuffer = 0;
		uiIndiceLigne++;
	}

	// Fermer le fichier
	PARFermerFicher();
}