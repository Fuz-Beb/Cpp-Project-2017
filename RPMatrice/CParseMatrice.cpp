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
void CParseMatrice::PAMAssignerNbLignes()
{
	char * sBuffer = nullptr, * sRetour = nullptr;

	sBuffer = CParse::PARLireLigne();

	// Verification du pr�fixe avant le =
	sRetour = PARSubString(sBuffer, 0, 8);

	if(strcmp(sRetour, "nblignes") == 1) {
		delete(sBuffer);
		delete(sRetour);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBLignes==");
	}

	delete(sRetour);

	sRetour = PARSubString(sBuffer, 9, strlen(sBuffer) - 9);

	if(sRetour == NULL) {
		delete(sBuffer);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	uiPAMNbLignes = atoi(sRetour);

	delete(sBuffer);
	delete(sRetour);

	if(uiPAMNbLignes < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

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
void CParseMatrice::PAMAssignerNbColonnes()
{
	char *sBuffer = nullptr, * sRetour = nullptr;
	
	sBuffer = CParse::PARLireLigne();

	// Verification du pr�fixe avant le =
	sRetour = PARSubString(sBuffer, 1, 11);

	if(strcmp(sRetour, "nbcolonnes=") == 1) {
		delete(sBuffer);
		delete(sRetour);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBColonnes=");
	}

	delete(sRetour);

	sRetour = PARSubString(sBuffer, 11, strlen(sBuffer) - 11);

	if(sRetour == NULL) {
		delete(sBuffer);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	uiPAMNbColonnes = atoi(sRetour);

	delete(sBuffer);
	delete(sRetour);

	if(uiPAMNbColonnes < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");
	

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

	sBuffer = CParse::PARLireLigne();

	// Verification du pr�fixe avant le =
	sRetour = PARSubString(sBuffer, 0, 11);

	if(strcmp(sRetour, "typematrice") == 1) {
		delete(sBuffer);
		delete(sRetour);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de TypeMatrice=");
	}

	delete(sRetour);

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
	PAMAssignerNbLignes();

	// Lecture et �criture attribut du nombre de colonne
	PAMAssignerNbColonnes();
	
	// Lire une ligne dans le vide (ligne inutile Matrice=[)
	sBuffer = CParse::PARLireLigne();

	PARConvertirMinusc(sBuffer);

	if(strcmp(sBuffer, "matrice=[\n") == 1)
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Matrice=[");

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