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
	uiPAMNbLignes = stoi(sChaine);
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
	uiPAMNbLignes = stoi(sChaine);	
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
char * CParseMatrice::PAMLireType() 
{
	return 0;
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

	// Toujours probleme de lien
	CParse * PAParser = new CParse();

	//PARParser.PAROuvrirFichier(sChemin);

	//sBuffer = PAMLireType();

	if(sBuffer != "double")
		throw CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");

	delete(sBuffer);
	//sBuffer = CParse::PARLireLigne(2);
	//PAMAssignerNbLignes(sBuffer);

	delete(sBuffer);
	//sBuffer = CParse::PARLireLigne(3);
	//PAMAssignerNbColonnes(sBuffer);

	delete(sBuffer);
	//sBuffer = CParse::PARLireLigne(4);
	
	delete(sBuffer);

	// Reste ici a faire boucle pour navigue dans les lignes
		// char * sBuffer = stdup(PARLireLigne(uiBoucle));
		// Puis boucle pour naviguer dans les colonnes du buffer
			// Faire un genre de substring pour découper le sBuffer en colonne et appeler ModifierElement Matrice
	
	// Certaines exception à prendre ne compte / A reformuler
	
	//if(atoi(sContenu[1].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	//uiPARNbLignes = atoi(sContenu[1].c_str());

	//if(atoi(sContenu[2].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

//	uiPARNbColonnes = atoi(sContenu[1].c_str());


	// A replacer plus haut pour créer la matrice double
	//CMatrice<double> pMATMatrice = CMatrice<double>(uiPARNbLignes, uiPARNbColonnes);


	// Code à replacer :

		/*
	while(getline(fichier, sBuffer)) { // Parcourir les lignes jusqu'à la fin
		
		uiMaxColonne = uiPARNbColonnes; // Remise du compteur de colonne à la taille annoncée

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