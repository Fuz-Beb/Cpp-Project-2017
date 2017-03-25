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
	pPARFichier = nullptr;
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
	PARFermerFicher(pPARFichier);
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
	PARModifierChemin(sChemin);
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
char * CParse::PARLireChemin()
{
	return sPARChemin;
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParse::PARModifierChemin(char * sParam)
{
	unsigned int uiTaille = strlen(sParam);

	if(sPARChemin != NULL)
		delete(sPARChemin);

	sPARChemin = (char *) malloc(sizeof(char *) * uiTaille + 1);

	if(sPARChemin == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(sPARChemin, sParam, uiTaille);
}


/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParse::PAROuvrirFichier(char * sChaine)
{
	pPARFichier = fopen(sChaine, "r");

	if(pPARFichier == nullptr)
		throw CException(ECHECFICHIER, "Echec d'ouverture du fichier");
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
char * CParse::PARLireLigne()
{
	char * sBuffer = nullptr;

	getline();

	getline(pPARFichier, sBuffer);
	
	char * test = nullptr;
	return test;
}

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParse::PARConvertirStr2Double(char * sChaine)
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
void CParse::PARConvertirMinusc(basic_string<char> & sChaine)
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

/*****************************
Methode : 
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : néant
*****************************/
void CParse::PARFermerFicher(FILE * pFichier)
{
	if(pFichier != NULL) {
		fclose(pFichier);
		delete(pPARFichier);
	}
}
