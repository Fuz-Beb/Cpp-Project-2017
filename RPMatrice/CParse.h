#include <fstream>
#include <string.h>
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
	void PARConvertirStr2Double(char * sChaine);
	void PARConvertirMinusc(basic_string<char> & sChaine);
	void PARFermerFicher(FILE * pFichier);
};
#endif
