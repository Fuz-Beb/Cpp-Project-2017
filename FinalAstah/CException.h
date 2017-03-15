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
	unsigned int uiEXCCode;

	char * psEXCMessage;


public:
	CException();

	~CException();

	unsigned int EXCLectureCode();

	void EXCEcritureCode(unsigned int uiCodeErreur);

	char * EXCLectureMessage();

	void EXCEcritureMessage(char * psMessage);

};
#endif
