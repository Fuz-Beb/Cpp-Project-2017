#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CException.h"


CException::CException()
{
}

CException::~CException()
{
}

unsigned int CException::EXCLectureCode()
{
	return 0;
}

void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
}

char * CException::EXCLectureMessage()
{
	return 0;
}

void CException::EXCEcritureMessage(char * psMessage)
{
}
