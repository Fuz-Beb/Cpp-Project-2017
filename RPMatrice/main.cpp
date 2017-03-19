#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	unsigned int z = 0;

	// Test constructeur par défaut
	//CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	//CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par défaut
	//delete(a);

	// Test méthode MATAfficherMatrice
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

	// Matrice de repection
	CMatrice<int> Matrice3 = CMatrice<int>(2,2);

	Matrice3.MATModifierElement(1,1, 1);
	Matrice3.MATModifierElement(1,2, 2);
	Matrice3.MATModifierElement(2,1, 3);
	Matrice3.MATModifierElement(2,2, 4);

	printf("AVANT");
	Matrice3.MATAfficherMatrice();


	Matrice3.MATAjouterColonnesFin(1);
	Matrice3.MATModifierElement(2, 3, 1);

	
	//Matrice3.MATAjouterColonnePrecis(3);
	//Matrice3.MATAjouterColonnePrecis(3);
	//Matrice3.MATAjouterLignePrecis(3);
	//Matrice3.MATModifierElement(3, 2, 17);
	printf("APRES");

	Matrice3.MATAfficherMatrice();

	
	
	
	
	/*Matrice3 = Matrice1 + Matrice2;*/
	/*Matrice3.MATAfficherMatrice();*/
}