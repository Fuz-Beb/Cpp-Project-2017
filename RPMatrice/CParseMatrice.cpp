#include "CParseMatrice.h"
#include "CException.h"
#include "CMatrice.h"
#include "CParse.h"
#include <string>

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
Methode : Traiter fichier
******************************
Entrée : 
Necessité : néant
Sortie : néant
Entraine : 
*****************************/
void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	char * sBuffer = NULL;

	//CParseMatrice PAMParser = CParseMatrice();

	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	PAMVerifierType();

	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbLignes(sBuffer);

	sBuffer = CParse::PARLireLigne();
	PAMAssignerNbColonnes(sBuffer);
	
	sBuffer = CParse::PARLireLigne();
	delete(sBuffer);

	// ZONE EN CONSTRUCTION
	char * sBufferDouble = nullptr;
	unsigned int uiMaxColonne = 0, uiBoucleBuffer = 0, uiCompteurLigne = 0, uiCompteurColonne = 0, uiBoucleBufferDouble = 0;
	CMatrice<double> pMATMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
		
	while(PARLireLigne()) {
		uiMaxColonne = uiPAMNbColonnes; // Remise du compteur de colonne à la taille annoncée

		while(uiBoucleBuffer < uiMaxColonne) { // Parcourir les colonnes de la ligne actuel
			
			if(sBuffer[uiBoucleBuffer] != ' ') // Verifier si espace
				//sBufferDouble[uiBoucleBufferDouble] = sBuffer[uiBoucleBuffer]; // A FREE ET A STRDUP
				if(sBufferDouble != nullptr)
					sBufferDouble = PARConcatenateString(sBufferDouble, PARSubString(sBuffer, uiBoucleBuffer, 1)); // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
				
				else
					sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
				
				uiBoucleBufferDouble++;

				if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t') {
					pMATMatrice.MATModifierElement(uiCompteurLigne, uiCompteurColonne, stof(sBufferDouble));
					free(sBufferDouble);
			}

			else
				uiMaxColonne++;

			// Ligne ajouter element matrice

			uiBoucleBuffer++;
		}

		uiCompteurLigne++;
	}

	// Fermeture du fichier
	pMATMatrice.MATAfficherMatrice();
	PARFermerFicher();
	
}