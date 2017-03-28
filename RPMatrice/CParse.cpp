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
	psPARChemin = nullptr;
	pPARFichier = nullptr;
}

/*****************************
Constructeur de confort
******************************
Entr�e : char * psChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParse::CParse(char * psChemin)
{
	PARModifierChemin(psChemin);
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
	delete(psPARChemin);
	PARFermerFicher();
}

/*****************************
Methode : Lire Chemin
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : char *
Entraine : Retourne le chemin de l'attribut
*****************************/
char * CParse::PARLireChemin()
{
	return psPARChemin;
}

/*****************************
Methode : Modifier Chemin
******************************
Entr�e : char * sParam
Necessit� : n�ant
Sortie : n�ant
Entraine : Modification de l'attribut sPARChemin
*****************************/
void CParse::PARModifierChemin(char * psParam)
{
	unsigned int uiTaille = strlen(psParam);

	if(psPARChemin != NULL)
		delete(psPARChemin);

	psPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));
	//sPARChemin = (char *) malloc(sizeof(char) * uiTaille + 1);

	if(psPARChemin == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psPARChemin, psParam, uiTaille);
}


/*****************************
Methode : Ouvrir Fichier
******************************
Entr�e : char * sChaine
Necessit� : Fichier
Sortie : n�ant
Entraine : Ouverture un fichier
*****************************/
void CParse::PAROuvrirFichier(char * psParam)
{
	pPARFichier = fopen(psParam, "r");

	if(pPARFichier == nullptr)
		throw CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");
}

/*****************************
Methode : Lire Ligne
******************************
Entr�e : n�ant
Necessit� : M�thode Traiter fichier / Ouvrir fichier
Sortie : char *
Entraine : Lecture d'une ligne du fichier et retourne sur le tas une cha�ne
*****************************/
char * CParse::PARLireLigne()
{
	// Position de d�part
	unsigned int uiCurseurInitial = ftell(pPARFichier);

	// Mise du curseur � la fin du fichier pour le calcul de la taille de la chaine
	fseek(pPARFichier, 0, SEEK_END);
	
	// Allocation de la chaine avec la "bonne taille"
	char * psBuffer = (char*) malloc (sizeof(char) * (ftell(pPARFichier) - uiCurseurInitial + 1));
	if(psBuffer == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

	// R�cup�ration de la ligne
	psBuffer = fgets(psBuffer, strlen(psBuffer), pPARFichier);
	if (psBuffer == nullptr)
		throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

	// Mise � l'�chelle de la chaine retourn�e
	psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
	if (psBuffer == nullptr)
		throw CException(ECHECALLOCATION, "Echec de la reallocation");

	return psBuffer;
}

/*****************************
Methode : SubString
******************************
Entr�e : char * sParam, unsigned int uiDebut, unsigned int uiTaille
Necessit� : n�ant
Sortie : char *
Entraine : Permet d'extraire une cha�ne d'une position � une autre
*****************************/
char * CParse::PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille)
{
	char * psRetour = (char *) malloc(sizeof(char) * uiTaille + 1);

	memcpy(psRetour, &psParam[uiDebut], uiTaille);
	psRetour[uiTaille] = '\0';

	PARConvertirMinusc(psRetour);

	return psRetour;
}

/*****************************
Methode : Concatener deux chaines
******************************
Entr�e : const char * sStr1, const char * sStr2
Necessit� : n�ant
Sortie : char *
Entraine : Retourne sur le tas la concatenation des deux cha�nes
*****************************/
char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2) 
{
    size_t lengthStr1 = strlen(psStr1);
    size_t lengthStr2 = strlen(psStr2);
    char * psConcatenate = (char*)malloc(strlen(psStr1) + strlen(psStr2) + 1);

    if (psConcatenate != NULL)
    {
		strncpy(psConcatenate, psStr1, lengthStr1 + 1);
		strncpy(psConcatenate + lengthStr1, psStr2, lengthStr2 + 1);
    }

    else
	{
		delete(psConcatenate);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
    }

    return psConcatenate;
}

/*****************************
Methode : Convertir Chaine Minuscule
******************************
Entr�e : char * sChaine
Necessit� : n�ant
Sortie : n�ant
Entraine : Convertir la chaine en param�tre en minuscule
*****************************/
void CParse::PARConvertirMinusc(char * psParam)
{
    int uiBoucle = 0;

    while(psParam[uiBoucle] != '\0') {
        psParam[uiBoucle] = PARConvertirCharMinusc(psParam[uiBoucle]);
		uiBoucle++;
	}
}

/*****************************
Methode : Convertir un char en minuscule
******************************
Entr�e : char cParam
Necessit� : M�thode Ouvrir fichier
Sortie : char
Entraine : Conversion d'un char en char minuscule
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
Methode : Fermer Fichier
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : Fermeture du fichier
*****************************/
void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}