#include "CParseMatrice.h"
#include "CException.h"
#include "CMatrice.h"

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char * CParseMatrice::PAMLireType() 
{
	return 0;
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

}

/*****************************
Methode : Traiter fichier
******************************
Entr�e : 
Necessit� : n�ant
Sortie : n�ant
Entraine : 
*****************************/
void CParseMatrice::PAMTraiterFichier()
{/*
	string sContenu[4];
	string sBuffer;
	char * sBufferDouble;
	unsigned int uiBoucle = 0, uiBoucleBuffer = 0, uiCompteurLigne = 0, uiCompteurColonne = 0, uiBoucleBufferDouble = 0, uiMaxColonne = 0;
	ifstream fichier("test.txt", ios::in); // Ouvrir le fichier en lecture

	if(!fichier)// Si ouverture a reussi
		throw CException(ECHECFICHIER, "Echec d'ouverture du fichier");

	while(getline(fichier, sContenu[uiBoucle])) {
		uiBoucle++;
		toLower(sContenu[0]);
	}

	if(sContenu[0] != "double")
		throw CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");

	if(atoi(sContenu[1].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	uiPARNbLignes = atoi(sContenu[1].c_str());

	if(atoi(sContenu[2].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	uiPARNbColonnes = atoi(sContenu[1].c_str());

	CMatrice<double> pMATMatrice = CMatrice<double>(uiPARNbLignes, uiPARNbColonnes);


	while(getline(fichier, sBuffer)) { // Parcourir les lignes jusqu'� la fin
		
		uiMaxColonne = uiPARNbColonnes; // Remise du compteur de colonne � la taille annonc�e

		while(uiBoucleBuffer < uiMaxColonne) { // Parcourir les colonnes de la ligne actuel
			
			if(sBuffer[uiBoucleBuffer] != ' ') { // Verifier si espace
				//sBufferDouble[uiBoucleBufferDouble] = sBuffer[uiBoucleBuffer]; // A FREE ET A STRDUP
				
				if(sBufferDouble != NULL)
					//sBufferDouble = // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
				
				sBufferDouble = strdup((const char*)sBuffer[uiBoucleBuffer]); // A FREE ET A STRDUP
				uiBoucleBufferDouble++;

				if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t')
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


	fichier.close();*/
}