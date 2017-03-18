#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class CException
{
private: 
	// Attributs
	unsigned int uiEXCCode;
	char * psEXCMessage;

public:
	// Constructeur et destructeur
	CException();
	CException(unsigned int uiCodeErreur, char * psMessageErreur);
	~CException();

	// Accesseurs
	unsigned int EXCLectureCode();
	void EXCEcritureCode(unsigned int uiCodeErreur);
	char * EXCLectureMessage();
	void EXCEcritureMessage(char * psMessage);
};
#endif
