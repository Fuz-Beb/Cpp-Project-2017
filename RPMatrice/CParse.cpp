#include "CParse.h"
#include "CException.h"



CParse::CParse()
{
	psPARChemin = nullptr;
	pPARFichier = nullptr;
}


CParse::CParse(char * psChemin)
{
	CParse();
	PARModifierChemin(psChemin);
}


CParse::~CParse()
{
	delete(psPARChemin);
	PARFermerFicher();
}


char * CParse::PARLireChemin()
{
	return psPARChemin;
}


void CParse::PARModifierChemin(char * psParam)
{
	unsigned int uiTaille = strlen(psParam);

	if(psPARChemin != NULL)
		delete(psPARChemin);

	psPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));

	if(psPARChemin == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psPARChemin, psParam, uiTaille);
}


void CParse::PAROuvrirFichier(char * psParam)
{
	pPARFichier = fopen(psParam, "r");

	if(pPARFichier == nullptr)
		throw CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");
}


void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}


char * CParse::PARLireLigne()
{
	// Position de d�part
	unsigned int uiCurseurInitial = ftell(pPARFichier);
	unsigned int uiSizeMaxBuffer = 0;

	// Mise du curseur � la fin du fichier pour le calcul de la taille de la chaine
	fseek(pPARFichier, 0, SEEK_END);

	// R�cup�ration de la taille maximum du buffer
	uiSizeMaxBuffer = ftell(pPARFichier) - uiCurseurInitial + 1;
	
	// Allocation de la chaine avec la "bonne taille"
	char * psBuffer = (char*) malloc (sizeof(char) * uiSizeMaxBuffer);
	if(psBuffer == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

	// R�cup�ration de la ligne
	psBuffer = fgets(psBuffer, uiSizeMaxBuffer, pPARFichier);
	
	if (psBuffer == nullptr)
		throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

	// Mise � l'�chelle de la chaine retourn�e
	psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
	if (psBuffer == nullptr)
		throw CException(ECHECALLOCATION, "Echec de la reallocation");

	return psBuffer;
}


char * CParse::PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille)
{
	char * psRetour = (char *) malloc(sizeof(char) * uiTaille + 1);
	if(psRetour == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	memcpy(psRetour, &psParam[uiDebut], uiTaille);
	psRetour[uiTaille] = '\0';

	PARConvertirStrMinusc(psRetour);

	return psRetour;
}


char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2) 
{
    size_t lengthStr1 = strlen(psStr1);
    size_t lengthStr2 = strlen(psStr2);
    char * psConcatenate = (char*)malloc(strlen(psStr1) + strlen(psStr2) + 1);

    if (psConcatenate != NULL)
    {
		strncpy(psConcatenate, psStr1, lengthStr1);
		strncpy(psConcatenate + lengthStr1, psStr2, lengthStr2);
    }

    else
	{
		delete(psConcatenate);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
    }

    return psConcatenate;
}


void CParse::PARConvertirStrMinusc(char * psParam)
{
    int uiBoucle = 0;

    while(psParam[uiBoucle] != '\0') {
        psParam[uiBoucle] = PARConvertirCharMinusc(psParam[uiBoucle]);
		uiBoucle++;
	}
}


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