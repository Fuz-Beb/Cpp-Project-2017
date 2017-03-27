#include "CParseMatrice.h"
#include "CException.h"
#include "CMatrice.h"
#include "CParse.h"
#include <string>

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParseMatrice::CParseMatrice()
{
	MATMatrice = CMatrice<double>();
}

/*****************************
Constructeur de confort
******************************
Entr�e : char * sChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
unsigned int CParseMatrice::PAMLireNbLignes()
{
	return uiPAMNbLignes;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
unsigned int CParseMatrice::PAMLireNbColonnes()
{
	return uiPAMNbColonnes;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
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
Entr�e : 
Necessit� : n�ant
Sortie : n�ant
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
Entr�e : 
Necessit� : n�ant
Sortie : n�ant
Entraine : 
*****************************/
void CParseMatrice::PAMAjouterMatrice(CMatrice<double> & MATParam)
{
	MATMatrice = CMatrice<double>(MATParam);
}

/*****************************
Methode : Traiter fichier
******************************
Entr�e : 
Necessit� : n�ant
Sortie : n�ant
Entraine : 
*****************************/
void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = NULL;

	// Mise en place de l'ouverture du fichier
	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	// V�rification qu'on va bien lire une matrice double
	PAMVerifierType();

	// Lecture et �criture attribut du nombre de ligne
	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbLignes(sBuffer);

	// Lecture et �criture attribut du nombre de colonne
	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbColonnes(sBuffer);
	
	// Lire une ligne dans le vide (ligne inutile Matrice=[)
	sBuffer = CParse::PARLireLigne();
	delete(sBuffer);

	// Boucles pour lire et cr�er une CMatrice

	// Buffer d'un �l�ment sp�cifique ex : ligne 1 colonne 1
	char * sBufferDouble = nullptr;

	// Variables d'indice de boucles
	unsigned int uiMaxColonne = 0, uiBoucleBuffer = 0, uiIndiceLigne = 1, uiIndiceColonne = 1, uiBoucleBufferDouble = 0;
	
	// Cr�ation d'une CMatrice selon sa taille lu
	//CMatrice<double> pMATMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
	MATMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
		
	// Boucle TQ concernant le nombre de ligne � lire
	while(uiIndiceLigne <= uiPAMNbLignes) {
		uiMaxColonne = uiPAMNbColonnes; // Remise du compteur de colonne � la taille par souhait� (utile dans le cas d'espace)

		sBuffer = PARLireLigne(); // Remplissage du buffer par rapport � la ligne actuel

		// Boucle TQ concernant le nombre de colonne � lire (g�re les espaces en trop)
		while(uiBoucleBuffer < uiMaxColonne) {
			
			// Permet de v�rifier si il y a des espaces entre les �l�ments
			if(sBuffer[uiBoucleBuffer] != ' ') { 

				// Permet de g�rer le cas o� l'�lement � une dizaine, centaine...
				if(sBufferDouble != nullptr) {
					sBufferDouble = PARConcatenateString(sBufferDouble, PARSubString(sBuffer, uiBoucleBuffer, 1)); // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
				}

				// Dans le cas o� le second buffer d'�l�ment est vide, alors j'en cr�er un.
				else {
					sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
				}
				
				// Incr�mentation de l'indice du second buffer (dans le cas o� dizaine, centaine...)
				uiBoucleBufferDouble++;

				// On v�rifie s'il y a une dizaine, centaine... o� si on s'arrete et on modifie l'�lement dans la CMatrice
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

			// En cas d'espace en trop ex : 2    4 5 ; Je continue � parcourir en ignorant
			else {
				uiMaxColonne++;
			}

			// Permet de naviguer dans les colonnes du buffer
			uiBoucleBuffer++;
			
		}

		// Lib�rer le buffer g�n�ral pour �viter les fuites
		free(sBuffer);

		// Remise par d�faut des variables pour recommencer une boucle
		uiIndiceColonne = 1;
		uiBoucleBuffer = 0;
		uiIndiceLigne++;
	}

	// Fermer le fichier
	PARFermerFicher();
}