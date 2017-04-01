#include "CException.h"


CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = nullptr;
}


CException::CException(unsigned int uiCodeErreur, char * psMessageErreur)
{
	uiEXCCode = uiCodeErreur;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessageErreur) + 1);
	
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psEXCMessage, psMessageErreur, strlen(psMessageErreur) + 1);
}


CException::~CException()
{
	if (psEXCMessage != nullptr)
		delete psEXCMessage;
}


unsigned int CException::EXCLectureCode()
{
	return uiEXCCode;
}


void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}


void CException::EXCLectureMessage()
{
	std::cout << psEXCMessage;
}


void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == nullptr)
		delete psEXCMessage;

	psEXCMessage = (char *) malloc(sizeof(char) * strlen(psMessage) + 1);
	strncpy(psEXCMessage, psMessage, strlen(psMessage) + 1);
}