#include <fstream>
#include <iostream> 
#include <string>

#ifndef C_PARSE_H
#define C_PARSE_H

#include <fstream>

using namespace std;

class CParse
{
private:
	// Attributs
	char * sPARChemin;
	FILE * pPARFichier;

public:
	// Constructeurs / Descructeurs
	CParse();
	CParse(char * sChemin);
	~CParse();

	// Méthode
	char * PARLireChemin();
	void PARModifierChemin(char * sParam);
	void PAROuvrirFichier(char * sChaine);
	char * PARLireLigne();
	char * PARSubString(char * sParam, unsigned int uiDebut, unsigned int uiTaille);
	char * CParse::PARConcatenateString(const char * sStr1, const char * sStr2);
	void PARConvertirMinusc(char * sChaine);
	char PARConvertirCharMinusc(char cParam);
	void PARFermerFicher();
};
#endif
