#include "CParse.h"
#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParse::CParse()
{
	sPARChemin = nullptr;
	pPARFichier = nullptr;
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : L'objet est d�truit
*****************************/
CParse::~CParse()
{
	delete(sPARChemin);
	PARFermerFicher();
}

/*****************************
Constructeur de confort
******************************
Entr�e : char * sChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParse::CParse(char * sChemin)
{
	PARModifierChemin(sChemin);
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char * CParse::PARLireChemin()
{
	return sPARChemin;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char * CParse::PARLireLigne()
{
	
	char * test = nullptr;
	return test;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char * CParse::PARSubString(char * sParam, unsigned int uiDebut, unsigned int uiTaille)
{
	char * sRetour = (char *) malloc(sizeof(char *) * uiTaille + 1);

	sParam = PARLireLigne();

	memcpy(sRetour, &sParam[uiDebut], uiTaille);
	sRetour[uiTaille] = '\0';

	PARConvertirMinusc(sRetour);

	return sRetour;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char * CParse::PARConcatenateString(const char * sStr1, const char * sStr2) 
{
    size_t lengthStr1 = strlen(sStr1);
    size_t lengthStr2 = strlen(sStr2);
    char * sConcatenate = (char*)malloc(strlen(sStr1) + strlen(sStr2) + 1);

    if (sConcatenate != NULL)
    {
		strncpy(sConcatenate, sStr1, lengthStr1 + 1);
		strncpy(sConcatenate + lengthStr1, sStr2, lengthStr2 + 1);
    }

    else
    {
        free(sConcatenate);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
    }

    return sConcatenate;
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
void CParse::PARConvertirMinusc(char * sChaine)
{
    int uiBoucle = 0;

    while(sChaine[uiBoucle] != '\0')
        {
            sChaine[uiBoucle] = PARConvertirCharMinusc(sChaine[uiBoucle]);
            uiBoucle++;
        }
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
char CParse::PARConvertirCharMinusc(char cParam) 
{
    int iTemp = (int)cParam;

    if(iTemp >= 'A' && iTemp <= 'Z')
        {
            iTemp = iTemp + ('a' - 'A');

            return (char)iTemp;
        }

    else
    {
        return cParam;
    }
}

/*****************************
Methode : 
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : n�ant
*****************************/
void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL) {
		fclose(pPARFichier);
		delete(pPARFichier);
	}
}