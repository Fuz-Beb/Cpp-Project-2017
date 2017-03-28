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
	psPARChemin = nullptr;
	pPARFichier = nullptr;
}

/*****************************
Constructeur de confort
******************************
Entrée : char * psChemin
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParse::CParse(char * psChemin)
{
	PARModifierChemin(psChemin);
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
	delete(psPARChemin);
	PARFermerFicher();
}

/*****************************
Methode : Lire Chemin
******************************
Entrée : néant
Necessité : néant
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
Entrée : char * sParam
Necessité : néant
Sortie : néant
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
Entrée : char * sChaine
Necessité : Fichier
Sortie : néant
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
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : char *
Entraine : Lecture d'une ligne du fichier et retourne sur le tas une chaîne
*****************************/
char * CParse::PARLireLigne()
{
	// Position de départ
	unsigned int uiCurseurInitial = ftell(pPARFichier);

	// Mise du curseur à la fin du fichier pour le calcul de la taille de la chaine
	fseek(pPARFichier, 0, SEEK_END);
	
	// Allocation de la chaine avec la "bonne taille"
	char * psBuffer = (char*) malloc (sizeof(char) * (ftell(pPARFichier) - uiCurseurInitial + 1));
	if(psBuffer == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

	// Récupération de la ligne
	psBuffer = fgets(psBuffer, strlen(psBuffer), pPARFichier);
	if (psBuffer == nullptr)
		throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

	// Mise à l'échelle de la chaine retournée
	psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
	if (psBuffer == nullptr)
		throw CException(ECHECALLOCATION, "Echec de la reallocation");

	return psBuffer;
}

/*****************************
Methode : SubString
******************************
Entrée : char * sParam, unsigned int uiDebut, unsigned int uiTaille
Necessité : néant
Sortie : char *
Entraine : Permet d'extraire une chaîne d'une position à une autre
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
Entrée : const char * sStr1, const char * sStr2
Necessité : néant
Sortie : char *
Entraine : Retourne sur le tas la concatenation des deux chaînes
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
Entrée : char * sChaine
Necessité : néant
Sortie : néant
Entraine : Convertir la chaine en paramètre en minuscule
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
Entrée : char cParam
Necessité : Méthode Ouvrir fichier
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
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : Fermeture du fichier
*****************************/
void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}