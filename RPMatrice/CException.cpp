#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CException.h"


/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = NULL;
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est d�truit
*****************************/
CException::~CException()
{
	if (psEXCMessage != NULL)
		delete psEXCMessage;
}

/*****************************
Methode : Lecture du code d'erreur
*****************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : unsigned int - le code d'erreur
Necessit� : n�ant
Sortie : n�ant
Entraine : modification du code d'erreur
*****************************/
void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}

/*****************************
Methode : Lecture du message d'erreur
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : char * - le message d'erreur
Necessit� : n�ant
Sortie : n�ant
Entraine : modification du message d'erreur
*****************************/
void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == NULL)
		delete psEXCMessage;

	psEXCMessage = new char[strlen(psMessage) + 1];
	strcpy(psEXCMessage, psMessage);
}