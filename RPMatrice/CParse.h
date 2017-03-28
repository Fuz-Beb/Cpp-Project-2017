#ifndef C_PARSE_H
#define C_PARSE_H

#include <fstream>

using namespace std;

class CParse
{
private:
	// Attributs
	char * psPARChemin;
	FILE * pPARFichier;

public:
	// Constructeurs / Descructeurs
	CParse();
	CParse(char * psChemin);
	~CParse();

	// Méthode
	char * PARLireChemin();
	void PARModifierChemin(char * psParam);
	void PAROuvrirFichier(char * psParam);
	char * PARLireLigne();
	char * PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille);
	char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2);
	void PARConvertirMinusc(char * psParam);
	char PARConvertirCharMinusc(char cParam);
	void PARFermerFicher();
};
#endif
