#include "CParse.h"
#include "CException.h"

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
void PAROuvrirFichier()
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