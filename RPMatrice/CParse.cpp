#include "CParse.h"
#include "CException.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParse::CParse()
{
	sPARChemin = nullptr;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : L'objet est détruit
*****************************/
CParse::~CParse()
{
	delete(sPARChemin);
}

/*****************************
Constructeur de confort
******************************
Entrée : char * sChemin
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParse::CParse(char * sChemin)
{
	unsigned int uiTaille = strlen(sChemin);
	if(sPARChemin != NULL)
		delete(sPARChemin);

	sPARChemin = (char *) malloc(sizeof(char *) * uiTaille + 1);

	if(sPARChemin == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy_s(sPARChemin, uiTaille + 1, sChemin, uiTaille);
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void PAROuvrirFichier(char * sChaine)
{

}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void PARLireLigne(unsigned int uiNumLigne)
{

}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void PARConvertirStr2Double(char * sChaine)
{

}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void PARFermerFicher()
{

}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void PARConvertirMinusc(basic_string<char> & sChaine)
{
   for (basic_string<char>::iterator p = sChaine.begin();
        p != sChaine.end(); ++p) {
      *p = tolower(*p);
   }
}


/*
void string_to_float(string & chaine, float* tab)
{
	int cc=nbre_colonne((char*)chaine.c_str());
	tab=new float [cc];
	for(int j=0;j<cc;j++) {
		string X;
		X=chaine.substr(j*8+j,8);
		tab[j]=atof(X.c_str());
		printf("tab[%d]= %f",j,tab[j]) ;
	}
}
*/
