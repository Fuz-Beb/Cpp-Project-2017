#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"
#include <iostream>
#include <stdint.h>

void main()
{

	// OK - Test constructeur par défaut
		//CMatrice<int> * a = new CMatrice<int>();

	// OK - Test constructeur de recopie
		//CMatrice<int> * b = new CMatrice<int>(* a);

	// OK - Test destructeur par défaut
		//delete(a);

	// OK - Test méthode MATAfficherMatrice
		/*CMatrice<int> c = CMatrice<int>(2, 2);
		c.MATModifierElement(1,1, 1);
		c.MATModifierElement(1,2, 2);
		c.MATModifierElement(2,1, 3);
		c.MATModifierElement(2,2, 4);
		c.MATAfficherMatrice();*/

	// Test de modification et de lecture des élements de la matrice
	
	// Matrice 1
		CMatrice<int> Matrice1 = CMatrice<int>(4,4);
		Matrice1.MATModifierElement(1,1, 7);
		Matrice1.MATModifierElement(1,2, 98);
		Matrice1.MATModifierElement(2,1, 0);
		Matrice1.MATModifierElement(2,2, 6);

	// Matrice 2
		CMatrice<int> Matrice2 = CMatrice<int>(4,4);
		Matrice2.MATModifierElement(1,1, 0);
		Matrice2.MATModifierElement(1,2, -1);
		Matrice2.MATModifierElement(2,1, 73);
		Matrice2.MATModifierElement(2,2, 922);

	// Matrices
		CMatrice<int> Matrice3 = CMatrice<int>(2,2);
		CMatrice<int> Matrice4 = CMatrice<int>(2,2);

		Matrice3.MATModifierElement(1,1, 1);
		Matrice3.MATModifierElement(1,2, 2);
		Matrice3.MATModifierElement(2,1, 3);
		Matrice3.MATModifierElement(2,2, 4);

	
	// Test d'affichage :
	
		printf("AVANT : \n");
		Matrice3.MATAfficherMatrice();

	// OK - Test d'affichage + MATAjouterColonnesFin
		/*
		Matrice3.MATAjouterColonnesFin(1);
		Matrice3.MATModifierElement(2, 3, 1);
		Matrice3.MATModifierElement(1, 3, 1);

		Matrice3.MATAjouterColonnesFin(1);
		Matrice3.MATModifierElement(2, 4, 9);
		Matrice3.MATModifierElement(1, 4, 8);
		*/

	// OK - Test d'affichage + MATAjouterColonnePrecis
		/*
		Matrice3.MATAjouterColonnePrecis(2);
		Matrice3.MATModifierElement(1, 2, 7);
		Matrice3.MATModifierElement(2, 2, 6);
		Matrice3.MATAjouterColonnePrecis(2);
		Matrice3.MATModifierElement(1, 2, 9);
		Matrice3.MATModifierElement(2, 2, 8);
		Matrice3.MATAjouterColonnePrecis(5);
		Matrice3.MATModifierElement(1, 5, 10);
		Matrice3.MATModifierElement(2, 5, 12);

		Matrice3.MATAjouterColonnePrecis(12);
		*/

	// OK - Test d'affichage + MATSupprimerColonnePrecis
		/*
		Matrice3.MATSupprimerColonnePrecis(3);
		*/

	// Test d'affichage + MATSupprimerColonneFin & MATSupprimerLigneFin
		/*
		Matrice3.MATSupprimerLigneFin(2);
		Matrice3.MATSupprimerColonneFin(1);
		*/

	// OK - Test d'affichage + MATAjouterLignePrecis
		/*
		Matrice3.MATAjouterLignePrecis(4);
		Matrice3.MATModifierElement(3, 2, 17);
	
		Matrice3.MATAfficherMatrice();
		*/

	// OK - Test d'affichage + MATSupprimerLignePrecis
		/*
		Matrice3.MATSupprimerLignePrecis(1);
		Matrice3.MATAfficherMatrice();
		*/

	// Test des surcharges
	
		//Matrice4 = Matrice3 * Matrice3;

		/*
		int A = 100;
		Matrice4 = Matrice3 * A;
		*/
		/*
		A = 2;
		Matrice4 = Matrice3 / A;
		*/
		
		/*
		printf("Affichage de la surcharge : \n");
		Matrice4.MATAfficherMatrice();
		*/
	
	// Test de la puissance matrice
		/* REVOIR LA PUISSANCE !!!
		Matrice4 = Matrice3.MATPPuissanceMatrice(2);
		printf("Puissance : \n");
		Matrice4.MATAfficherMatrice();
		*/
	// Affichage Après modification

	printf("APRES : \n");
	Matrice3.MATAfficherMatrice();
}