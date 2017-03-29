#include "CMatrice.h"
#include "CException.h"
#include "CParseMatrice.h"
#include "CParse.h"
#include <iostream>
//#include <vld.h>

void main(unsigned int argc, char *argv[])
{
	unsigned int uiBoucleTableau = 0, uiBoucleArgs = 1;
	double eValeurC = 0;
	bool bAdditionOuSoustraction = false;
	CMatrice<double> CMAResultOperation = CMatrice<double>();

	// Allocation des ressources
	CParseMatrice ** CPAMonParseur = (CParseMatrice **) malloc(sizeof(CParseMatrice*) * argc);
	CMatrice<double> ** CMAMesMatrices = (CMatrice<double> **) malloc(sizeof(CMatrice<double> *) * argc);

	// Traitement des fichiers
	for (uiBoucleArgs = 1 ; uiBoucleArgs < argc ; uiBoucleArgs++)
	{
		CPAMonParseur[uiBoucleTableau] = new CParseMatrice();
		CMAMesMatrices[uiBoucleTableau] = new CMatrice<double>();
		CPAMonParseur[uiBoucleTableau]->PAMTraiterFichier(argv[uiBoucleArgs]);
		CMAMesMatrices[uiBoucleTableau] = CPAMonParseur[uiBoucleTableau]->PAMRetournerMatrice();
		uiBoucleTableau++;
	}

	// Demande de saisie utilisateur
		cin >> eValeurC;


	// Multiplication et affichage du résultat
	printf("Division des matrices \n\n");
	for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
	{
		printf("Matrice %d * %0.2f. Resultat = \n", uiBoucleTableau+1, eValeurC);
		CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] * eValeurC;
		CMAResultOperation.MATAfficherMatrice();
	}


	// Division et affichage du résultat
	printf("Multiplication des matrices \n\n");
	for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
	{
		printf("Matrice %d / %0.2f. Resultat = \n", uiBoucleTableau+1, eValeurC);
		CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] / eValeurC;
		CMAResultOperation.MATAfficherMatrice();
	}


	// Additions des matrices
	printf("Addition des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1; uiBoucleTableau < argc - 1; uiBoucleTableau++)
		CMAResultOperation = CMAResultOperation + *CMAMesMatrices[uiBoucleTableau];
	
	CMAResultOperation.MATAfficherMatrice();


	// Additions et soustractions des matrices
	printf("Additions et soustractions des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1; uiBoucleTableau < argc - 1; uiBoucleTableau++)
	{
		if (bAdditionOuSoustraction == true) {
			CMAResultOperation = CMAResultOperation + *CMAMesMatrices[uiBoucleTableau];
			bAdditionOuSoustraction = false;
		} else {
			CMAResultOperation = CMAResultOperation - *CMAMesMatrices[uiBoucleTableau];
			bAdditionOuSoustraction = true;
		}
	}
	CMAResultOperation.MATAfficherMatrice();


	// Multiplication des matrices
	printf("Multiplication des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++)
		CMAResultOperation = CMAResultOperation * *CMAMesMatrices[uiBoucleTableau];

	CMAResultOperation.MATAfficherMatrice();
}
