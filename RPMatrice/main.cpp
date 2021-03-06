#include "CMatrice.h"
#include "CException.h"
#include "CParseMatrice.h"
#include "CParse.h"
#include <iostream>
#include <windows.h>
#include <vld.h>


void main(unsigned int argc, char *argv[])
{
	try {
		// Exeception si l'utilisateur n'a pas renseigné de nom de fichier
		if (argc < 2) {
			CException * CEXObject = new CException(ECHECOUVERTUREFICHIER, "Aucun nom de fichier n'a ete fourni en parametre");
			throw *CEXObject;
		} 

		// Déclarations des variables
		unsigned int uiBoucleTableau = 0, uiSizeOfCMAMesMatrice = 0;
		double eValeurC = 0;
		bool bAdditionOuSoustraction = false, bCorrectValue = false;
		CMatrice<double> CMAResultOperation = CMatrice<double>();

		CParseMatrice ** CPAMonParseur = (CParseMatrice **) malloc(sizeof(CParseMatrice*) * argc - 1);
		CMatrice<double> ** CMAMesMatrices = (CMatrice<double> **) malloc(sizeof(CMatrice<double> *) * argc - 1);

		// Traitement des fichiers - Création des matrices
		for (uiBoucleTableau = 0 ; uiBoucleTableau < argc - 1; uiBoucleTableau++)
		{
			CPAMonParseur[uiBoucleTableau] = new CParseMatrice();
			CPAMonParseur[uiBoucleTableau]->PAMTraiterFichier(argv[uiBoucleTableau + 1]);
			CMAMesMatrices[uiBoucleTableau] = CPAMonParseur[uiBoucleTableau]->PAMRetournerMatrice();
			uiSizeOfCMAMesMatrice++;
		}

		// Affichage des matrices
		printf("---- Affichage des matrices ----\n\n");
		for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1; uiBoucleTableau++) {
			printf("Matrice numero %d \n", uiBoucleTableau+1);
			CMAMesMatrices[uiBoucleTableau]->MATAfficherMatrice();
			printf("\n");
		}

		// Demande de saisie utilisateur
		printf("---- Merci de renseigner la constante ----\n ");
		cin >> eValeurC;
		while (!bCorrectValue)
		{
		   if(cin.fail() || eValeurC == 0) {
				cout << "Seul des nombres supérieurs à 0 sont acceptes" << endl;
				cin.clear();
				cin.ignore();
				cin >> eValeurC;
			}
			else
				bCorrectValue = true;
		}

		// Multiplication et affichage du résultat
		printf("\n---- Division des matrices ----\n");
		for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
		{
			printf("\n\nMatrice %d * %0.2f \n", uiBoucleTableau+1, eValeurC);
			CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] * eValeurC;
			CMAResultOperation.MATAfficherMatrice();
		}


		// Division et affichage du résultat
		printf("\n---- Multiplication des matrices ----\n");
		for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
		{
			printf("\n\nMatrice %d / %0.2f \n", uiBoucleTableau+1, eValeurC);
			CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] / eValeurC;
			CMAResultOperation.MATAfficherMatrice();
		}


		// Additions des matrices
		printf("\n---- Addition des matrices ---- \n\n");
		CMAResultOperation = *CMAMesMatrices[0];

		for (uiBoucleTableau = 1; uiBoucleTableau < argc - 1; uiBoucleTableau++)
			CMAResultOperation = CMAResultOperation + *CMAMesMatrices[uiBoucleTableau];
	
		CMAResultOperation.MATAfficherMatrice();


		// Additions et soustractions des matrices
		printf("\n---- Additions et soustractions des matrices ----\n\n");
		CMAResultOperation = *CMAMesMatrices[0];

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
		printf("\n ---- Multiplication des matrices ---- \n\n");
		CMAResultOperation = *CMAMesMatrices[0];

		for (uiBoucleTableau = 1 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++)
			CMAResultOperation = CMAResultOperation * *CMAMesMatrices[uiBoucleTableau];

		CMAResultOperation.MATAfficherMatrice();

		// Désallocation mémoire
		for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++) {
			delete CPAMonParseur[uiBoucleTableau];
			delete CMAMesMatrices[uiBoucleTableau];
		}
		delete CPAMonParseur;
		delete CMAMesMatrices;

		} catch (CException & EXCObjet) {
			std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
			cout << "Appuyer sur une touche pour quitter le programme";
			cin.get();
	}
}