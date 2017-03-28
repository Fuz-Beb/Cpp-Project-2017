#include "CParseMatrice.h"

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
Methode : Lire Nombre Lignes
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre de lignes précédemment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbLignes()
{
	return uiPAMNbLignes;
}

/*****************************
Methode : Assigner Nombre Lignes
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre de colonnes lu
*****************************/
void CParseMatrice::PAMAssignerNbLignes()
{
	char * sBuffer = nullptr, * sRetour = nullptr;

	sBuffer = CParse::PARLireLigne();

	// Verification du préfixe avant le =
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
Methode : Lire Nombre Colonnes
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre de colonnes qui a été précédemment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbColonnes()
{
	return uiPAMNbColonnes;
}

/*****************************
Methode : Assigner nombre colonnes
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre de colonne lu
*****************************/
void CParseMatrice::PAMAssignerNbColonnes()
{
	char *sBuffer = nullptr, * sRetour = nullptr;
	
	sBuffer = CParse::PARLireLigne();

	// Verification du préfixe avant le =
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
Methode : Vérifier le type
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : La vérification du type double sur la lecture du fichier
*****************************/
void CParseMatrice::PAMVerifierType() 
{
	char * sBuffer = nullptr, * sRetour = nullptr;

	sBuffer = CParse::PARLireLigne();

	// Verification du préfixe avant le =
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
Methode : Traiter fichier
******************************
Entrée : char * sChemin
Necessité : néant
Sortie : néant
Entraine : La lecture du fichier et création de la matrice associée
*****************************/
void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = nullptr, * sChaineBuffer = nullptr, * sBufferDoubleTemp = nullptr;

	// Mise en place de l'ouverture du fichier
	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	// Vérification qu'on va bien lire une matrice double
	PAMVerifierType();

	// Lecture et écriture attribut du nombre de ligne
	PAMAssignerNbLignes();

	// Lecture et écriture attribut du nombre de colonne
	PAMAssignerNbColonnes();
	
	// Lire une ligne dans le vide (ligne inutile Matrice=[)
	sBuffer = CParse::PARLireLigne();

	PARConvertirMinusc(sBuffer);

	if(strcmp(sBuffer, "matrice=[\n") == 1)
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Matrice=[");

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
					sBufferDoubleTemp = PARSubString(sBufferDouble, 0, strlen(sBufferDouble));
					sChaineBuffer = PARSubString(sBuffer, uiBoucleBuffer, 1);
					delete(sBufferDouble);
					sBufferDouble = nullptr;
					sBufferDouble = PARConcatenateString(sBufferDoubleTemp, sChaineBuffer); // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
					delete(sChaineBuffer);
					sChaineBuffer = nullptr;
					delete(sBufferDoubleTemp);
					sBufferDoubleTemp = nullptr;
				}

				// Dans le cas où le second buffer d'élèment est vide, alors j'en créer un.
				else {
					sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
				}
				
				// Incrémentation de l'indice du second buffer (dans le cas où dizaine, centaine...)
				uiBoucleBufferDouble++;

				// On vérifie s'il y a une dizaine, centaine... où si on s'arrete et on modifie l'élement dans la CMatrice
				if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t') {
					MATMatrice.MATModifierElement(uiIndiceLigne, uiIndiceColonne, stof(sBufferDouble));

					delete(sBufferDouble);
					sBufferDouble = nullptr;
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
		delete(sBuffer);

		// Remise par défaut des variables pour recommencer une boucle
		uiIndiceColonne = 1;
		uiBoucleBuffer = 0;
		uiIndiceLigne++;
	}

	// Fermer le fichier
	PARFermerFicher();
}