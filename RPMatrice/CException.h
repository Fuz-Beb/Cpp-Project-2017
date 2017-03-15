#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrice.h"

class CException : public CMatrice
{
private:
	unsigned int uiEXCCode;

	string sEXCMessage;


public:
	void CException();

	void ~CException();

	unsigned int EXCLectureCode();

	void EXCEcritureCode(unsigned int uiCodeErreur);

	string EXCLectureMessage();

	void EXCEcritureMessage(string sMessage);

};
#endif
