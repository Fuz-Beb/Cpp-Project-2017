#ifndef C_PARSE_H
#define C_PARSE_H

#include <assert.h>
#include <fstream>

using namespace std;

class CParse 
{
private:
	// Attributs
	char * sPARChemin;

public:
	// Constructeurs / Descructeurs
	CParse();
	CParse(char * sChemin);
	~CParse();

	// Méthode
	void PAROuvrirFichier(char * sChaine);
	char * PARLireLigne(unsigned int uiNumLigne);
	void PARConvertirStr2Double(char * sChaine);
	void PARFermerFicher();
	void PARConvertirMinusc(basic_string<char> & sChaine);
};
#endif
