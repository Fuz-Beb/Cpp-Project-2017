#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CException.h"


/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = NULL;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est détruit
*****************************/
CException::~CException()
{
	if (psEXCMessage != NULL)
		delete psEXCMessage;
}

/*****************************
Methode : Lecture du code d'erreur
*****************************
Entrée : néant
Necessité : néant
Sortie : unsigned int - le code d'erreur
Entraine : retourne le code d'erreur
*****************************/
unsigned int CException::EXCLectureCode()
{
	return uiEXCCode;
}

/*****************************
Methode : Modification du code d'erreur
******************************
Entrée : unsigned int - le code d'erreur
Necessité : néant
Sortie : néant
Entraine : modification du code d'erreur
*****************************/
void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}

/*****************************
Methode : Lecture du message d'erreur
******************************
Entrée : néant
Necessité : néant
Sortie : char * - le message d'erreur
Entraine : retourne le message d'erreur
*****************************/
char * CException::EXCLectureMessage()
{
	return psEXCMessage;
}

/*****************************
Methode : Modification du message d'erreur
******************************
Entrée : char * - le message d'erreur
Necessité : néant
Sortie : néant
Entraine : modification du message d'erreur
*****************************/
void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == NULL)
		delete psEXCMessage;

	psEXCMessage = new char[strlen(psMessage) + 1];
	strcpy(psEXCMessage, psMessage);
}