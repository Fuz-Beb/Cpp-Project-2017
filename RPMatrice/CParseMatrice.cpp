#include "CParseMatrice.h"
#include "CException.h"
#include "CMatrice.h"
#include "CParse.h"


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
	return uiPARNbLignes;
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
	uiPARNbLignes = std::stoi(sChaine);
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
	return uiPARNbColonnes;
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
	uiPARNbColonnes = std::stoi(sChaine);
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
/*void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	char * sBuffer = NULL;

	CParse::PAROuvrirFichier(sChemin);


	sBuffer = PAMLireType();

	if(sBuffer != "double")
		throw CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");

	delete(sBuffer);
	sBuffer = CParse::PARLireLigne(2);
	PAMAssignerNbLignes(sBuffer);

	delete(sBuffer);
	sBuffer = CParse::PARLireLigne(3);
	PAMAssignerNbColonnes(sBuffer);

	delete(sBuffer);
	sBuffer = CParse::PARLireLigne(4);
	
	delete(sBuffer);


	//if(atoi(sContenu[1].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	//uiPARNbLignes = atoi(sContenu[1].c_str());

	//if(atoi(sContenu[2].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

//	uiPARNbColonnes = atoi(sContenu[1].c_str());

	CMatrice<double> pMATMatrice = CMatrice<double>(uiPARNbLignes, uiPARNbColonnes);

	
}*/