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

	sPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));
	//sPARChemin = (char *) malloc(sizeof(char) * uiTaille + 1);

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
		throw CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");
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
	// Position de d�part
	unsigned int uiCurseurInitial = ftell(pPARFichier);

	// Mise du curseur � la fin du fichier pour le calcul de la taille de la chaine
	fseek(pPARFichier, 0, SEEK_END);
	
	// Allocation de la chaine avec la "bonne taille"
	char * sBuffer = (char*) malloc (sizeof(char) * (ftell(pPARFichier) - uiCurseurInitial + 1));
	if(sBuffer == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	fseek(pPARFichier, uiCurseurInitial, SEEK_SET);
	//fseek(pPARFichier, -uiCurseurInitial, SEEK_CUR);

	// R�cup�ration de la ligne
	sBuffer = fgets(sBuffer, strlen(sBuffer), pPARFichier);
	if (sBuffer == nullptr)
		throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

	// Mise � l'�chelle de la chaine retourn�e
	sBuffer = (char*) realloc(sBuffer, sizeof(char) * (strlen(sBuffer) + 1));
	if (sBuffer == nullptr)
		throw CException(ECHECALLOCATION, "Echec de la reallocation");

	return sBuffer;
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
	char * sRetour = (char *) malloc(sizeof(char) * uiTaille + 1);

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
		delete(sStr1);
		delete(sStr2);
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

    while(sChaine[uiBoucle] != '\0') {
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

    if(iTemp >= 'A' && iTemp <= 'Z') {
		iTemp = iTemp + ('a' - 'A');
        return (char)iTemp;
	}
    else
        return cParam;
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
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}