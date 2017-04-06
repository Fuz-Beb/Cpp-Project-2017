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
	try {
		unsigned int uiTaille = strlen(psParam);

		if(psPARChemin != NULL)
			delete(psPARChemin);

		psPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));

		if(psPARChemin == NULL) {
			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		strncpy(psPARChemin, psParam, uiTaille);
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return;
	}
}


void CParse::PAROuvrirFichier(char * psParam)
{
	try {
		pPARFichier = fopen(psParam, "r");

		if(pPARFichier == nullptr) {
			CException * CEXObject = new CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");
			throw *CEXObject;
		}
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}


void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}


char * CParse::PARLireLigne()
{
	try {
		// Position de départ
		unsigned int uiCurseurInitial = ftell(pPARFichier);
		unsigned int uiSizeMaxBuffer = 0;

		// Mise du curseur à la fin du fichier pour le calcul de la taille de la chaine
		fseek(pPARFichier, 0, SEEK_END);

		// Récupération de la taille maximum du buffer
		uiSizeMaxBuffer = ftell(pPARFichier) - uiCurseurInitial + 1;
	
		// Allocation de la chaine avec la "bonne taille"
		char * psBuffer = (char*) malloc (sizeof(char) * uiSizeMaxBuffer);
		if(psBuffer == NULL) {
			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

		// Récupération de la ligne
		psBuffer = fgets(psBuffer, uiSizeMaxBuffer, pPARFichier);
	
		if (psBuffer == nullptr) {
			CException * CEXObject = new CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");
			throw *CEXObject;
		}

		// Mise à l'échelle de la chaine retournée
		psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
		if (psBuffer == nullptr) {
			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		return psBuffer;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}


char * CParse::PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille)
{
	try {
		char * psRetour = (char *) malloc(sizeof(char) * uiTaille + 1);
		if(psRetour == NULL) {
			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		memcpy(psRetour, &psParam[uiDebut], uiTaille);
		psRetour[uiTaille] = '\0';

		PARConvertirStrMinusc(psRetour);

		return psRetour;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}


char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2) 
{
	try {
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
			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		return psConcatenate;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
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