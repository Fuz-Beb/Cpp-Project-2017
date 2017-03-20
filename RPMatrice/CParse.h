#ifndef C_PARSE_H
#define C_PARSE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

#include <cstring>

#include <array>

using namespace std;

class CParse 
{
private:
	// Attributs
	unsigned int uiPARNbLignes;
	unsigned int uiPARNbColonnes;

	// Accesseurs
	inline unsigned int PARLireNbLignes();
	inline void PAREcrireNbLigne(unsigned int uiNbLignes);
	inline unsigned int PARLireNbColonnes();
	inline void PAREcrireNbColonnes(unsigned int uiNbColonnes);

	// Conversion en minuscule string
	void toLower(basic_string<char>& sChaine);
	void toLower(basic_string<wchar_t>& sChaine);
	//void string_to_float(string & sChaine, float* tab);

public:
	// Méthode
	void PARTraiterFichier(char * psChemin);
	
};
#endif
