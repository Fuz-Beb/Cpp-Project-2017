#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	unsigned int z = 0;

	// Test constructeur par défaut
	CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par défaut
	delete(a);

	// Test méthode MATAfficherMatrice
	CMatrice<int> c = CMatrice<int>(2, 2);
	c.MATModifierElement(1,1, 1);
	c.MATModifierElement(1,2, 2);
	c.MATModifierElement(2,1, 3);
	c.MATModifierElement(2,2, 4);
	c.MATAfficherMatrice();

	// Test de modification et de lecture des élements de la matrice
	
	// Matrice 1
	CMatrice<int> Matrice1 = CMatrice<int>(2,2);
	Matrice1.MATModifierElement(1,1, 1);
	Matrice1.MATModifierElement(1,2, 2);
	Matrice1.MATModifierElement(2,1, 3);
	Matrice1.MATModifierElement(2,2, 4);

	// Matrice 2
	CMatrice<int> Matrice2 = CMatrice<int>(2,2);
	Matrice1.MATModifierElement(1,1, 1);
	Matrice1.MATModifierElement(1,2, 2);
	Matrice1.MATModifierElement(2,1, 3);
	Matrice1.MATModifierElement(2,2, 4);

	Matrice1 + Matrice2;
}