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
	~CException();

	// Accesseurs
	inline unsigned int EXCLectureCode();
	inline void EXCEcritureCode(unsigned int uiCodeErreur);
	inline char * EXCLectureMessage();
	inline void EXCEcritureMessage(char * psMessage);
};
#endif
