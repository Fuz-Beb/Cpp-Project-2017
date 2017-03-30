#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <iostream>

#define ECHECALLOCATION 1
#define DIMENSIONHORSPORTEE 2
#define DIMENSIONINEGALE 3
#define FORMATFICHIERINCORRECTE 4
#define MAUVAISTYPE 5
#define ERREURTAILLE 6
#define DIVISIONPARZERO 7
#define ECHECOUVERTUREFICHIER 8
#define ECHECLECTURELIGNEFICHIER 9

class CException
{
private: 
	// Attributs
	unsigned int uiEXCCode;
	char * psEXCMessage;

public:
	// Constructeurs et destructeur
	explicit CException();
	explicit CException(unsigned int uiCodeErreur, char * psMessageErreur);
	~CException();

	// Accesseurs
	unsigned int EXCLectureCode();
	void EXCEcritureCode(unsigned int uiCodeErreur);
	char * EXCLectureMessage();
	void EXCEcritureMessage(char * psMessage);
};
#endif
