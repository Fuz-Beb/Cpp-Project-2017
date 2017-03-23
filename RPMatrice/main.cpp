#include "CMatrice.h"
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
		CMatrice<int> Matrice1 = CMatrice<int>(3,3);
		Matrice1.MATModifierElement(1,1, 10);
		Matrice1.MATModifierElement(1,2, 20);
		Matrice1.MATModifierElement(1,3, 30);
		Matrice1.MATModifierElement(2,1, 40);
		Matrice1.MATModifierElement(2,2, 50);
		Matrice1.MATModifierElement(2,3, 60);
		Matrice1.MATModifierElement(3,1, 70);
		Matrice1.MATModifierElement(3,2, 80);
		Matrice1.MATModifierElement(3,3, 90);

	// Matrice 2
		CMatrice<int> Matrice2 = CMatrice<int>(3,3);
		Matrice2.MATModifierElement(1,1, 1);
		Matrice2.MATModifierElement(1,2, 2);
		Matrice2.MATModifierElement(1,3, 3);
		Matrice2.MATModifierElement(2,1, 4);
		Matrice2.MATModifierElement(2,2, 5);
		Matrice2.MATModifierElement(2,3, 6);
		Matrice2.MATModifierElement(3,1, 7);
		Matrice2.MATModifierElement(3,2, 8);
		Matrice2.MATModifierElement(3,3, 9);

	// Matrices
		CMatrice<int> Matrice3 = CMatrice<int>(5,10);
		//CMatrice<int> Matrice4 = CMatrice<int>(2,2);

		//Matrice3.MATModifierElement(1,1, 1);
		//Matrice3.MATModifierElement(3,1, 1);
		//Matrice3.MATModifierElement(3,2, 2);
		//Matrice3.MATModifierElement(1,1, 1);

		//printf("Element : %d", Matrice3.MATLireElement(3,1));
		//printf("Element : %d", Matrice3.MATLireElement(3,2));
		//Matrice3.MATModifierElement(2,1, 1);
		//Matrice3.MATModifierElement(2,2, 1);

	
	// Test d'affichage :
	
		//printf("AVANT : \n");
		//Matrice3.MATAfficherMatrice();

	// OK - Test d'affichage + MATAjouterColonnesFin
		//Matrice3.MATAjouterColonnesFin(1);
		//Matrice3.MATModifierElement(2, 3, 1);
		//Matrice3.MATModifierElement(1, 3, 1);
		//Matrice3.MATAjouterColonnesFin(1);
		//Matrice3.MATModifierElement(2, 4, 9);
		//Matrice3.MATModifierElement(1, 4, 8);

	// OK - Test d'affichage + MATAjouterColonnePrecis
		//Matrice3.MATAjouterColonnePrecis(2);
		//Matrice3.MATModifierElement(1, 2, 7);
		//Matrice3.MATModifierElement(2, 2, 6);
		//Matrice3.MATAjouterColonnePrecis(2);
		//Matrice3.MATModifierElement(1, 2, 9);
		//Matrice3.MATModifierElement(2, 2, 8);
		//Matrice3.MATAjouterColonnePrecis(5);
		//Matrice3.MATModifierElement(1, 5, 10);
		//Matrice3.MATModifierElement(2, 5, 12);
		//Matrice3.MATAjouterColonnePrecis(12);

	// OK - Test d'affichage + MATSupprimerColonnePrecis
		//Matrice3.MATSupprimerColonnePrecis(3);
		// Matrice3.MATAfficherMatrice();

	// Test d'affichage + MATSupprimerColonneFin & MATSupprimerLigneFin
		//Matrice3.MATSupprimerLigneFin(2);
		//Matrice3.MATSupprimerColonneFin(1);
		//Matrice3.MATAfficherMatrice();

	// OK - Test d'affichage + MATAjouterLignePrecis
		//Matrice3.MATAjouterLignePrecis(4);
		//Matrice3.MATModifierElement(3, 2, 17);
		//Matrice3.MATAfficherMatrice();

	// OK - Test d'affichage + MATSupprimerLignePrecis
		/*
		Matrice3.MATSupprimerLignePrecis(1);
		Matrice3.MATAfficherMatrice();
		*/

	// Test des surcharges

		// OK - operator+
		// Matrice3 = Matrice2 + Matrice1;
		// Matrice3.MATAfficherMatrice();

		// OK - operator-
		// Matrice3 = Matrice2 + Matrice1;
		// Matrice3.MATAfficherMatrice();

		// OK - operator* CMatrice
		// Matrice3 = Matrice2 * Matrice1;
		// Matrice3.MATAfficherMatrice();

		// OK - operator* Type OK
		// int a = 5;
		// Matrice3 = Matrice2 * A;
		// Matrice3.MATAfficherMatrice();
		
		// OK - operator* Type, CMatrice
		// int a = 5;
		// Matrice3 = A * Matrice2;
		// Matrice3.MATAfficherMatrice();

		// OK - operator/ CMatrice
		// int a = 5;
		// Matrice3 = Matrice1 / Matrice2;
		// Matrice3.MATAfficherMatrice();

		// OK - operator/ Type
		// int a = 5;
		// Matrice3 = Matrice2 / A;
		// Matrice3.MATAfficherMatrice();
		
		/*printf("Affichage de la surcharge : \n");
		Matrice4.MATAfficherMatrice();
		*/
	
	// Test de la puissance matrice
		/* REVOIR LA PUISSANCE !!!
		Matrice4 = Matrice3.MATPPuissanceMatrice(2);
		printf("Puissance : \n");
		Matrice4.MATAfficherMatrice();
		*/
	// Affichage Après modification

	/*printf("APRES : \n");*/
	//Matrice3.MATAfficherMatrice();
}