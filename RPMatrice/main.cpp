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
	CMatrice<int> c = CMatrice<int>();

	c.MATAfficherMatrice();

	// Test de modification et de lecture des élements de la matrice
	CMatrice<int> c = CMatrice<int>(2,2);
	c.MATModifierElement(3,2, 1);
}