#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <iostream>

#define ECHECALLOCATION 1
#define DIMENSIONHORSPORTEE 2
#define DIMENSIONINEGALE 3
#define ACTIONHORSPORTEE 4
#define FORMATFICHIERINCORRECTE 5
#define MAUVAISTYPE 6
#define ERREURTAILLE 7
#define DIVISIONPARZERO 8
#define ECHECOUVERTUREFICHIER 9
#define ECHECLECTURELIGNEFICHIER 10

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
